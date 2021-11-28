#include "client.h"
#define MAXLINE 1024

Client:: Client(char * _hostname, int _port){
udpClientSocket= new UDPClientSocket();
udpClientSocket ->initializeClient(_hostname, _port);
}

void Client::send_request(Message class_message){
int n;
socklen_t len; 
       char* marshaled_message= class_message.marshal();
       class_message.setMessage(marshaled_message,strlen(marshaled_message));
    class_message. print_message_info();
    // cout<<"Marshaled Message From the object: "<<class_message->getMessage()<<endl;
    char *message = new char[sizeof(class_message)];
     message = (char*) &class_message;

 stringstream histream;
{
        boost::archive::text_oarchive oa(histream);
        oa << class_message;
    } // <-- destructor of text_oarchive


    // string hi= "helllo from the other side\n";
   
    // histream<<hi;
    histream.seekg(0, ios::end);
    int size = histream.tellg();

    cout<<"the sstream contains in the client: "<< histream.str()<<endl;
    cout<<"the stream size is:  "<<size<<endl;
    Message* newclass_message= (Message* ) message;
    // cout<<"Marshaled Message From the new object casted: "<<newclass_message->getMessage()<<endl;
    newclass_message -> print_message_info();
    ofstream outobj("client_obj.txt");
    outobj.write(message, sizeof(class_message));
    outobj.close();
    sendto(udpClientSocket -> sock, histream.str().c_str(), size,
        MSG_CONFIRM, (const struct sockaddr *) &udpClientSocket->myAddr, 
            sizeof(udpClientSocket->myAddr));


    // sendto(udpClientSocket -> sock, (char *) & class_message, sizeof(class_message),
    //     MSG_CONFIRM, (const struct sockaddr *) &udpClientSocket->myAddr, 
    //         sizeof(udpClientSocket->myAddr));
    // printf("Hello message sent.\n");
           


    Message server_message;
   char *message_buffer = new char[sizeof(server_message)];
   

   stringstream clientstream; 
     n = recvfrom(udpClientSocket -> sock, (char*) message_buffer, MAXLINE, 
                MSG_WAITALL, (struct sockaddr *) &udpClientSocket->myAddr,
               &len);
    cout<<"received"<<endl; 
    clientstream= (stringstream) message_buffer;

    // Message client_message;
    {
        boost::archive::text_iarchive ia(clientstream);
        ia >> server_message;
    }
    cout<<"message_buffer in the server: "<< message_buffer<<endl; 
    cout<<"the stream in the server contains: "<< clientstream.str()<<endl;
    printf("Server : \n");
    server_message.print_message_info();
    
   
}

Message * Client:: execute(Message * _message){

}

Client:: ~Client(){
delete udpClientSocket;
}
