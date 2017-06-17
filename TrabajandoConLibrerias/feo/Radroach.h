#pragma once
#ifndef RADROACH_H
#define RADROACH_H
#include "EnemyBase.h"
class Radroach :public EnemyBase{
private:
	const int internalTimer = 4;
	const int subTimer = internalTimer / 2;
	const float speedMovement = 0.3f;
public:
	Radroach();
	Radroach(sf::RectangleShape rectangulo, int vida, float tiempo);
	~Radroach();
	void Attack(sf::Time cuento, PlayerP* niña);
};

#endif