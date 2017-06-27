#pragma once
#ifndef ROCK_H
#define ROCK_H

#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
// #include"EnemyBase.h"
class Rock
{
private:
	const int ditchedOutPosition = 1000;
	const float speedMovement = 300.0f;
	int look;
	bool thrown;
	sf::RectangleShape seinShape;
public:
	Rock();
	~Rock();
	void Path(sf::RenderWindow &ventanita, sf::Time cuento);
	void SetThrown(bool tirado);
	void SetLook(int observado);
	// void CollideEnemy(EnemyBase* blanco);
	bool GetThrown();
	int GetLook();
	sf::RectangleShape& GetShape();
};

#endif