#include "rfid.h"

String users[2];


void usersSetup() {
    rfidFunctionSetup();
}

void getUID(){


    String user = rfidFunction();

    if (users->length() == 0)
    {
        if (user != "NO CARD")
        {
            Serial.println(user + " is user1");
            users[0] = user;
            delay(2000);
        }
    }


    if (users->length() == 8)
    {
        user = rfidFunction();
        if (user != "NO CARD")
        {
            Serial.println(user + " is user2");
            users[1] = user;
            delay(2000);
            for(String user: users){
            Serial.println(user);
            }
        }
    }
    
}
