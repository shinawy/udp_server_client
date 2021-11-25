#include "udpserversocket.h"

UDPServerSocket:: UDPServerSocket (): UDPSocket(){

}

bool UDPServerSocket:: initializeServer (char * _myAddr, int _myPort){
                                                                      
    myAddr.sin_family    = AF_INET;
    myAddr.sin_addr.s_addr = INADDR_ANY;
    myAddr.sin_port = htons(_myPort);

    if (bind(sock, (const struct sockaddr *)&myAddr, sizeof(myAddr)) < 0) {
        perror("Bind Failed");
        return false;
    } else {
        perror("Bind Done");
        return true;
    }
}

UDPServerSocket:: ~UDPServerSocket (){

}
