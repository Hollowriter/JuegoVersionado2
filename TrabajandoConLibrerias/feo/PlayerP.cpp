#include"PlayerP.h"

PlayerP::PlayerP()
:
health(100),
bullets(30),
score(0),
thyShape(100.0f){
}
PlayerP::PlayerP(int vida, int balas, int puntos, sf::CircleShape circulo)
	:
	health(vida),
	bullets(balas),
	score(puntos),
	thyShape(circulo) {
}
void PlayerP::Move(sf::Time cuento) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		thyShape.move(-(cuento.asSeconds() * 1000), 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		thyShape.move(cuento.asSeconds() * 1000, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		thyShape.move(0, -(cuento.asSeconds() * 1000));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		thyShape.move(0, cuento.asSeconds() * 1000);
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
sf::CircleShape PlayerP::GetShape(){
	thyShape.setFillColor(sf::Color::Green);
	return thyShape;
}