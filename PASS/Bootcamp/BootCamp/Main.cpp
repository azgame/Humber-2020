#include "Square.h"
#include "Triangle.h"
#include "Mage.h"
#include "Warrior.h"

int main() {

	Shape a = Shape();
	Square b = Square();
	Triangle c = Triangle();
	RPGClass* hero = new Mage();
	hero->Speak();
	hero = new Warrior();
	hero->Speak();

	/*a.Print();
	b.Print();
	c.Print();

	a.SetName("shape");
	b.SetName("square");
	c.SetName("triangle");

	a.SetBoundary(4, 5);
	b.SetBoundary(4, 5);
	c.SetBoundary(4, 5);

	a.SetColour(1.0f, 1.0f, 1.0f);
	b.SetColour(0.2f, 1.0f, 0.0f);
	c.SetColour(1.0f, 0.5f, 0.0f);

	a.Print();
	b.Print();
	c.Print();*/

	return 0;
}