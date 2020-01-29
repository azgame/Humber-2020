#include "Triangle.h"



Triangle::Triangle()
{
	Shape();
}


Triangle::~Triangle()
{
}

float Triangle::GetArea()
{
	return (w * h) / 2.0f;
}
