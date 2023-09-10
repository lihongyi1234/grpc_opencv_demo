#include <iostream>
#include <memory>
#include <string>
#include "opencv2/opencv.hpp"

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include "opencv.grpc.pb.h"

#pragma comment(lib, "opencv_img_hash3416.lib")
#pragma comment(lib, "opencv_world3416.lib")

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using helloopencv::Greeter;
using helloopencv::OpencvReply;
using helloopencv::OpencvRequest;

void cvtProtoToMat(const helloopencv::ImageProto& mat_proto, cv::Mat& image)
{
    int width = mat_proto.width();
    int height = mat_proto.height();
    int channels = mat_proto.channels();
    std::string bytes = mat_proto.data_bytes().Get(0);
    printf("width:%d, height:%d\n", width, height);
    printf("channels:%d\n", channels);
    image.create(height, width, CV_8UC3);
    int len = std::min(height * width * channels * int(sizeof(uchar)), (int)bytes.size());
    memcpy(image.data, bytes.data(), len);
    printf("len:%d\n", len);
}

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

// Logic and data behind the server's behavior.
class GreeterServiceImpl final : public Greeter::Service {
    Status SayOpencv(ServerContext* context, const OpencvRequest* request,
        OpencvReply* reply) override {
        std::string prefix("Hello ");
        std::vector<cv::Mat> images;
        int lens = request->images().size();
        std::cout << "lens: " << lens << std::endl;
        images.resize(lens);
        for (int i = 0; i < lens; i++)
        {
            cvtProtoToMat(request->images(i), images[i]);
        }
        std::cout << "---000---" << std::endl;
        cv::Mat output;
        cv::hconcat(images[0], images[1], output);

        cvtMatToProto(output, reply->mutable_images());
        printf("output image (w,h) = (%d,%d)\n", output.cols, output.rows);
        reply->set_message(prefix + request->name());
        return Status::OK;
    }
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    GreeterServiceImpl service;

    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    ServerBuilder builder;
    builder.SetMaxReceiveMessageSize(google::protobuf::kint32max);
    builder.SetMaxSendMessageSize(google::protobuf::kint32max);
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&service);
    // Finally assemble the server.
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();

    return 0;
}
