/* msgbox_tool_impl.cpp

 Generated by phxrpc_pb2tool from msgbox.proto

*/

#include "msgbox_tool_impl.h"
#include "msgbox_client.h"

#include "phxrpc/file.h"

using namespace phxrpc;

MsgBoxToolImpl:: MsgBoxToolImpl()
{
}

MsgBoxToolImpl:: ~MsgBoxToolImpl()
{
}

int MsgBoxToolImpl :: PHXEcho( phxrpc::OptMap & opt_map )
{
    google::protobuf::StringValue req;
    google::protobuf::StringValue resp;

    if( NULL == opt_map.Get( 's' ) ) return -1;

    req.set_value( opt_map.Get( 's' ) );

    MsgBoxClient client;
    int ret = client.PHXEcho( req, &resp );
    printf( "%s return %d\n", __func__, ret );
    printf( "resp: {\n%s}\n", resp.DebugString().c_str() );

    return ret;
}

int MsgBoxToolImpl :: Add( phxrpc::OptMap & opt_map )
{
    msgbox::MsgIndex req;
    msgbox::AddMsgResp resp;

    //TODO: fill req from opt_map

    if( NULL == opt_map.Get( 's' ) || NULL == opt_map.Get( 't' )
            || NULL == opt_map.Get( 'm' ) ) {
        return -1;
    }

    req.set_from( opt_map.Get( 's' ) );
    req.set_to( opt_map.Get( 't' ) );
    req.set_content( opt_map.Get( 'm' ) );

    MsgBoxClient client;
    int ret = client.Add( req, &resp );
    printf( "%s return %d\n", __func__, ret );
    printf( "resp: {\n%s}\n", resp.DebugString().c_str() );

    return ret;
}

int MsgBoxToolImpl :: GetBySeq( phxrpc::OptMap & opt_map )
{
    msgbox::GetBySeqReq req;
    msgbox::MsgIndexList resp;

    //TODO: fill req from opt_map

    if( NULL == opt_map.Get( 'u' ) || NULL == opt_map.Get( 's' ) ) return -1;

    req.set_username( opt_map.Get( 'u' ) );
    req.set_seq( atoi( opt_map.Get( 's' ) ) );

    MsgBoxClient client;
    int ret = client.GetBySeq( req, &resp );
    printf( "%s return %d\n", __func__, ret );
    printf( "resp: {\n%s}\n", resp.DebugString().c_str() );

    return ret;
}

int MsgBoxToolImpl :: GetAll( phxrpc::OptMap & opt_map )
{
    google::protobuf::StringValue req;
    msgbox::MsgIndexList resp;

    //TODO: fill req from opt_map

    if( NULL == opt_map.Get( 'u' ) ) return -1;

    req.set_value( opt_map.Get( 'u' ) );

    MsgBoxClient client;
    int ret = client.GetAll( req, &resp );
    printf( "%s return %d\n", __func__, ret );
    printf( "resp: {\n%s}\n", resp.DebugString().c_str() );

    return ret;
}

