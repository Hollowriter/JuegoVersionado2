#pragma once
#include "EnemyBase.h"
class Radroach :public EnemyBase{
public:
	Radroach();
	Radroach(sf::RectangleShape rectangulo, int vida);
	~Radroach();
	void Attack(sf::Time cuento, sf::Clock reloj, PlayerP* niña);
};

