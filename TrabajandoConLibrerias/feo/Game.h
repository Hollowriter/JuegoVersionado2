#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<ctime>
#include<fstream>
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"
#include"SFML/Main.hpp"
#include"PlayerP.h"
#include"Radroach.h"
#include"Beatle.h"
#include"Rock.h"
#include"Clima.h"
#if DEBUG
#include"vld.h"
#else
#include<Windows.h>
#endif
#include"json.hpp"
#define TOPE 10
#define CLIMA 800
using namespace std;
using namespace nlohmann;
class Game
{
private:
	/*sf::Http thyHost;
	sf::Http::Request thyRequest;
	sf::Http::Response seinResponse;*/ // descomentas esto y LNK 2019/2001
	json datus;
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
	void Menu();
	void Play(sf::RenderWindow &window);
	void Credits(sf::RenderWindow &window);
};

#endif
