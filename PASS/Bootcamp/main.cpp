#include <iostream>
#include "Login.h"

int Add(int* n1_, int* n2_);
int Add(int a, int b);
void Square(int &a);

int main() {

    Login login = Login();

    int n;
    Client c = Client();
    Client d = Client("John");
    Client* e = new Client("Sarah");

    std::cout << c.userName << std::endl;
    std::cout << d.userName << std::endl;
    std::cout << e->userName << std::endl;

    e->SetUserName("Laura");

    std::cout << e->userName << std::endl;

    int input = 15;

    if (login.CheckPassword(input, c.GetPassword()))
    {
        std::cout << "Login successfull" << std::endl;
    }

    /*int n = 10;

    int *a = (int*)malloc(sizeof(int) * n);

    std::cout << sizeof(a) << std::endl;

    for (int i = 0; i < n; i++) {
        a++;
        std::cout << a << std::endl;
    }*/

    return 0;
}

int Add(int a, int b)
{
    return a + b;
}

int Add(int* n1_, int* n2_)
{
    return *n1_ + *n2_;
}

void Square(int &a)
{
    a = a * a;
}
