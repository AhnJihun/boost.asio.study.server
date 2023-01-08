#pragma once

#include <memory>

#include <boost/asio.hpp>

namespace SyncServer{

class CSyncServer {
public :
    CSyncServer( std::shared_ptr< boost::asio::ip::tcp::socket >& socket );
    virtual ~CSyncServer();

    void StartServer();
    void StopServer();

protected :
    

private :
    std::shared_ptr< boost::asio::ip::tcp::socket > mSocket;
    void ThreadRunnable();

public :
    CSyncServer() = delete;
    CSyncServer( const CSyncServer& ) = delete;
    CSyncServer& operator=( const CSyncServer& ) = delete;

};

}