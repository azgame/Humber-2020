#include "Square.h"



Square::Square()
{
	Shape();
}


Square::~Square()
{
}

float Square::GetArea()
{
	return w * h;
}
