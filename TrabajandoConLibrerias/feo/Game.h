#pragma once
#include<iostream>
#include<ctime>
#include<fstream>
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"
#include"PlayerP.h"
#include"Radroach.h"
#include"Beatle.h"
#include"Rock.h"
#include<Windows.h>
#if DEBUG
#include"vld.h"
#endif
#include"json.hpp"
#define TOPE 10
using namespace std;
class Game
{
private:
	sf::Clock relojito;
	sf::Time contando;
	sf::Music musiquita;
	PlayerP* myomi;
	EnemyBase* bichos[TOPE];
	Rock* mineral;
	sf::Font fuente;
	sf::Text texto;
	int puntaje;
	int puntajeMasAlto;
	int clima;
	bool quieroJugar;
	const int sunny = 32;
	const int cloudy = 26;
	const int hot = 36;
	const int foggy = 20;
public:
	Game();
	~Game();
	void Menu();
	void Play(sf::RenderWindow &window);
	void Credits(sf::RenderWindow &window);
};

