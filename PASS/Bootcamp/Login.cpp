#include "Login.h"

Login::Login() : Client()
{

}
Login::~Login() {}

bool Login::CheckUserName(std::string name_, std::string clientUserName_)
{
    return name_ == clientUserName_;
}

bool Login::CheckPassword(int pword_, int clientPWord_)
{
    return pword_ == clientPWord_;
}
