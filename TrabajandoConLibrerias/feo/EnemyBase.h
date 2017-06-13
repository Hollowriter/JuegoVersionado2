#pragma once
#include<iostream>
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"PlayerP.h"
class EnemyBase{
protected:
	sf::RectangleShape enemyShape;
	int health;
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
	sf::RectangleShape GetShape();
};

