#pragma once
#include<iostream>
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
using namespace std;
class PlayerP {
private:
	sf::CircleShape thyShape;
	int health;
	int bullets;
	int score;
public:
	PlayerP();
	void Move();
	void Death();
	void Draw(sf::CircleShape circulo);
	void SetHealth(int vida);
	void SetBullets(int balas);
	void SetScore(int puntos);
	int GetHealth();
	int GetBullets();
	int GetScore();
	sf::CircleShape GetShape();
};