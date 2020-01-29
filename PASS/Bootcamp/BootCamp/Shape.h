#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>

class Shape
{
public:
	Shape();
	~Shape();

	int w, h;
	float r, g, b;

	void SetName(std::string name_)				{ name = name_; }
	std::string GetName()						{ return name; }
	void SetBoundary(int w_, int h_);
	void SetColour(float r_, float g_, float b_);
	virtual float GetArea();
	void Print();
protected:
	std::string name;
};

#endif