/* msgbox_service_impl.cpp

 Generated by phxrpc_pb2service from msgbox.proto

*/

#include "msgbox_service_impl.h"
#include "msgbox_server_config.h"
#include "msgbox.pb.h"
#include "phxrpc/file.h"

#include "msgbox_dao.h"

#include "common/redis_client_factory.h"

MsgBoxServiceImpl :: MsgBoxServiceImpl( ServiceArgs_t & args )
    : args_( args )
{
}

MsgBoxServiceImpl :: ~MsgBoxServiceImpl()
{
}

int MsgBoxServiceImpl :: PHXEcho( const google::protobuf::StringValue & req,
        google::protobuf::StringValue * resp )
{
    resp->set_value( req.value() );
    return 0;
}

int MsgBoxServiceImpl :: Add( const msgbox::MsgIndex & req,
        msgbox::AddMsgResp * resp )
{
    MsgBoxDAO dao( args_.factory->Get() );

    return dao.Add( req, resp );
}

int MsgBoxServiceImpl :: GetBySeq( const msgbox::GetBySeqReq & req,
        msgbox::MsgIndexList * resp )
{
    MsgBoxDAO dao( args_.factory->Get() );

    return dao.GetBySeq( req, resp );
}

int MsgBoxServiceImpl :: GetAll( const google::protobuf::StringValue & req,
        msgbox::MsgIndexList * resp )
{
    MsgBoxDAO dao( args_.factory->Get() );

    return dao.GetAll( req, resp );
}

