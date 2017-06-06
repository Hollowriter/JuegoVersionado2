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
public:
	EnemyBase();
	EnemyBase(sf::RectangleShape rectangulo, int vida);
	~EnemyBase();
	virtual void Attack(sf::Time cuento, sf::Clock reloj, PlayerP* niña) = 0;
	void Draw(sf::RenderWindow ventana);
	bool Death();
	void SetHealth(int vida);
	int GetHealth();
	sf::RectangleShape GetShape();
};

