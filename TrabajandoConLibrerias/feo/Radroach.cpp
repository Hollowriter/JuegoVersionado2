#include "Radroach.h"

Radroach::Radroach():EnemyBase(){
	thyTexture.loadFromFile("cucarachita.png");
	rectSourceSprite.contains(32, 32);
	seinSprite.setTexture(thyTexture);
	seinSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}
Radroach::Radroach(int vida, float tiempo):EnemyBase(vida, tiempo){
	thyTexture.loadFromFile("cucarachita.png");
	rectSourceSprite.contains(32, 32);
	seinSprite.setTexture(thyTexture);
	seinSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}
Radroach::~Radroach(){
}
void Radroach::Attack(sf::Time cuento, PlayerP* ni�a){
	if (!Death()) {
		if (enemyTime <= internalTimer) {
			enemyTime += cuento.asSeconds();
		}
		else if (enemyTime > internalTimer) {
			enemyTime = 0;
		}
		if (ni�a->GetShape().getPosition() != seinSprite.getPosition()) {
			if (enemyTime <= subTimer) {
				if (ni�a->GetShape().getPosition().x > seinSprite.getPosition().x) {
					seinSprite.move(speedMovement * cuento.asSeconds(), 0);
				}
				else if (ni�a->GetShape().getPosition().x < seinSprite.getPosition().x) {
					seinSprite.move(-speedMovement * cuento.asSeconds(), 0);
				}
			}
			else if (enemyTime > subTimer && enemyTime <= internalTimer) {
				if (ni�a->GetShape().getPosition().y > seinSprite.getPosition().y) {
					seinSprite.move(0, speedMovement * cuento.asSeconds());
				}
				else if (ni�a->GetShape().getPosition().y < seinSprite.getPosition().y) {
					seinSprite.move(0, -speedMovement * cuento.asSeconds());
				}
			}
		}
	}
}