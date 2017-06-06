#pragma once
#include "EnemyBase.h"
class Radroach :
	public EnemyBase
{
public:
	Radroach();
	Radroach(sf::RectangleShape rectangulo, int vida);
	~Radroach();
};

