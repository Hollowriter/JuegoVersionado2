#include "Rock.h"

Rock::Rock()
:
look(0),
thrown(false),
seinShape(sf::Vector2f(10, 10)){
	seinShape.setPosition(80, 80);
}
Rock::~Rock(){
}
void Rock::Path(sf::RenderWindow &ventanita){
	if (thrown == true) {
		switch (look) {
		case 0:
			seinShape.move(0, -1);
			break;
		case 1:
			seinShape.move(1, 0);
			break;
		case 2:
			seinShape.move(0, 1);
			break;
		case 3:
			seinShape.move(-1, 0);
			break;
		}
		if (seinShape.getPosition().x > ventanita.getSize().x ||
			seinShape.getPosition().x < 0 ||
			seinShape.getPosition().y > ventanita.getSize().y ||
			seinShape.getPosition().y < 0) {
			seinShape.setPosition(80, 80);
			thrown = false;
		}
	}
}
void Rock::SetThrown(bool tirado){
	thrown = tirado;
}
void Rock::SetLook(int observado){
	look = observado;
}
bool Rock::GetThrown(){
	return thrown;
}
int Rock::GetLook(){
	return look;
}
sf::RectangleShape& Rock::GetShape(){
	seinShape.setFillColor(sf::Color::Magenta);
	return seinShape;
}