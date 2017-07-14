#include"PlayerP.h"

PlayerP::PlayerP()
:
health(startingHealth),
score(0),
direction(0),
thyTexture(),
seinSprite(){
	thyTexture.loadFromFile("Assets/Myomi.png");
	rectSourceSprite.contains(spriteX, spriteY);
	seinSprite.setTexture(thyTexture);
	seinSprite.setTextureRect(sf::IntRect(0, 0, spriteX, spriteY));
}
PlayerP::PlayerP(int vida, int puntos, int direccion, sf::RectangleShape rectangular)
	:
	health(vida),
	score(puntos),
	direction(direccion),
	thyTexture(){
	thyTexture.loadFromFile("Assets/Myomi.png");
	rectSourceSprite.contains(spriteX, spriteY);
	seinSprite.setTexture(thyTexture);
	seinSprite.setTextureRect(sf::IntRect(0, 0, spriteX, spriteY));
}
void PlayerP::Move(sf::Time cuento) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		direction = 3;
		seinSprite.move(-(cuento.asSeconds() * velocity), 0);
		seinSprite.setTextureRect(sf::IntRect(anim1, 0, spriteX, spriteY));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		direction = 1;
		seinSprite.move(cuento.asSeconds() * velocity, 0);
		seinSprite.setTextureRect(sf::IntRect(0, 0, spriteX, spriteY));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		direction = 0;
		seinSprite.move(0, -(cuento.asSeconds() * velocity));
		seinSprite.setTextureRect(sf::IntRect(anim4, anim2, spriteX, spriteY));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		direction = 2;
		seinSprite.move(0, cuento.asSeconds() * velocity);
		seinSprite.setTextureRect(sf::IntRect(0, anim2, spriteX, spriteY));
	}
}
const bool PlayerP::Death() {
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
const int PlayerP::GetHealth(){
	return health;
}
const int PlayerP::GetScore(){
	return score;
}
const int PlayerP::GetDirection(){
	return direction;
}
const sf::Sprite PlayerP::GetShape(){
	return seinSprite;
}
const sf::IntRect PlayerP::GetRect(){
	return rectSourceSprite;
}