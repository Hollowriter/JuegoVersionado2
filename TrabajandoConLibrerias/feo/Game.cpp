#include "Game.h"

Game::Game(){
    myomi = new PlayerP();
	/*cucarachita = new Radroach();
	cascarudo = new Beatle();*/
	mineral = new Rock();
	/*cucarachita->Positioning(myomi);
	cascarudo->Positioning(myomi);*/
	for (int i = 0; i < TOPE; i++){
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
}
Game::~Game(){
	delete myomi;
	/*delete cucarachita;
	delete cascarudo;*/
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
	srand(time(0));
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
			}
		}
		/*cucarachita->Attack(contando, myomi);
		cascarudo->Attack(contando, myomi);
		cucarachita->CollideRock(mineral);
		cascarudo->CollideRock(mineral);*/
		/*if (myomi->GetShape().getGlobalBounds().intersects(cucarachita->GetShape().getGlobalBounds()) &&
			!(cucarachita->Death())) {
			myomi->SetHealth(myomi->GetHealth() - cucarachita->GetHealth());
			cucarachita->SetHealth(cucarachita->GetHealth() - cucarachita->GetHealth());
		}
		if (myomi->GetShape().getGlobalBounds().intersects(cascarudo->GetShape().getGlobalBounds()) &&
			!(cascarudo->Death())) {
			myomi->SetHealth(myomi->GetHealth() - cascarudo->GetHealth());
			cascarudo->SetHealth(cascarudo->GetHealth() - cascarudo->GetHealth());
		}*/
		window.clear(sf::Color::White);
		// window.draw(thyRectangle);
		// window.draw(leSprite);
		window.draw(myomi->GetShape());
		/*window.draw(cucarachita->GetShape());
		window.draw(cascarudo->GetShape());*/
		window.draw(mineral->GetShape());
		for (int i = 0; i < TOPE; i++){
			if (bichos[i] != NULL) {
				window.draw(bichos[i]->GetShape());
			}
		}
		window.display();
	}
}