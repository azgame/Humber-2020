#include <iostream>
#include <string>
#include <limits>

int Square(int);

/*
  Notes:
*/

class Test
{
public:
  	Test() {
    		n = 0;
  	}

  	~Test() {}

  	int GetN() { return n; }
  	void SetN(int n_) { n = n_; }

private:
  	int n;
};



int main() {

	bool isRunning = true;
	while (isRunning)
  	{
    		int num;
    		if (std::cout << "Give number: " && !(std::cin >> num)) {
      			return -1;
    		}
    		std::string choice;
    		while (std::cout << "Select function: " && !(std::cin >> choice)) {
      			std::cin.clear();
      			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      			std::cout << "Invalid input; please re-enter.\n";
    		}
    		if (choice == "square")
    		{
      			std::cout << Square(num) << std::endl;
    		}
    		else if (choice == "exit")
    		{
      			isRunning = false;
    		}
	}

  	return 0;
}


int Square(int sq)
{
  	return sq * sq;
}
