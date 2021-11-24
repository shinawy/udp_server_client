#include "udpserversocket.h"

// UDPServerSocket:: UDPServerSocket (){

// }

bool UDPServerSocket:: initializeServer (char * _myAddr, int _myPort){
 // Filling server information
    myAddr.sin_family    = AF_INET; // IPv4
    myAddr.sin_addr.s_addr = INADDR_ANY;
    myAddr.sin_port = htons(_myPort);

    // Bind the socket with the server address
    if ( bind(sock, (const struct sockaddr *)&peerAddr, 
            sizeof(_myAddr)) < 0 )
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }


}

UDPServerSocket:: ~UDPServerSocket ( ){

}
