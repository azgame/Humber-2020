#ifndef RPGCLASS_H
#define RPGCLASS_H

#include <string>
#include <iostream>

class RPGClass
{
public:
	RPGClass() {}
	~RPGClass() {}

	std::string name;

	virtual void Move() = 0;
	virtual void Attack() = 0;
	virtual void Defend() = 0;
	virtual void Speak() = 0;
	virtual void CastAbility() = 0;
};


#endif
