#include<iostream>
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
using namespace std;
int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "CosaFea");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);
		window.draw(shape);
		window.display();
	}
	return 0;
}