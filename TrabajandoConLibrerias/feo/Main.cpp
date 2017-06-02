#include<iostream>
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#if DEBUG
#include"vld.h"
#endif
#include"json.hpp"
using namespace std;
int main() {
	sf::Time contando = sf::seconds(0.01f);
	sf::RenderWindow window(sf::VideoMode(800, 600), "CosaFea");
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
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// shape.move(contando.asSeconds(), 0);
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			thyRectangle.move(-(contando.asSeconds() * 10), 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			thyRectangle.move(contando.asSeconds() * 10, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			thyRectangle.move(0, -(contando.asSeconds() * 10));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			thyRectangle.move(0, contando.asSeconds() * 10);
		}
		if (thyRectangle.getGlobalBounds().intersects(leSprite.getGlobalBounds())) {
			laColision = true;
		}
		if (laColision == true) {
			leSprite.move(0, contando.asMilliseconds());
		}*/
		window.clear(sf::Color::White);
		// window.draw(shape);
		// window.draw(thyRectangle);
		// window.draw(leSprite);
		window.display();
	}
	return 0;
}