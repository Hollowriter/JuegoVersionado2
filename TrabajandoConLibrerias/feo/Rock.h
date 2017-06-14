#pragma once
#include"PlayerP.h"
class Rock
{
private:
	int look;
	bool thrown;
public:
	Rock();
	~Rock();
	void Path(int thyDirection);
	void SetThrown(bool tirado);
	void SetLook(int Look);
	bool GetThrown();
	bool GetLook();
};

