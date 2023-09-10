@echo off
set PROTOC=H:\Projects\CppProjects\pRPC_Project\grpc\bin\protoc.exe
set grpc=H:\Projects\CppProjects\pRPC_Project\grpc\bin\grpc_cpp_plugin.exe
set OUTPUT=./

echo ------------------------------
echo opencv.proto
set FILE=opencv.proto
%PROTOC% %FILE% --cpp_out=%OUTPUT%
%PROTOC% %FILE% --plugin=protoc-gen-grpc="%grpc%" --grpc_out=%OUTPUT% 

pause