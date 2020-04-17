#ifndef _JOE_EXOTIC_H
#define _JOE_EXOTIC_H

#include <ostream>

#define MONEY_CHECK 10000
#define INS_LVL_1 25
#define INS_LVL_2 50
#define INS_LVL_3 75
#define START_INVESTIGATION 200
#define CAUGHT 500

// Only using three checks, but with some more sophistication, I could use all of these
enum class JEState
{
	Investigation = 1,
	Film = 2,
	Marry = 4,
	Campaign = 8,
	InsanityCheck = 16,
	CheckAccount = 32,
	KillCaroleCheck = 64,
	BreedTigers = 128,
	ThreatenCB = 256,
	JeffLowe = 512
};

class JoeExotic
{
public:

	JoeExotic();
	~JoeExotic();

	bool RunningTheZoo();
	void MoMoneyMoProblems();
	void JoeIsBroke();

	friend std::ostream& operator<<(std::ostream& out, const JoeExotic joe);

	// This all seems like much more work than its worth
	int _i, _m, _p;
	bool _b;

	void setInsanity(int i_)			{ _i = i_; }
	int getInsanity() const				{ return _i; }

	void setMoney(int m_)				{ _m = m_; }
	int getMoney() const				{ return _m; }

	void setPublicAttention(int p_)		{ _p = p_; }
	int getPublicAttention() const		{ return _p; }

	void setDesireToKillCB(bool cb_)	{ _b = cb_; }
	bool getDesireToKillCB() const		{ return _b; }

private:

	JEState			mState;

	
	__declspec(property(put = setInsanity,			get = getInsanity))				int mInsanity;
	__declspec(property(put = setPublicAttention,	get = getPublicAttention))		int mPublicAttention;
	__declspec(property(put = setDesireToKillCB,	get = getDesireToKillCB))		bool mKillBaskins;
	__declspec(property(put = setMoney,				get = getMoney))				int mMoney;

};


inline JEState operator<<(JEState s1_, int i)			{ return (JEState)((int)(s1_) << i); }
inline JEState operator>>(JEState s1_, int i)			{ return (JEState)((int)(s1_) >> i); }
inline JEState operator&(JEState s1_, JEState s2_)		{ return (JEState)((int)(s1_) & (int)(s2_)); }
inline JEState operator|(JEState s1_, JEState s2_)		{ return (JEState)((int)(s1_) | (int)(s2_)); }
inline JEState operator^(JEState s1_, JEState s2_)		{ return (JEState)((int)(s1_) ^ (int)(s2_)); }
inline JEState operator~(JEState s1_)					{ return (JEState)~(int)s1_; }
inline JEState& operator^=(JEState& s1_, JEState s2_)	{ return (JEState&)((int&)(s1_) ^= (int)(s2_)); }
inline JEState& operator|=(JEState& s1_, JEState s2_)	{ return (JEState&)((int&)(s1_) |= (int)(s2_)); }
inline JEState& operator&=(JEState& s1_, JEState s2_)	{ return (JEState&)((int&)(s1_) &= (int)(s2_)); }

#endif 