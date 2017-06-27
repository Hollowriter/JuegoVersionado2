#pragma once
#include<iostream>
#include<ctime>
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"PlayerP.h"
#include"Radroach.h"
#include"Beatle.h"
#include"Rock.h"
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
	PlayerP* myomi;
	/*EnemyBase* cucarachita[TOPE];
	EnemyBase* cascarudo[TOPE];*/
	EnemyBase* bichos[TOPE];
	Rock* mineral;
public:
	Game();
	~Game();
	void Play();
};

