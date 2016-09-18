/* account_client.cpp

 Generated by phxrpc_pb2client from account.proto

*/

#include <iostream>
#include <memory>
#include <stdlib.h>
#include <mutex>

#include "account_client.h"
#include "phxrpc_account_stub.h"

#include "phxrpc/rpc.h"

static phxrpc::ClientConfig global_accountclient_config_;
static phxrpc::ClientMonitorPtr global_accountclient_monitor_;

bool AccountClient :: Init( const char * config_file )
{
    return global_accountclient_config_.Read( config_file );
}

const char * AccountClient :: GetPackageName() {
    const char * ret = global_accountclient_config_.GetPackageName();
    if (strlen(ret) == 0) {
        ret = "account";
    }
    return ret;
}

AccountClient :: AccountClient()
{
    static std::mutex monitor_mutex;
    if ( !global_accountclient_monitor_.get() ) { 
        monitor_mutex.lock();
        if ( !global_accountclient_monitor_.get() ) {
            global_accountclient_monitor_ = phxrpc::MonitorFactory::GetFactory()
                ->CreateClientMonitor( GetPackageName() );
        }
        global_accountclient_config_.SetClientMonitor( global_accountclient_monitor_ );
        monitor_mutex.unlock();
    }
}

AccountClient :: ~AccountClient()
{
}

int AccountClient :: PHXEcho( const google::protobuf::StringValue & req,
        google::protobuf::StringValue * resp )
{
    const phxrpc::Endpoint_t * ep = global_accountclient_config_.GetRandom();

    if(ep != nullptr) {
        phxrpc::BlockTcpStream socket;
        bool open_ret = phxrpc::PhxrpcTcpUtils::Open(&socket, ep->ip, ep->port,
                    global_accountclient_config_.GetConnectTimeoutMS(), NULL, 0, 
                    *(global_accountclient_monitor_.get()));
        if ( open_ret ) {
            socket.SetTimeout(global_accountclient_config_.GetSocketTimeoutMS());

            AccountStub stub(socket, *(global_accountclient_monitor_.get()));
            return stub.PHXEcho(req, resp);
        } 
    }

    return -1;
}

int AccountClient :: PhxBatchEcho( const google::protobuf::StringValue & req,
        google::protobuf::StringValue * resp )
{
    int ret = -1; 
    size_t echo_server_count = 2;
    uthread_begin;
    for (size_t i = 0; i < echo_server_count; i++) {
        uthread_t [=, &uthread_s, &ret](void *) {
            const phxrpc::Endpoint_t * ep = global_accountclient_config_.GetByIndex(i);
            if (ep != nullptr) {
                phxrpc::UThreadTcpStream socket;
                if(phxrpc::PhxrpcTcpUtils::Open(&uthread_s, &socket, ep->ip, ep->port,
                            global_accountclient_config_.GetConnectTimeoutMS(), *(global_accountclient_monitor_.get()))) { 
                    socket.SetTimeout(global_accountclient_config_.GetSocketTimeoutMS());
                    AccountStub stub(socket, *(global_accountclient_monitor_.get()));
                    int this_ret = stub.PHXEcho(req, resp);
                    if (this_ret == 0) {
                        ret = this_ret;
                        uthread_s.Close();
                    }   
                }   
            }
        };  
    }   
    uthread_end;
    return ret;
}

int AccountClient :: Add( const account::User & req,
        google::protobuf::Empty * resp )
{
    const phxrpc::Endpoint_t * ep = global_accountclient_config_.GetRandom();

    if(ep != nullptr) {
        phxrpc::BlockTcpStream socket;
        bool open_ret = phxrpc::PhxrpcTcpUtils::Open(&socket, ep->ip, ep->port,
                    global_accountclient_config_.GetConnectTimeoutMS(), NULL, 0, 
                    *(global_accountclient_monitor_.get()));
        if ( open_ret ) {
            socket.SetTimeout(global_accountclient_config_.GetSocketTimeoutMS());

            AccountStub stub(socket, *(global_accountclient_monitor_.get()));
            return stub.Add(req, resp);
        } 
    }

    return -1;
}

int AccountClient :: Get( const google::protobuf::StringValue & req,
        account::User * resp )
{
    const phxrpc::Endpoint_t * ep = global_accountclient_config_.GetRandom();

    if(ep != nullptr) {
        phxrpc::BlockTcpStream socket;
        bool open_ret = phxrpc::PhxrpcTcpUtils::Open(&socket, ep->ip, ep->port,
                    global_accountclient_config_.GetConnectTimeoutMS(), NULL, 0, 
                    *(global_accountclient_monitor_.get()));
        if ( open_ret ) {
            socket.SetTimeout(global_accountclient_config_.GetSocketTimeoutMS());

            AccountStub stub(socket, *(global_accountclient_monitor_.get()));
            return stub.Get(req, resp);
        } 
    }

    return -1;
}

int AccountClient :: Auth( const account::AuthReq & req,
        google::protobuf::Empty * resp )
{
    const phxrpc::Endpoint_t * ep = global_accountclient_config_.GetRandom();

    if(ep != nullptr) {
        phxrpc::BlockTcpStream socket;
        bool open_ret = phxrpc::PhxrpcTcpUtils::Open(&socket, ep->ip, ep->port,
                    global_accountclient_config_.GetConnectTimeoutMS(), NULL, 0, 
                    *(global_accountclient_monitor_.get()));
        if ( open_ret ) {
            socket.SetTimeout(global_accountclient_config_.GetSocketTimeoutMS());

            AccountStub stub(socket, *(global_accountclient_monitor_.get()));
            return stub.Auth(req, resp);
        } 
    }

    return -1;
}


