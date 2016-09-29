/* presence_client.h

 Generated by phxrpc_pb2client from presence.proto

*/

#pragma once

#include "presence.pb.h"
#include "phxrpc/rpc.h"

class PresenceClient
{
public:
    PresenceClient();
    ~PresenceClient();

    int PHXEcho( const google::protobuf::StringValue & req,
        google::protobuf::StringValue * resp );

    int PhxBatchEcho( const google::protobuf::StringValue & req,
        google::protobuf::StringValue * resp );

    int Create( const google::protobuf::StringValue & req,
        presence::Session * resp );

    int Get( const google::protobuf::StringValue & req,
        presence::Session * resp );

    int Remove( const google::protobuf::StringValue & req,
        presence::Session * resp );

private:
    std::string package_name_;
    phxrpc::ClientConfig * config_;
};
