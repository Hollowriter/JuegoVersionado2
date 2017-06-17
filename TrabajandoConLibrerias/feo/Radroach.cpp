#include "Radroach.h"

Radroach::Radroach():EnemyBase(){
}
Radroach::Radroach(sf::RectangleShape rectangulo, int vida, float tiempo):EnemyBase(rectangulo, vida, tiempo){
}
Radroach::~Radroach(){
}
void Radroach::Attack(sf::Time cuento, PlayerP* niña){
	if (!Death()) {
		if (enemyTime <= internalTimer) {
			enemyTime += cuento.asSeconds();
		}
		else if (enemyTime > internalTimer) {
			enemyTime = 0;
		}
		if (niña->GetShape().getPosition() != enemyShape.getPosition()) {
			if (enemyTime <= subTimer) {
				if (niña->GetShape().getPosition().x > enemyShape.getPosition().x) {
					enemyShape.move(speedMovement, 0);
				}
				else if (niña->GetShape().getPosition().x < enemyShape.getPosition().x) {
					enemyShape.move(-speedMovement, 0);
				}
			}
			else if (enemyTime > subTimer && enemyTime <= internalTimer) {
				if (niña->GetShape().getPosition().y > enemyShape.getPosition().y) {
					enemyShape.move(0, speedMovement);
				}
				else if (niña->GetShape().getPosition().y < enemyShape.getPosition().y) {
					enemyShape.move(0, -speedMovement);
				}
			}
		}
	}
}