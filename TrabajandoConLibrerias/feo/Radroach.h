#ifndef RADROACH_H
#define RADROACH_H

#include "EnemyBase.h"
class Radroach :public EnemyBase{
private:
	const int internalTimer = 4;
	const int subTimer = internalTimer / 2;
	const float speedMovement = 200.0f;
public:
	Radroach();
	Radroach(int vida, float tiempo);
	~Radroach();
	void Attack(sf::Time cuento, PlayerP* niña);
};

#endif