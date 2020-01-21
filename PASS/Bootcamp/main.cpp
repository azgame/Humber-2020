#include <iostream>
#include "client.h"

int Square(int num1);
void Print(auto val);

int main() {

    Client c;
    c.id = 5;
    int num1 = 5;

    int num2 = Square(num1);
    Print(num2);
    Print(c.id);
    return 0;
}

int Add(int num1, int num2) {
    int num3 = num1 + num2;
    return num3;
}

int Square(int num1) {
    int num2 = num1 * num1;
    return num2;
}

void Print(auto val) {
    std::cout << val << std::endl;
}
