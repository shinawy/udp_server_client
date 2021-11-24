#include "udpsocket.h"

UDPSocket:: UDPSocket (){
    
}
void UDPSocket:: setFilterAddress (char * _filterAddress){


}

char * UDPSocket:: getFilterAddress (){


}

bool UDPSocket:: initializeServer (char * _myAddr, int _myPort){


}

bool UDPSocket:: initializeClient (char * _peerAddr, int _peerPort){


}

int UDPSocket:: writeToSocket (char * buffer, int maxBytes ){


}

int UDPSocket:: writeToSocketAndWait (char * buffer, int maxBytes,int microSec ){


}

int UDPSocket:: readFromSocketWithNoBlock (char * buffer, int maxBytes ){


}

int UDPSocket:: readFromSocketWithTimeout (char * buffer, int maxBytes, int timeoutSec, int timeoutMilli){


}

int UDPSocket:: readFromSocketWithBlock (char * buffer, int maxBytes ){


}

int UDPSocket:: readSocketWithNoBlock (char * buffer, int maxBytes ){


}

int UDPSocket:: readSocketWithTimeout (char * buffer, int maxBytes, int timeoutSec, int timeoutMilli){


}

int UDPSocket:: readSocketWithBlock (char * buffer, int maxBytes ){


}

int UDPSocket:: getMyPort (){


}

int UDPSocket:: getPeerPort (){


}

void UDPSocket:: enable(){


}

void UDPSocket:: disable(){


}

bool UDPSocket:: isEnabled(){


}

void UDPSocket:: lock(){


}

void UDPSocket:: unlock(){


}

int UDPSocket:: getSocketHandler(){


}

UDPSocket:: ~UDPSocket ( ){


}
