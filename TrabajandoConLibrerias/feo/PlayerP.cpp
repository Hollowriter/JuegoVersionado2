#include"PlayerP.h"

PlayerP::PlayerP()
:
health(startingHealth),
score(0),
direction(0),
thyTexture(){
	thyTexture.loadFromFile("Myomi.png");
	rectSourceSprite.contains(23, 32);
	seinSprite.setTexture(thyTexture);
	seinSprite.setTextureRect(sf::IntRect(0, 0, 23, 32));
}
PlayerP::PlayerP(int vida, int puntos, int direccion, sf::RectangleShape rectangular)
	:
	health(vida),
	score(puntos),
	direction(direccion),
	thyTexture(){
	thyTexture.loadFromFile("Myomi.png");
	rectSourceSprite.contains(23, 32);
	seinSprite.setTexture(thyTexture);
	seinSprite.setTextureRect(sf::IntRect(0, 0, 23, 32));
}
void PlayerP::Move(sf::Time cuento) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		direction = 3;
		seinSprite.move(-(cuento.asSeconds() * velocity), 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		direction = 1;
		seinSprite.move(cuento.asSeconds() * velocity, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		direction = 0;
		seinSprite.move(0, -(cuento.asSeconds() * velocity));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		direction = 2;
		seinSprite.move(0, cuento.asSeconds() * velocity);
	}
}
bool PlayerP::Death() {
	if (health <= 0) {
		return true;
	}
	return false;
}
void PlayerP::Draw(sf::RenderWindow &ventana){
	ventana.draw(seinSprite);
}
void PlayerP::SetHealth(int vida){
	health = vida;
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
				piedra->GetShape().setPosition(seinSprite.getPosition());
				piedra->SetLook(direction);
				piedra->SetThrown(true);
			}
		}
	}
}
int PlayerP::GetHealth(){
	return health;
}
int PlayerP::GetScore(){
	return score;
}
int PlayerP::GetDirection(){
	return direction;
}
sf::Sprite PlayerP::GetShape(){
	return seinSprite;
}
sf::IntRect PlayerP::GetRect(){
	return rectSourceSprite;
}