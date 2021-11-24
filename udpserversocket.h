#include "udpsocket.h"

#ifndef UDPSERVERSOCKET_H
#define UDPSERVERSOCKET_H



class UDPServerSocket : public UDPSocket {
public:
    UDPServerSocket (): UDPSocket(){};
    bool initializeServer (char * _myAddr, int _myPort);
    ~UDPServerSocket ( );
};
#endif // UDPSERVERSOCKET_H 