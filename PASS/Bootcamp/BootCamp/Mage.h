#ifndef MAGE_H
#define MAGE_H

#include "RPGClass.h"

class Mage : public RPGClass
{
public:
	Mage();
	~Mage();

	void Move();
	void Attack();
	void Defend();
	void Speak();
	void CastAbility();
};

#endif