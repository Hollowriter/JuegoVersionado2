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
#include"Clima.h"
#include<Windows.h>
#if DEBUG
#include"vld.h"
#endif
// #include"../json.hpp" // json me tira un error de linkeo
#define TOPE 10
#define CLIMA 4
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
	string reportero;
	string detectorPuntos;
	fstream puntuacion;
	int clima;
	bool quieroJugar;
	const int basicHealth = 110;
	const int ventanaY = 600;
	const int ventanaX = 800;
public:
	Game();
	~Game();
	// void WindowCharge();
	void Menu(/*sf::RenderWindow &window*/);
	void Play(sf::RenderWindow &window);
	void Credits(sf::RenderWindow &window);
};

