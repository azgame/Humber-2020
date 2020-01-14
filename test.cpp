#include <iostream>
#include "include.h"

int main() {
  Include i = Include();
  i.n = 5;
  std::cout << i.n << std::endl;
  return 0;
}
