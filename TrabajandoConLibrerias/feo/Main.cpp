#include<iostream>
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"PlayerP.h"
#include"Radroach.h"
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
	myomi = new PlayerP();
	cucarachita = new Radroach();
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
		window.clear(sf::Color::White);
		// window.draw(thyRectangle);
		// window.draw(leSprite);
		window.draw(myomi->GetShape());
		window.draw(cucarachita->GetShape());
		window.display();
		if (contando.asSeconds() > 20) {
			// relojito.restart();
		}
	}
	delete myomi;
	return 0;
}