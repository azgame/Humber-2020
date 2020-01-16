#include <iostream>

int Square(int num1);

int main() {

    int num1 = 5;

    int num2 = Square(num1);
    std::cout << num2 << std::endl;
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


void Print() {

}
