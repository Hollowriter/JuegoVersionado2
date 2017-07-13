#ifndef BEATLE_H
#define BEATLE_H

#include "EnemyBase.h"
class Beatle : public EnemyBase{
private:
	const float speedMovement = 200.0f;
public:
	Beatle();
	Beatle(int vida, float tiempo);
	~Beatle();
	void Attack(sf::Time cuento, PlayerP* niña);
};

#endif