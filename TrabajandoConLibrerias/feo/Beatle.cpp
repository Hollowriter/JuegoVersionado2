#include "Beatle.h"

Beatle::Beatle():EnemyBase(){
	thyTexture.loadFromFile("Assets\cascarudo.png");
	rectSourceSprite.contains(32, 32);
	seinSprite.setTexture(thyTexture);
	seinSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}
Beatle::Beatle(int vida, float tiempo):EnemyBase(vida, tiempo){
	thyTexture.loadFromFile("Assets\cascarudo.png");
	rectSourceSprite.contains(32, 32);
	seinSprite.setTexture(thyTexture);
	seinSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}
Beatle::~Beatle(){
}
void Beatle::Attack(sf::Time cuento, PlayerP* ni�a){
	if (!Death()) {
		if (ni�a->GetShape().getPosition().x > seinSprite.getPosition().x) {
			seinSprite.move(speedMovement * cuento.asSeconds(), 0);
		}
		else if (ni�a->GetShape().getPosition().x < seinSprite.getPosition().x) {
			seinSprite.move(-speedMovement * cuento.asSeconds(), 0);
		}
		if (ni�a->GetShape().getPosition().y > seinSprite.getPosition().y) {
			seinSprite.move(0, speedMovement * cuento.asSeconds());
		}
		else if (ni�a->GetShape().getPosition().y < seinSprite.getPosition().y) {
			seinSprite.move(0, -speedMovement * cuento.asSeconds());
		}
	}
}