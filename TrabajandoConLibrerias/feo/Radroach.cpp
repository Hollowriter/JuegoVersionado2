#include "Radroach.h"

Radroach::Radroach():EnemyBase(){
}
Radroach::Radroach(sf::RectangleShape rectangulo, int vida, float tiempo):EnemyBase(rectangulo, vida, tiempo){
}
Radroach::~Radroach(){
}
void Radroach::Attack(sf::Time cuento, PlayerP* ni�a){
	if (enemyTime <= 4) {
		enemyTime += cuento.asSeconds();
	}
	else if (enemyTime > 4){
		enemyTime = 0;
	}
	if (ni�a->GetShape().getPosition() != enemyShape.getPosition()){
		if (enemyTime <= 2) {
			if (ni�a->GetShape().getPosition().x > enemyShape.getPosition().x) {
				enemyShape.move(0.3, 0);
			}
			else if (ni�a->GetShape().getPosition().x < enemyShape.getPosition().x) {
				enemyShape.move(-0.3, 0);
			}
		}
		else if (enemyTime > 2 && enemyTime <= 4){
			if (ni�a->GetShape().getPosition().y > enemyShape.getPosition().y) {
				enemyShape.move(0, 0.3);
			}
			else if (ni�a->GetShape().getPosition().y < enemyShape.getPosition().y) {
				enemyShape.move(0, -0.3);
			}
		}
	}
}