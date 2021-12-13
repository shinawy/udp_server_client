#include "message.h"
#include "client.h"
#include "server.h"
#include "udpclientsocket.h"
#include "udpserversocket.h"
#include "udpsocket.h"
#include <string>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "user.h"




bool client_log_in(string& username, string& password, User& usr);
bool client_sign_up(string& username, string& password, User& usr);

void input_user(string& username, string& password){
            cout << "Enter Username: \n";
            cin >> username;
            cout << "Enter Password: \n";
            cin >> password;
}

void input_user_fullname(string& firstname, string& lastname){
    cout<<"Enter your first name: \n";
    cin>>firstname; 
    cout<<"Enter your last name:\n"; 
    cin>>lastname;
}


bool client_log_in(string& username, string& password, User& usr){
    cout<<"login Window.................."<<endl;
    Json::Value response;
    input_user(username, password);
    response= usr.login(username,password);
    usr.set_username(username);
    cout<<"response_client_log_in: "<<response<<endl;
    if (response["registered"]==0){
        cout<<"User Not registered, opening sign up page\n";
        client_sign_up(username, password, usr);

    }
    else if (response["password"]==0){
        cout<<"Password is wrong, please enter valid username and password\n";
        client_log_in(username, password, usr);
    }
    else {
        return 1;
    }


}

bool client_sign_up(string& username, string& password, User& usr){
    cout<<"Registeration Window***********: \n";
    string firstname, lastname;
    Json::Value response;
    input_user(username, password); 
    input_user_fullname(firstname, lastname);    
    response= usr.register_user(username, password,firstname, lastname);
    usr.set_username(username);

    cout<<"response_client_sign_up: "<< response<<endl;
    if (response["ERROR"]== "Username Already Registered"){
        cout<<"Try different username for sign up or choose to log in: \n";
        cout<<"Please press the number corresponding to the functionality you need: \n";
        cout<<"1) Login\n";
        cout<<"2) Sign Up with different username"; 

        int choice; 
        cout<<"\nEnter your choice\n";
        cin>>choice; 
        if (choice==2)
            client_sign_up(username, password, usr);
        else 
            client_log_in(username, password, usr);

    }
    else {
        return 1;
    }
    


}

int main() {

    cout << "Welcome to The Online Image Sharing Server\n"; 
    
    string hostname = "macoclient";


    Client myclient((char*)hostname.c_str(), 8080);
    
    cout << "1) Login\n";
    cout << "2) Register User\n"; 
    string username, password;
    
    User usr;

    int op0;
    cin >> op0;
    Json::Value response;
    bool ans=0;
    if (op0 == 1) {
           ans= client_log_in(username, password, usr);
            if (ans)
                cout<<"USER successfully logged in"<<endl; 
            else
                cout<<"User is not logged in"<<endl;
    } else if (op0 == 2) {
            
            ans= client_sign_up(username, password, usr);
            if (ans){
                cout<<"USER Registered Successfully\n";
            }
            else 
                cout<<"Error while registering this user\n";
            
    }


    int op;           

    do{
        cout << "[*]------------------------------------------------------[*]\n";
        cout << "Enter number for the option you want: \n";
        cout << "1) Upload an Image\n";
        cout << "2) View Your Images\n";
        cout << "3) Removre Viewers\n";
        cout << "4) Edit Viewers Quota\n";
        cout<<  "5) Grant user permission to see your images\n";
        cout << "6) View Images for Other users\n";
        cout << "7) Exit\n";
        cout<<  "8) Log in with another user account\n";
        cout << "[*]------------------------------------------------------[*]\n";
         
        cin >> op;

        cout<<"You are now logged in as "<<usr.getusername()<<endl;
        switch (op) {
            case 1: 
            {
                printf("Enter Image Path: \n");
                string comm;
                cin >> comm;
                Message* client_message = usr.upload_image(comm); 
                myclient.send_request(*client_message);
                break;
            }
            case 2: 
            {
                Json::Value res_images= usr.view_owned_images(usr.getusername());
                cout<<"Result Images: "<< res_images<<endl;
                break;
            }
                
            
            case 3: 
            {
                cout << "Enter the username for the person you want to remove: \n";
                string user;
                cin >> user;
                usr.remover_viewer(usr.getusername(),user);
                break;
            }
            case 4:
            {
                cout << "Enter Viewer username: \n";
                string user;
                cin >> user;

                int quota;
                cout<<"Enter the new Quota you want to assign for this person: \n";
                cin>>quota;
                usr.edit_viewer_quota(usr.getusername(),user,quota);
                break;
            }

            case 5: {
                string guest_user_name;
                cout<<"Enter the username for the person you want to grant access\n";
                cin>>guest_user_name;

                int quota;
                cout<<"Enter the Quota for this person: \n";
                cin>>quota;
             
                Json::Value res_add_perm = usr.add_user_quota(usr.getusername(),guest_user_name,quota);
                cout<<"Granted access Response: "<<res_add_perm<<endl;
                break; 
            }
            case 6:{ 
                string username; 
                cout<<"Enter the username you want to see their picture\n"; 
                cin>> username;
                Json::Value res_view_other =usr.view_image(username,usr.getusername());
                cout<<"Photos of other user called "<<username<<": "<<endl<<res_view_other<<endl;
                break;
            }
            case 7:
                return 0;
            
            case 8:{
            ans= client_log_in(username, password, usr);
            if (ans)
                cout<<"USER successfully logged in"<<endl; 
            else
                cout<<"User is not logged in"<<endl;
            break;    
            }
        }


    } while (op != 7);

    return 0; 
}
