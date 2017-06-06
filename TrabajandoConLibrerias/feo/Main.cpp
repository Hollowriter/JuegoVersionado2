#include<iostream>
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"PlayerP.h"
#if DEBUG
#include"vld.h"
#endif
#include"json.hpp"
using namespace std;
int main() {
	sf::Time contando = sf::seconds(0.01f);
	sf::RenderWindow window(sf::VideoMode(800, 600), "CosaFea");
	PlayerP* myomi;
	myomi = new PlayerP();
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
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}
		myomi->Move(contando);
		window.clear(sf::Color::White);
		// window.draw(thyRectangle);
		// window.draw(leSprite);
		window.draw(myomi->GetShape());
		window.display();
	}
	delete myomi;
	return 0;
}