#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

#include "Server/SyncServer/CSyncServer.h"
#include "Server/SyncServer/CSyncAcceptor.h"

int main ( int argc , char** argv ) {

    for ( int i = 1 ; i  < argc ; i++ ) {
        std::cout << argv[i] << std::endl;
    }
    
    SyncServer::CSyncAcceptor syncAcceptor( argv[1] , boost::lexical_cast<unsigned short>(argv[2]) );

    return 0;
}