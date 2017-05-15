#include<iostream>
#include"..\SFML-2.4.2\include\SFML\Window.hpp"
using namespace std;
int main() {
	sf::Window window(sf::VideoMode(800, 600), "CosaFea");
	/*while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}*/
	return 0;
}