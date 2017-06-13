#include<iostream>
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"PlayerP.h"
#include"Radroach.h"
#include"Beatle.h"
#if DEBUG
#include"vld.h"
#endif
#include"json.hpp"
using namespace std;
int main() {
	sf::Clock relojito;
	sf::Time contando = relojito.restart();
	sf::RenderWindow window(sf::VideoMode(800, 600), "CosaFea");
	PlayerP* myomi;
	EnemyBase* cucarachita;
	EnemyBase* cascarudo;
	myomi = new PlayerP();
	cucarachita = new Radroach();
	cascarudo = new Beatle();
	// sf::CircleShape shape(100.f);
	// sf::RectangleShape thyRectangle(sf::Vector2f(100, 100));
	/*sf::Texture thyTexture;
	sf::Sprite leSprite;
	sf::Music spicy;*/
	/*spicy.openFromFile("Spicy.wav");
	spicy.play();
	thyTexture.loadFromFile("verdecito.png");
	leSprite.setTexture(thyTexture);
	leSprite.scale(0.3f, 0.3f);
	leSprite.setPosition(200, 200);*/
	// shape.setFillColor(sf::Color::Red);
	// thyRectangle.setFillColor(sf::Color::Blue);
	// bool laColision = false;
	while (window.isOpen() && !(myomi->Death())){
		sf::Event event;
		contando = relojito.restart();
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}
		myomi->Move(contando);
		cucarachita->Attack(contando, myomi);
		cascarudo->Attack(contando, myomi);
		if (myomi->GetShape().getGlobalBounds().intersects(cucarachita->GetShape().getGlobalBounds()) &&
			!(cucarachita->Death())) {
			myomi->SetHealth(myomi->GetHealth() - cucarachita->GetHealth());
			cucarachita->SetHealth(cucarachita->GetHealth() - cucarachita->GetHealth());
		}
		if (myomi->GetShape().getGlobalBounds().intersects(cascarudo->GetShape().getGlobalBounds()) &&
			!(cascarudo->Death())) {
			myomi->SetHealth(myomi->GetHealth() - cascarudo->GetHealth());
			cascarudo->SetHealth(cascarudo->GetHealth() - cascarudo->GetHealth());
		}
		window.clear(sf::Color::White);
		// window.draw(thyRectangle);
		// window.draw(leSprite);
		window.draw(myomi->GetShape());
		window.draw(cucarachita->GetShape());
		window.draw(cascarudo->GetShape());
		window.display();
	}
	delete myomi;
	delete cucarachita;
	delete cascarudo;
	return 0;
}