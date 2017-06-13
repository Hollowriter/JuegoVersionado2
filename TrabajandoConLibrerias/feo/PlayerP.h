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
public:
	PlayerP();
	PlayerP(int vida, int balas, int puntos, sf::RectangleShape rectangular);
	void Move(sf::Time cuento);
	bool Death();
	void Draw(sf::RenderWindow &ventana);
	void SetHealth(int vida);
	void SetBullets(int balas);
	void SetScore(int puntos);
	int GetHealth();
	int GetBullets();
	int GetScore();
	sf::RectangleShape GetShape();
};