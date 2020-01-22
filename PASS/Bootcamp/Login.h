#ifndef LOGIN_H
#define LOGIN_H

#include "client.h"

class Login : public Client
{
public:
    Login();
    ~Login();

    bool CheckUserName(std::string name_, std::string clientUserName_);
    bool CheckPassword(int pword_, int clientPWord_);
};

#endif
