#ifndef PLAYERP_H
#define PLAYERP_H

#include<iostream>
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"Rock.h"
using namespace std;
class PlayerP {
private:
	sf::Texture thyTexture;
	sf::IntRect rectSourceSprite;
	sf::Sprite seinSprite;
	const int startingPosition = 100;
	const int velocity = 750;
	const int startingHealth = 110;
	const int spriteX = 46;
	const int spriteY = 64;
	const int anim1 = 45;
	const int anim2 = 64;
	const int anim4 = 135;
	int health;
	int score;
	int direction;
public:
	PlayerP();
	PlayerP(int vida, int puntos, int direccion, sf::RectangleShape rectangular);
	void Move(sf::Time cuento);
	bool Death();
	void Draw(sf::RenderWindow &ventana);
	void SetHealth(int vida);
	void SetScore(int puntos);
	void SetDirection(int direccion);
	void Throwing(Rock* piedra);
	int GetHealth();
	int GetScore();
	int GetDirection();
	sf::Sprite GetShape();
	sf::IntRect GetRect();
};

#endif