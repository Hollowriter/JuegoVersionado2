#include"PlayerP.h"

PlayerP::PlayerP()
:
health(100),
bullets(30),
score(0),
thyShape(sf::Vector2f(70, 70)){
	thyShape.setPosition(100, 100);
}
PlayerP::PlayerP(int vida, int balas, int puntos, sf::RectangleShape rectangular)
	:
	health(vida),
	bullets(balas),
	score(puntos),
	thyShape(rectangular) {
	thyShape.setPosition(100, 100);
}
void PlayerP::Move(sf::Time cuento) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		thyShape.move(-(cuento.asSeconds() * 750), 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		thyShape.move(cuento.asSeconds() * 750, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		thyShape.move(0, -(cuento.asSeconds() * 750));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
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
int PlayerP::GetHealth(){
	return health;
}
int PlayerP::GetBullets(){
	return bullets;
}
int PlayerP::GetScore(){
	return score;
}
sf::RectangleShape PlayerP::GetShape(){
	thyShape.setFillColor(sf::Color::Green);
	return thyShape;
}