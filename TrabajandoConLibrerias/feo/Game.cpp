#include "Game.h"

Game::Game()
:
puntaje(0),
puntajeMasAlto(0){
	srand(time(0));
}
Game::~Game(){
	delete myomi;
	delete mineral;
	for (int i = 0; i < TOPE; i++){
		if (bichos[i] != NULL) {
			delete bichos[i];
			bichos[i] = NULL;
		}
	}
	myomi = NULL;
	mineral = NULL;
}
void Game::Play(){
	musiquita.openFromFile("someone.ogg");
	musiquita.play();
	myomi = new PlayerP();
	mineral = new Rock();
	for (int i = 0; i < TOPE; i++) {
		if (i < TOPE / 2) {
			bichos[i] = new Radroach();
		}
		else if (i >= TOPE / 2) {
			bichos[i] = new Beatle();
		}
		if (bichos[i] != NULL) {
			bichos[i]->Positioning(myomi);
		}
	}
	contando = relojito.restart();
	sf::RenderWindow window(sf::VideoMode(800, 600), "CosaFea");
	while (window.isOpen() && !(myomi->Death())) {
		sf::Event event;
		contando = relojito.restart();
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		myomi->Move(contando);
		myomi->Throwing(mineral);
		mineral->Path(window, contando);
		for (int i = 0; i < TOPE; i++){
			if (bichos[i] != NULL) {
				bichos[i]->Attack(contando, myomi);
				bichos[i]->CollideRock(mineral);
				if (myomi->GetShape().getGlobalBounds().intersects(bichos[i]->GetShape().getGlobalBounds()) &&
					!(bichos[i]->Death())) {
					myomi->SetHealth(myomi->GetHealth() - bichos[i]->GetHealth());
					bichos[i]->SetHealth(bichos[i]->GetHealth() - bichos[i]->GetHealth());
				}
				bichos[i]->AfterLife(myomi);
			}
		}
		window.clear(sf::Color::White);
		window.draw(myomi->GetShape());
		window.draw(mineral->GetShape());
		for (int i = 0; i < TOPE; i++){
			if (bichos[i] != NULL) {
				window.draw(bichos[i]->GetShape());
			}
		}
		window.display();
	}
}