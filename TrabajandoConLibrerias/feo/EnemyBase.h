#pragma once
#include<iostream>
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
class EnemyBase{
private:
	sf::RectangleShape enemyShape;
	int health;
public:
	EnemyBase();
	EnemyBase(sf::RectangleShape rectangulo, int vida);
	~EnemyBase();
	virtual void Attack(sf::Time cuento) = 0;
	void Draw(sf::RenderWindow ventana);
	bool Death();
	void SetHealth(int vida);
	int GetHealth();
	sf::RectangleShape GetShape();
};

