#include"PlayerP.h"

PlayerP::PlayerP()
:
health(100),
bullets(30),
score(0),
direction(0),
thyShape(sf::Vector2f(70, 70)){
	thyShape.setPosition(100, 100);
}
PlayerP::PlayerP(int vida, int balas, int puntos, int direccion, sf::RectangleShape rectangular)
	:
	health(vida),
	bullets(balas),
	score(puntos),
	direction(direccion),
	thyShape(rectangular){
	thyShape.setPosition(100, 100);
}
void PlayerP::Move(sf::Time cuento) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		direction = 3;
		thyShape.move(-(cuento.asSeconds() * 750), 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		direction = 1;
		thyShape.move(cuento.asSeconds() * 750, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		direction = 0;
		thyShape.move(0, -(cuento.asSeconds() * 750));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		direction = 2;
		thyShape.move(0, cuento.asSeconds() * 750);
	}
}
bool PlayerP::Death() {
	if (health <= 0) {
		return true;
	}
	return false;
}
void PlayerP::Draw(sf::RenderWindow &ventana){
	ventana.draw(thyShape);
}
void PlayerP::SetHealth(int vida){
	health = vida;
}
void PlayerP::SetBullets(int balas){
	bullets = balas;
}
void PlayerP::SetScore(int puntos){
	score = puntos;
}
void PlayerP::SetDirection(int direccion){
	direction = direccion;
}
void PlayerP::Throwing(Rock* piedra){
	if (piedra != NULL){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
			if (piedra->GetThrown() == false) {
				piedra->GetShape().setPosition(thyShape.getPosition());
				piedra->SetLook(direction);
				piedra->SetThrown(true);
			}
		}
	}
}
int PlayerP::GetHealth(){
	return health;
}
int PlayerP::GetBullets(){
	return bullets;
}
int PlayerP::GetScore(){
	return score;
}
int PlayerP::GetDirection(){
	return direction;
}
sf::RectangleShape PlayerP::GetShape(){
	thyShape.setFillColor(sf::Color::Green);
	return thyShape;
}