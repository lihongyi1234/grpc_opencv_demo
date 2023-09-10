#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "opencv.grpc.pb.h"
#include "opencv2/opencv.hpp"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using helloopencv::Greeter;
using helloopencv::OpencvReply;
using helloopencv::OpencvRequest;

#pragma comment(lib, "opencv_img_hash3416.lib")
#pragma comment(lib, "opencv_world3416.lib")

void cvtMatToProto(const cv::Mat& image, helloopencv::ImageProto* image_proto)
{
	image_proto->set_width(image.cols);
	image_proto->set_height(image.rows);
	int channels = image.channels();
	image_proto->set_channels(channels);

	image_proto->clear_data_bytes();
	int depth = image.depth();
	image_proto->set_depth(helloopencv::ImageProto_Depth_UCHAR_8);
	image_proto->mutable_data_bytes()->Add()->assign(reinterpret_cast<const char*>(image.data), image.rows * image.cols * channels * sizeof(uchar));
}

void cvtProtoToMat(const helloopencv::ImageProto& mat_proto, cv::Mat& image)
{
	int width = mat_proto.width();
	int height = mat_proto.height();
	int channels = mat_proto.channels();
	std::string bytes = mat_proto.data_bytes().Get(0);
	image.create(height, width, CV_8UC3);
	int len = std::min(height * width * channels * int(sizeof(uchar)), (int)bytes.size());
	memcpy(image.data, bytes.data(), len);
}

class GreeterClient {
public:
	GreeterClient(std::shared_ptr<Channel> channel)
		: stub_(Greeter::NewStub(channel)) {}

	// Assembles the client's payload, sends it and presents the response back
	// from the server.
	std::string SayHello(const std::string& user, const std::string output, const std::vector<cv::Mat>&images) {
		// Data we are sending to the server.
		OpencvRequest request;
		request.set_name(user);

		for (int i = 0; i < images.size(); i++) {
			cvtMatToProto(images[i], request.add_images());
		}

		// Container for the data we expect from the server.
		OpencvReply reply;

		// Context for the client. It could be used to convey extra information to
		// the server and/or tweak certain RPC behaviors.
		ClientContext context;

		// The actual RPC.
		Status status = stub_->SayOpencv(&context, request, &reply);

		// Act upon its status.
		if (status.ok()) {

			helloopencv::ImageProto mat_proto = reply.images();
			cv::Mat image;
			cvtProtoToMat(mat_proto, image);
			cv::imwrite(output, image);
			return reply.message();
		}
		else {
			std::cout << status.error_code() << ": " << status.error_message()
				<< std::endl;
			return "RPC failed";
		}
	}

private:
	std::unique_ptr<Greeter::Stub> stub_;
};

int main(int argc, char** argv) {
	// Instantiate the client. It requires a channel, out of which the actual RPCs
	// are created. This channel models a connection to an endpoint specified by
	// the argument "--target=" which is the only expected argument.
	// We indicate that the channel isn't authenticated (use of
	// InsecureChannelCredentials()).
	std::string target_str;	
	target_str = "localhost:50051";

	std::string img0 = argc > 1 ? argv[1] : "../data/hello.jpg";
	std::string img1 = argc > 2 ? argv[2] : "../data/opencv.jpg";
	std::string output = argc > 1 ? argv[3] : "../data/hello_opencv.jpg";
	int width = 2048, height = 2048;

	cv::Mat image0 = cv::imread(img0);
	cv::resize(image0, image0, cv::Size(width, height));
	cv::Mat image1 = cv::imread(img1);
	cv::resize(image1, image1, cv::Size(width, height));
	std::vector<cv::Mat> imgaes{ image0 ,image1 };

	grpc::ChannelArguments channel_args;
	channel_args.SetMaxReceiveMessageSize(google::protobuf::kint32max);
	channel_args.SetMaxSendMessageSize(google::protobuf::kint32max);
	std::shared_ptr<grpc::Channel> channel = grpc::CreateCustomChannel(target_str, grpc::InsecureChannelCredentials(), channel_args);
	GreeterClient greeter(channel);

	std::string user("opencv");
	std::string reply = greeter.SayHello(user, output, imgaes);
	std::cout << "Greeter received: " << reply << std::endl;

	return 0;
}

