#include "Radroach.h"

Radroach::Radroach():EnemyBase(){
}
Radroach::Radroach(sf::RectangleShape rectangulo, int vida, float tiempo):EnemyBase(rectangulo, vida, tiempo){
}
Radroach::~Radroach(){
}
void Radroach::Attack(sf::Time cuento, PlayerP* niña){
	if (enemyTime <= 4) {
		enemyTime += cuento.asSeconds();
	}
	else if (enemyTime > 4){
		enemyTime = 0;
	}
	if (niña->GetShape().getPosition() != enemyShape.getPosition()){
		if (enemyTime <= 2) {
			if (niña->GetShape().getPosition().x > enemyShape.getPosition().x) {
				enemyShape.move(0.3, 0);
			}
			else if (niña->GetShape().getPosition().x < enemyShape.getPosition().x) {
				enemyShape.move(-0.3, 0);
			}
		}
		else if (enemyTime > 2 && enemyTime <= 4){
			if (niña->GetShape().getPosition().y > enemyShape.getPosition().y) {
				enemyShape.move(0, 0.3);
			}
			else if (niña->GetShape().getPosition().y < enemyShape.getPosition().y) {
				enemyShape.move(0, -0.3);
			}
		}
	}
}