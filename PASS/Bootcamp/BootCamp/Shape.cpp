#include "Shape.h"



Shape::Shape()
{
	name = "";
	w = h = 0;
	r = g = b = 0.0f;
}


Shape::~Shape() {}

void Shape::SetBoundary(int w_, int h_)
{
	w = w_;
	h = h_;
}

void Shape::SetColour(float r_, float g_, float b_)
{
	r = r_;
	g = g_;
	b = b_;
}

float Shape::GetArea()
{
	return 0.0f;
}

void Shape::Print()
{
	std::cout << name <<  "\nIs coloured: [" << r
		<< ", " << g << ", " << b << "]" << std::endl;
	std::cout << "with area: " << GetArea() << std::endl;
}
