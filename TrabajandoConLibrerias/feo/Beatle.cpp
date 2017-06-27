#include "Beatle.h"

Beatle::Beatle():EnemyBase(){
}
Beatle::Beatle(sf::RectangleShape rectangulo, int vida, float tiempo):EnemyBase(rectangulo, vida, tiempo){
}
Beatle::~Beatle(){
}
void Beatle::Attack(sf::Time cuento, PlayerP* niña){
	if (!Death()) {
		if (niña->GetShape().getPosition().x > enemyShape.getPosition().x) {
			enemyShape.move(speedMovement * cuento.asSeconds(), 0);
		}
		else if (niña->GetShape().getPosition().x < enemyShape.getPosition().x) {
			enemyShape.move(-speedMovement * cuento.asSeconds(), 0);
		}
		if (niña->GetShape().getPosition().y > enemyShape.getPosition().y) {
			enemyShape.move(0, speedMovement * cuento.asSeconds());
		}
		else if (niña->GetShape().getPosition().y < enemyShape.getPosition().y) {
			enemyShape.move(0, -speedMovement * cuento.asSeconds());
		}
	}
}