#include "Radroach.h"

Radroach::Radroach():EnemyBase(){
}
Radroach::Radroach(sf::RectangleShape rectangulo, int vida):EnemyBase(rectangulo, vida){
}
Radroach::~Radroach(){
}
void Radroach::Attack(sf::Time cuento, PlayerP* ni�a){
	enemyTime += cuento.asMicroseconds();
	if (ni�a->GetShape().getPosition() != enemyShape.getPosition()){
		if (enemyTime <= 10) {
			if (ni�a->GetShape().getPosition().x > enemyShape.getPosition().x) {
				enemyShape.move(2, 0);
			}
			else if (ni�a->GetShape().getPosition().x < enemyShape.getPosition().x) {
				enemyShape.move(-2, 0);
			}
		}
		else if (enemyTime > 10 && enemyTime <= 20){
			if (ni�a->GetShape().getPosition().y > enemyShape.getPosition().y) {
				enemyShape.move(0, 2);
			}
			else if (ni�a->GetShape().getPosition().y < enemyShape.getPosition().y) {
				enemyShape.move(0, -2);
			}
		}
	}
}