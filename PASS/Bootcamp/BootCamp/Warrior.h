#ifndef WARRIOR_H
#define WARRIOR_H

#include "RPGClass.h"
class Warrior : public RPGClass
{
public:
	Warrior();
	~Warrior();

	void Move();
	void Attack();
	void Defend();
	void Speak();
	void CastAbility();
};

#endif