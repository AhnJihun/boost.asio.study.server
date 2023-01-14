#pragma once

#include <string>
#include <memory>
#include <thread>

#include <boost/asio.hpp>

namespace SyncServer {
class CSyncAcceptor {
public :
    CSyncAcceptor( const std::string& serverIp , unsigned short portNum );
    virtual ~CSyncAcceptor();    

    bool StartAcceptor();
    bool StopAcceptor();
    
    
    
protected :

private :
    void AcceptRunnable();

private :
    std::string mServerIp;
    unsigned short mPortNum;
    bool mIsRun;
    std::shared_ptr<std::thread> mAcceptThread;
    std::shared_ptr< boost::asio::ip::tcp::acceptor > mAcceptor;
    

public :
    CSyncAcceptor() = delete;
    CSyncAcceptor( const CSyncAcceptor& ) = delete;
    CSyncAcceptor& operator= ( const CSyncAcceptor& ) = delete;
};
}