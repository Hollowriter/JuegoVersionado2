#pragma once
#include "EnemyBase.h"
class Radroach :public EnemyBase{
public:
	Radroach();
	Radroach(sf::RectangleShape rectangulo, int vida, float tiempo);
	~Radroach();
	void Attack(sf::Time cuento, PlayerP* niña);
};

