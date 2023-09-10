// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: opencv.proto
// Original file comments:
// Copyright 2015 gRPC authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#ifndef GRPC_opencv_2eproto__INCLUDED
#define GRPC_opencv_2eproto__INCLUDED

#include "opencv.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace helloopencv {

// The greeting service definition.
class Greeter final {
 public:
  static constexpr char const* service_full_name() {
    return "helloopencv.Greeter";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // Sends a greeting
    virtual ::grpc::Status SayOpencv(::grpc::ClientContext* context, const ::helloopencv::OpencvRequest& request, ::helloopencv::OpencvReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::helloopencv::OpencvReply>> AsyncSayOpencv(::grpc::ClientContext* context, const ::helloopencv::OpencvRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::helloopencv::OpencvReply>>(AsyncSayOpencvRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::helloopencv::OpencvReply>> PrepareAsyncSayOpencv(::grpc::ClientContext* context, const ::helloopencv::OpencvRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::helloopencv::OpencvReply>>(PrepareAsyncSayOpencvRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      // Sends a greeting
      virtual void SayOpencv(::grpc::ClientContext* context, const ::helloopencv::OpencvRequest* request, ::helloopencv::OpencvReply* response, std::function<void(::grpc::Status)>) = 0;
      virtual void SayOpencv(::grpc::ClientContext* context, const ::helloopencv::OpencvRequest* request, ::helloopencv::OpencvReply* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::helloopencv::OpencvReply>* AsyncSayOpencvRaw(::grpc::ClientContext* context, const ::helloopencv::OpencvRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::helloopencv::OpencvReply>* PrepareAsyncSayOpencvRaw(::grpc::ClientContext* context, const ::helloopencv::OpencvRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status SayOpencv(::grpc::ClientContext* context, const ::helloopencv::OpencvRequest& request, ::helloopencv::OpencvReply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::helloopencv::OpencvReply>> AsyncSayOpencv(::grpc::ClientContext* context, const ::helloopencv::OpencvRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::helloopencv::OpencvReply>>(AsyncSayOpencvRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::helloopencv::OpencvReply>> PrepareAsyncSayOpencv(::grpc::ClientContext* context, const ::helloopencv::OpencvRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::helloopencv::OpencvReply>>(PrepareAsyncSayOpencvRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void SayOpencv(::grpc::ClientContext* context, const ::helloopencv::OpencvRequest* request, ::helloopencv::OpencvReply* response, std::function<void(::grpc::Status)>) override;
      void SayOpencv(::grpc::ClientContext* context, const ::helloopencv::OpencvRequest* request, ::helloopencv::OpencvReply* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::helloopencv::OpencvReply>* AsyncSayOpencvRaw(::grpc::ClientContext* context, const ::helloopencv::OpencvRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::helloopencv::OpencvReply>* PrepareAsyncSayOpencvRaw(::grpc::ClientContext* context, const ::helloopencv::OpencvRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_SayOpencv_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // Sends a greeting
    virtual ::grpc::Status SayOpencv(::grpc::ServerContext* context, const ::helloopencv::OpencvRequest* request, ::helloopencv::OpencvReply* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_SayOpencv : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_SayOpencv() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_SayOpencv() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayOpencv(::grpc::ServerContext* /*context*/, const ::helloopencv::OpencvRequest* /*request*/, ::helloopencv::OpencvReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSayOpencv(::grpc::ServerContext* context, ::helloopencv::OpencvRequest* request, ::grpc::ServerAsyncResponseWriter< ::helloopencv::OpencvReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_SayOpencv<Service > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_SayOpencv : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_SayOpencv() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::helloopencv::OpencvRequest, ::helloopencv::OpencvReply>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::helloopencv::OpencvRequest* request, ::helloopencv::OpencvReply* response) { return this->SayOpencv(context, request, response); }));}
    void SetMessageAllocatorFor_SayOpencv(
        ::grpc::MessageAllocator< ::helloopencv::OpencvRequest, ::helloopencv::OpencvReply>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::helloopencv::OpencvRequest, ::helloopencv::OpencvReply>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_SayOpencv() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayOpencv(::grpc::ServerContext* /*context*/, const ::helloopencv::OpencvRequest* /*request*/, ::helloopencv::OpencvReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* SayOpencv(
      ::grpc::CallbackServerContext* /*context*/, const ::helloopencv::OpencvRequest* /*request*/, ::helloopencv::OpencvReply* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_SayOpencv<Service > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_SayOpencv : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_SayOpencv() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_SayOpencv() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayOpencv(::grpc::ServerContext* /*context*/, const ::helloopencv::OpencvRequest* /*request*/, ::helloopencv::OpencvReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_SayOpencv : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_SayOpencv() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_SayOpencv() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayOpencv(::grpc::ServerContext* /*context*/, const ::helloopencv::OpencvRequest* /*request*/, ::helloopencv::OpencvReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSayOpencv(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_SayOpencv : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_SayOpencv() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->SayOpencv(context, request, response); }));
    }
    ~WithRawCallbackMethod_SayOpencv() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayOpencv(::grpc::ServerContext* /*context*/, const ::helloopencv::OpencvRequest* /*request*/, ::helloopencv::OpencvReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* SayOpencv(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_SayOpencv : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_SayOpencv() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::helloopencv::OpencvRequest, ::helloopencv::OpencvReply>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::helloopencv::OpencvRequest, ::helloopencv::OpencvReply>* streamer) {
                       return this->StreamedSayOpencv(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_SayOpencv() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status SayOpencv(::grpc::ServerContext* /*context*/, const ::helloopencv::OpencvRequest* /*request*/, ::helloopencv::OpencvReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSayOpencv(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::helloopencv::OpencvRequest,::helloopencv::OpencvReply>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_SayOpencv<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_SayOpencv<Service > StreamedService;
};

}  // namespace helloopencv


#endif  // GRPC_opencv_2eproto__INCLUDED
