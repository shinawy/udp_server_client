#include "udpclientsocket.h"

UDPClientSocket:: UDPClientSocket (): UDPSocket(){
    //cout<<"this is the client socket constructor\n";
}

bool UDPClientSocket:: initializeClient (char * _peerAddr, int _peerPort){

    myAddr.sin_family = AF_INET;
    myAddr.sin_port = htons(_peerPort);
    myAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (const struct sockaddr *)&myAddr, sizeof(myAddr)) < 0) {
        //perror("Bind Failed");
        return false;
    } else {
        //perror("Bind Done");
        return true;
    }

    
}

UDPClientSocket:: ~UDPClientSocket (){

}
