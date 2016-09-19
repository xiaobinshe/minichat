/* addrbook_server_config.h

 Generated by phxrpc_pb2server from addrbook.proto

*/

#pragma once

#include "phxrpc/rpc.h"

class AddrbookServerConfig
{
public:
    AddrbookServerConfig();

    ~AddrbookServerConfig();

    bool Read( const char * config_file );

    const phxrpc::HshaServerConfig & GetHshaServerConfig();

private:
    phxrpc::HshaServerConfig ep_server_config_;
};