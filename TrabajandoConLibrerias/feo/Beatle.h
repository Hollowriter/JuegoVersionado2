#pragma once
#include "EnemyBase.h"
class Beatle : public EnemyBase{
public:
	Beatle();
	Beatle(sf::RectangleShape rectangulo, int vida, float tiempo);
	~Beatle();
	void Attack(sf::Time cuento, PlayerP* niña);
};

