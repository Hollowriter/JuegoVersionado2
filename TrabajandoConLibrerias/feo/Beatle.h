#pragma once
#ifndef BEATLE_H
#define BEATLE_H

#include "EnemyBase.h"
class Beatle : public EnemyBase{
private:
	const float speedMovement = 0.2f;
public:
	Beatle();
	Beatle(sf::RectangleShape rectangulo, int vida, float tiempo);
	~Beatle();
	void Attack(sf::Time cuento, PlayerP* niña);
};

#endif