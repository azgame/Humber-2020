#include "JoeExotic.h"

#include <iostream>
#include <string>
#include <random>
#include <time.h>


JoeExotic::JoeExotic()
{
	mInsanity = 10;
	mPublicAttention = 20;
	mKillBaskins = false;
	mMoney = 10000;
	mState = JEState::CheckAccount; // initial state

	srand(time(NULL)); // set initial seed
}

JoeExotic::~JoeExotic()
{
	// ShutDown
}

bool JoeExotic::RunningTheZoo()
{
	if (mPublicAttention > CAUGHT && (int)(mState & JEState::Investigation))
		return false;

	mMoney += mPublicAttention; // The more attention, the more money

	if ((int)(mState & JEState::JeffLowe))
		mMoney = std::rand() % 20000;

	if (mMoney > 0 && mMoney < MONEY_CHECK)
		JoeIsBroke();
	else
	{
		if (mMoney < 0)
		{
			mState |= JEState::JeffLowe;
			std::cout << "Joe has sold out to Jeff Lowe" << std::endl;
		}
		else MoMoneyMoProblems();

		mInsanity += rand() % 16 + 1;
		if (rand() % 5 == 4) mKillBaskins = true;
	}
		
	if (mPublicAttention > START_INVESTIGATION) // Joe has drawn too much negative attention, he is under FBI investigation now
	{
		mState |= JEState::Investigation;
		std::cout << "Joe is under investigation" << std::endl;
	}

	if (mPublicAttention < 0 && (int)(mState & JEState::Investigation)) // Can end the investigation if he leaves the public spotlight
	{
		mState = ~JEState::Investigation;
		std::cout << "Joe is no longer under investigation" << std::endl;
	}

	return true;
}

void JoeExotic::MoMoneyMoProblems()
{
	if (mInsanity > INS_LVL_3) // Run for president/governor
	{
		if (!(int)(mState & JEState::Investigation))
			mPublicAttention += rand() % 26 + 5;
		mMoney -= 100000;
		std::cout << "Joe is running for office" << std::endl;
	}
	else if (mInsanity > INS_LVL_2) // Marry a young man
	{
		mPublicAttention -= rand() % 6 + 1;
		mMoney -= 10000;
		std::cout << "Joe is getting married" << std::endl;
	}
	else if (mInsanity > INS_LVL_1) // Film spicy garbage
	{
		if (!(int)(mState & JEState::Investigation))
			mPublicAttention += rand() % 11 + 1;

		mMoney -= rand() % 501 + 500;
		std::cout << "Joe is filming some hot garbage" << std::endl;
	}
}

void JoeExotic::JoeIsBroke()
{
	if (mKillBaskins) // Wants to kill CB
	{
		mInsanity = 0;
		mMoney += rand() % 4501 + 500;
		mPublicAttention += rand() % 26 + 5;
		mKillBaskins = false;
		if ((int)(mState & JEState::Investigation))
			mPublicAttention += rand() % 26 + 5;

		std::cout << "Joe has threatened to kill Carole Baskins" << std::endl;
	}
	else // Just breed a tiger cub and get on with it
	{
		mMoney += 10000;
		mPublicAttention -= rand() % 6 + 1;
		std::cout << "Joe is breeding tigers" << std::endl;
	}
}


std::ostream& operator<<(std::ostream& out, const JoeExotic joe)
{
	out << "Joe Exotic is " << (joe.mInsanity > 50 ? "very" : (joe.mInsanity < 25 ? "not" : "a little")) << " insane, has " 
		<< joe.mMoney << " dollars, is "
		<< (joe.mPublicAttention > 100 ? "in" : "not in") << " the public eye, and " 
		<< (joe.mKillBaskins ? "wants" : "does not want") << " to kill Carole Baskin.";
	return out;
}

