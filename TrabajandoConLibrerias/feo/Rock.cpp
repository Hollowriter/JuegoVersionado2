#include "Rock.h"

Rock::Rock()
:
look(0),
thrown(false),
seinShape(sf::Vector2f(10, 10)){
	seinShape.setPosition(ditchedOutPosition, ditchedOutPosition);
}
Rock::~Rock(){
}
void Rock::Path(sf::RenderWindow &ventanita){
	if (thrown == true) {
		switch (look) {
		case 0:
			seinShape.move(0, -speedMovement);
			break;
		case 1:
			seinShape.move(speedMovement, 0);
			break;
		case 2:
			seinShape.move(0, speedMovement);
			break;
		case 3:
			seinShape.move(-speedMovement, 0);
			break;
		}
		if (seinShape.getPosition().x > ventanita.getSize().x ||
			seinShape.getPosition().x < 0 ||
			seinShape.getPosition().y > ventanita.getSize().y ||
			seinShape.getPosition().y < 0) {
			seinShape.setPosition(ditchedOutPosition, ditchedOutPosition);
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
/*void Rock::CollideEnemy(EnemyBase* blanco){
	blanco->SetHealth(blanco->GetHealth() - blanco->GetHealth());
	thrown = false;
	seinShape.setPosition(1000, 1000);
}*/
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