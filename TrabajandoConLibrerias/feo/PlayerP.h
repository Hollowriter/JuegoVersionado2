#pragma once
#include<iostream>
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
using namespace std;
class PlayerP {
private:
	sf::RectangleShape thyShape;
	int health;
	int bullets;
	int score;
	int direction;
public:
	PlayerP();
	PlayerP(int vida, int balas, int puntos, int direccion, sf::RectangleShape rectangular);
	void Move(sf::Time cuento);
	bool Death();
	void Draw(sf::RenderWindow &ventana);
	void SetHealth(int vida);
	void SetBullets(int balas);
	void SetScore(int puntos);
	void SetDirection(int direccion);
	int GetHealth();
	int GetBullets();
	int GetScore();
	int GetDirection();
	sf::RectangleShape GetShape();
};