#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client
{
public:
    int clientId;
    std::string userName;

    Client();
    Client(std::string userName_);
    ~Client();
    void SetUserName(std::string name_);
    int GetPassword();
private:
    int password;
};

#endif
