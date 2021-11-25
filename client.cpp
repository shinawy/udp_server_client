#include "client.h"
#define MAXLINE 1024

Client:: Client(char * _hostname, int _port){
udpClientSocket= new UDPClientSocket();
udpClientSocket ->initializeClient(_hostname, _port);
}

void Client::send_request(Message* class_message){
int n;
socklen_t len; 
       char* buffer [MAXLINE];
       char* marshaled_message= class_message->marshal();
       class_message->setMessage(marshaled_message,strlen(marshaled_message));
    

    char *message = new char[sizeof(*class_message)];
     message = (char *)class_message;

    sendto(udpClientSocket -> sock, (const Message*)message, sizeof(*class_message),
        MSG_CONFIRM, (const struct sockaddr *) &udpClientSocket->myAddr, 
            sizeof(udpClientSocket->myAddr));
    // printf("Hello message sent.\n");
           
    n = recvfrom(udpClientSocket -> sock, (char *)buffer, MAXLINE, 
                MSG_WAITALL, (struct sockaddr *) &udpClientSocket->myAddr,
               &len);
    buffer[n] = "\0";
    printf("Server : %s\n", buffer);
}

Message * Client:: execute(Message * _message){

}

Client:: ~Client(){
delete udpClientSocket;
}
