#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <iostream>
#include <iomanip>
using namespace std; 
class PlayerInventory {
    friend class boost::serialization::access;
    template <class Archive> void serialize(Archive& ar, unsigned) {
        ar &itemID &itemCount ;
    }

  public:
    int itemID;
    int itemCount;
    void print_myname(){
        std::cout<<"maco 7omarrrr\n "<<std::endl; 
    }
};

enum MessageType { Request, Reply};
struct honey{int h; int w;};
class player {
    friend class boost::serialization::access;
    template <class Archive> void serialize(Archive& ar, unsigned) {
        ar &username &password &inv &mytest.h &mytest.w &msgtype &actmsg; 
    }

  public:
    std::string                  username;
    std::string                  password;
    std::vector<PlayerInventory> inv;
    honey mytest;
    std::string actmsg; 
    MessageType msgtype; 
    std::string print_myname(){
        return username;  
    }
};

#include <sstream>
int main() {
    std::stringstream ss;

    {
        boost::archive::text_oarchive oa(ss);

        player to_save;
        to_save.username = "bla";
        to_save.password = "blo";
        to_save.inv = {
                { 1, 17 },
                { 2, 11 },
                { 3, 8800 },
                { 4, 0 },
                { 5, 1 },
                { 6, 1 },
                { 7, 1 },
                { 8, 1 },
                { 9, 42 },
            };
        to_save.mytest.h=5;
        to_save.mytest.w=7; 
        to_save.msgtype= Reply;
        char* accms= "helloredsfsdf";
        to_save.actmsg=accms;
        oa << to_save;
    } // <-- destructor of text_oarchive

    std::cout << "Serialized stream: " << std::quoted(ss.str()) << std::endl;

    player loaded;
    {
        boost::archive::text_iarchive ia(ss);
        ia >> loaded;
    }

    std::cout << "Roundtrip username:" << std::quoted(loaded.username)
              << " password:" << std::quoted(loaded.password) << std::endl;

    for (auto [id, count] : loaded.inv) {
        std::cout << " - item " << id << " count:" << count << std::endl;
    
    }
    string ma= "ddddddddd";
    char* pa= (char*)ma.c_str();
    cout<<ma<<endl; 
    std::cout<<loaded.print_myname()<<std::endl;
    std::cout<<loaded.mytest.h<<std::endl;
    std::cout<<loaded.mytest.w<<std::endl;
    std::cout<<loaded.msgtype<<std::endl;
    cout<<loaded.actmsg<<endl;






}