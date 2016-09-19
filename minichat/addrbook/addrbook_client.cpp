/* addrbook_client.cpp

 Generated by phxrpc_pb2client from addrbook.proto

*/

#include <iostream>
#include <memory>
#include <stdlib.h>
#include <mutex>

#include "addrbook_client.h"
#include "phxrpc_addrbook_stub.h"

#include "phxrpc/rpc.h"

static phxrpc::ClientConfig global_addrbookclient_config_;
static phxrpc::ClientMonitorPtr global_addrbookclient_monitor_;

bool AddrbookClient :: Init( const char * config_file )
{
    return global_addrbookclient_config_.Read( config_file );
}

const char * AddrbookClient :: GetPackageName() {
    const char * ret = global_addrbookclient_config_.GetPackageName();
    if (strlen(ret) == 0) {
        ret = "addrbook";
    }
    return ret;
}

AddrbookClient :: AddrbookClient()
{
    static std::mutex monitor_mutex;
    if ( !global_addrbookclient_monitor_.get() ) { 
        monitor_mutex.lock();
        if ( !global_addrbookclient_monitor_.get() ) {
            global_addrbookclient_monitor_ = phxrpc::MonitorFactory::GetFactory()
                ->CreateClientMonitor( GetPackageName() );
        }
        global_addrbookclient_config_.SetClientMonitor( global_addrbookclient_monitor_ );
        monitor_mutex.unlock();
    }
}

AddrbookClient :: ~AddrbookClient()
{
}

int AddrbookClient :: PHXEcho( const google::protobuf::StringValue & req,
        google::protobuf::StringValue * resp )
{
    const phxrpc::Endpoint_t * ep = global_addrbookclient_config_.GetRandom();

    if(ep != nullptr) {
        phxrpc::BlockTcpStream socket;
        bool open_ret = phxrpc::PhxrpcTcpUtils::Open(&socket, ep->ip, ep->port,
                    global_addrbookclient_config_.GetConnectTimeoutMS(), NULL, 0, 
                    *(global_addrbookclient_monitor_.get()));
        if ( open_ret ) {
            socket.SetTimeout(global_addrbookclient_config_.GetSocketTimeoutMS());

            AddrbookStub stub(socket, *(global_addrbookclient_monitor_.get()));
            return stub.PHXEcho(req, resp);
        } 
    }

    return -1;
}

int AddrbookClient :: PhxBatchEcho( const google::protobuf::StringValue & req,
        google::protobuf::StringValue * resp )
{
    int ret = -1; 
    size_t echo_server_count = 2;
    uthread_begin;
    for (size_t i = 0; i < echo_server_count; i++) {
        uthread_t [=, &uthread_s, &ret](void *) {
            const phxrpc::Endpoint_t * ep = global_addrbookclient_config_.GetByIndex(i);
            if (ep != nullptr) {
                phxrpc::UThreadTcpStream socket;
                if(phxrpc::PhxrpcTcpUtils::Open(&uthread_s, &socket, ep->ip, ep->port,
                            global_addrbookclient_config_.GetConnectTimeoutMS(), *(global_addrbookclient_monitor_.get()))) { 
                    socket.SetTimeout(global_addrbookclient_config_.GetSocketTimeoutMS());
                    AddrbookStub stub(socket, *(global_addrbookclient_monitor_.get()));
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

int AddrbookClient :: Add( const addrbook::ContactReq & req,
        google::protobuf::Empty * resp )
{
    const phxrpc::Endpoint_t * ep = global_addrbookclient_config_.GetRandom();

    if(ep != nullptr) {
        phxrpc::BlockTcpStream socket;
        bool open_ret = phxrpc::PhxrpcTcpUtils::Open(&socket, ep->ip, ep->port,
                    global_addrbookclient_config_.GetConnectTimeoutMS(), NULL, 0, 
                    *(global_addrbookclient_monitor_.get()));
        if ( open_ret ) {
            socket.SetTimeout(global_addrbookclient_config_.GetSocketTimeoutMS());

            AddrbookStub stub(socket, *(global_addrbookclient_monitor_.get()));
            return stub.Add(req, resp);
        } 
    }

    return -1;
}

int AddrbookClient :: GetAll( const google::protobuf::StringValue & req,
        addrbook::ContactList * resp )
{
    const phxrpc::Endpoint_t * ep = global_addrbookclient_config_.GetRandom();

    if(ep != nullptr) {
        phxrpc::BlockTcpStream socket;
        bool open_ret = phxrpc::PhxrpcTcpUtils::Open(&socket, ep->ip, ep->port,
                    global_addrbookclient_config_.GetConnectTimeoutMS(), NULL, 0, 
                    *(global_addrbookclient_monitor_.get()));
        if ( open_ret ) {
            socket.SetTimeout(global_addrbookclient_config_.GetSocketTimeoutMS());

            AddrbookStub stub(socket, *(global_addrbookclient_monitor_.get()));
            return stub.GetAll(req, resp);
        } 
    }

    return -1;
}

int AddrbookClient :: GetOne( const addrbook::GetOneReq & req,
        addrbook::Contact * resp )
{
    const phxrpc::Endpoint_t * ep = global_addrbookclient_config_.GetRandom();

    if(ep != nullptr) {
        phxrpc::BlockTcpStream socket;
        bool open_ret = phxrpc::PhxrpcTcpUtils::Open(&socket, ep->ip, ep->port,
                    global_addrbookclient_config_.GetConnectTimeoutMS(), NULL, 0, 
                    *(global_addrbookclient_monitor_.get()));
        if ( open_ret ) {
            socket.SetTimeout(global_addrbookclient_config_.GetSocketTimeoutMS());

            AddrbookStub stub(socket, *(global_addrbookclient_monitor_.get()));
            return stub.GetOne(req, resp);
        } 
    }

    return -1;
}

