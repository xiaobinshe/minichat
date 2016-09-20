/* profile_server_config.cpp

 Generated by phxrpc_pb2server from profile.proto

*/

#include "profile.pb.h"
#include "profile_server_config.h"

ProfileServerConfig :: ProfileServerConfig()
{
}

ProfileServerConfig :: ~ProfileServerConfig()
{
}

bool ProfileServerConfig :: Read( const char * config_file )
{
    bool ret = ep_server_config_.Read( config_file );

    if ( strlen( ep_server_config_.GetPackageName() ) == 0 ) {
        ep_server_config_.SetPackageName( 
profile::Setting::default_instance().GetDescriptor()->file()->package().c_str() );
    }

    return ret;
}

const phxrpc::HshaServerConfig & ProfileServerConfig :: GetHshaServerConfig()
{
    return ep_server_config_;
}