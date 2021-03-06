/* account_service_impl.h

 Generated by phxrpc_pb2service from account.proto

*/

#pragma once

#include "account.pb.h"
#include "phxrpc_account_service.h"

class AccountServerConfig;

class RedisClientFactory;

typedef struct tagServiceArgs {
    AccountServerConfig * config;
    //You can add other arguments here and initiate in main().
    RedisClientFactory * factory;
}ServiceArgs_t;

class AccountServiceImpl : public AccountService
{
public:
    AccountServiceImpl( ServiceArgs_t & args );
    virtual ~AccountServiceImpl();

    virtual int PHXEcho( const google::protobuf::StringValue & req,
        google::protobuf::StringValue * resp );

    virtual int Set( const account::User & req,
        google::protobuf::Empty * resp );

    virtual int SetPwd( const account::PwdReq & req,
        google::protobuf::Empty * resp );

    virtual int Get( const google::protobuf::StringValue & req,
        account::User * resp );

    virtual int Auth( const account::PwdReq & req,
        google::protobuf::Empty * resp );

private:
    ServiceArgs_t & args_;
};

