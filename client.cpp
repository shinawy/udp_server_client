#include "client.h"
#define MAXLINE 65535

Client:: Client(char * _hostname, int _port){
    udpClientSocket= new UDPClientSocket();
    udpClientSocket -> initializeClient(_hostname, _port);
}

void Client::send_request(Message class_message, string username){
    int n;
    socklen_t len = sizeof(udpClientSocket-> peerAddr); 
 
    //class_message.Flatten();
    //string client_request_message = class_message.getFlattenedMessage();

    string client_request_message = class_message.getMessage();
    int message_size = client_request_message.length();
    
    //cout<<"Flattened Message: "<< client_request_message<<endl;
    

    sendto(udpClientSocket -> sock, (char*)client_request_message.c_str(), message_size,
        MSG_CONFIRM, (const struct sockaddr *) &udpClientSocket->myAddr, len); 
    

    /*char* server_reply_message [MAXLINE];

    n = recvfrom(udpClientSocket -> sock, (char*) server_reply_message, MAXLINE, 
                MSG_WAITALL, (struct sockaddr *) &udpClientSocket->myAddr,
               &len);

    cout << "Server : " << server_reply_message << endl;


    send_message(username);*/


 
}

Message * Client:: execute(Message * _message){

}

void Client::send_message(string message) {
    socklen_t len = sizeof(udpClientSocket-> peerAddr); 

    sendto(udpClientSocket -> sock, (char*)message.c_str(), message.length(),
        MSG_CONFIRM, (const struct sockaddr *) &udpClientSocket->myAddr, len);
}

Client:: ~Client(){
    delete udpClientSocket;
}
