#pragma once
#ifndef ENEMYBASE_H
#define ENEMYBASE_H

#include<iostream>
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"PlayerP.h"
#include"Rock.h"
class EnemyBase{
protected:
	sf::RectangleShape enemyShape;
	const int ditchedOutPosition = 1000;
	const int basicHealth = 20;
	const int playerAway = 30;
	const int positionLottery = 800;
	int health;
	int thyPosition;
	float enemyTime;
public:
	EnemyBase();
	EnemyBase(sf::RectangleShape rectangulo, int vida, float tiempo);
	~EnemyBase();
	virtual void Attack(sf::Time cuento, PlayerP* niña) = 0;
	void Draw(sf::RenderWindow &ventana);
	bool Death();
	void SetHealth(int vida);
	int GetHealth();
	void SetEnemyTime(float timing);
	float GetEnemyTime();
	void CollideRock(Rock* piedra);
	void Positioning(PlayerP* amenaza);
	sf::RectangleShape GetShape();
};

#endif