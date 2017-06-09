#include "Radroach.h"

Radroach::Radroach():EnemyBase(){
}
Radroach::Radroach(sf::RectangleShape rectangulo, int vida):EnemyBase(rectangulo, vida){
}
Radroach::~Radroach(){
}
void Radroach::Attack(sf::Time cuento, PlayerP* niña){
	enemyTime += cuento.asMicroseconds();
	if (niña->GetShape().getPosition() != enemyShape.getPosition()){
		if (enemyTime <= 10) {
			if (niña->GetShape().getPosition().x > enemyShape.getPosition().x) {
				enemyShape.move(2, 0);
			}
			else if (niña->GetShape().getPosition().x < enemyShape.getPosition().x) {
				enemyShape.move(-2, 0);
			}
		}
		else if (enemyTime > 10 && enemyTime <= 20){
			if (niña->GetShape().getPosition().y > enemyShape.getPosition().y) {
				enemyShape.move(0, 2);
			}
			else if (niña->GetShape().getPosition().y < enemyShape.getPosition().y) {
				enemyShape.move(0, -2);
			}
		}
	}
}