#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape
{
public:
	Square();
	~Square();

	float GetArea();
};

#endif