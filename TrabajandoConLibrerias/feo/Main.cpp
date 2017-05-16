#include<iostream>
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
using namespace std;
int main() {
	sf::Time contando = sf::seconds(0.01f);
	sf::RenderWindow window(sf::VideoMode(800, 600), "CosaFea");
	sf::CircleShape shape(100.f);
	sf::RectangleShape thyRectangle(sf::Vector2f(100, 100));
	int square_x = 0;
	int square_y = 0;
	shape.setFillColor(sf::Color::Red);
	thyRectangle.setFillColor(sf::Color::Blue);
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}
		shape.move(contando.asSeconds(), 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			square_x -= contando.asSeconds();
			thyRectangle.move(square_x, square_y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			square_x += contando.asSeconds();
			thyRectangle.move(square_x, square_y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			square_y -= contando.asSeconds();
			thyRectangle.move(square_x, square_y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			square_y += contando.asSeconds();
			thyRectangle.move(square_x, square_y);
		}
		window.clear(sf::Color::White);
		window.draw(shape);
		window.draw(thyRectangle);
		window.display();
	}
	return 0;
}