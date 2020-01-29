#include "client.h"

Client::Client()
{
    clientId = 0;
    userName = "";
    password = 10;
}

Client::Client(std::string userName_)
{
    clientId = 0;
    userName = userName_;
    password = 10;
}

Client::~Client()
{

}

void Client::SetUserName(std::string name_)
{
    userName = name_;
}

int Client::GetPassword()
{
    return password;
}
