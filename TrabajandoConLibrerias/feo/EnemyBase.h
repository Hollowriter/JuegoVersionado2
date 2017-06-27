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
	sf::Texture thyTexture;
	sf::IntRect rectSourceSprite;
	sf::Sprite seinSprite;
	const int ditchedOutPosition = 1000;
	const int basicHealth = 20;
	const int playerAway = 30;
	const int positionLottery = 800;
	int health;
	int thyPosition;
	float enemyTime;
public:
	EnemyBase();
	EnemyBase(int vida, float tiempo);
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
	sf::Sprite& GetShape();
	sf::IntRect GetRect();
};

#endif