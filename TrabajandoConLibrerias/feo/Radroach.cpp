#include "Radroach.h"

Radroach::Radroach():EnemyBase(){
}
Radroach::Radroach(sf::RectangleShape rectangulo, int vida, float tiempo):EnemyBase(rectangulo, vida, tiempo){
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
		if (ni�a->GetShape().getPosition() != enemyShape.getPosition()) {
			if (enemyTime <= subTimer) {
				if (ni�a->GetShape().getPosition().x > enemyShape.getPosition().x) {
					enemyShape.move(speedMovement, 0);
				}
				else if (ni�a->GetShape().getPosition().x < enemyShape.getPosition().x) {
					enemyShape.move(-speedMovement, 0);
				}
			}
			else if (enemyTime > subTimer && enemyTime <= internalTimer) {
				if (ni�a->GetShape().getPosition().y > enemyShape.getPosition().y) {
					enemyShape.move(0, speedMovement);
				}
				else if (ni�a->GetShape().getPosition().y < enemyShape.getPosition().y) {
					enemyShape.move(0, -speedMovement);
				}
			}
		}
	}
}