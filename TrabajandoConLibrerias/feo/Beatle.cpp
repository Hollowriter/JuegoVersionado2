#include "Beatle.h"

Beatle::Beatle():EnemyBase(){
}
Beatle::Beatle(sf::RectangleShape rectangulo, int vida, float tiempo):EnemyBase(rectangulo, vida, tiempo){
}
Beatle::~Beatle(){
}
void Beatle::Attack(sf::Time cuento, PlayerP* ni�a){
	if (!Death()) {
		if (ni�a->GetShape().getPosition().x > enemyShape.getPosition().x) {
			enemyShape.move(0.2, 0);
		}
		else if (ni�a->GetShape().getPosition().x < enemyShape.getPosition().x) {
			enemyShape.move(-0.2, 0);
		}
		if (ni�a->GetShape().getPosition().y > enemyShape.getPosition().y) {
			enemyShape.move(0, 0.2);
		}
		else if (ni�a->GetShape().getPosition().y < enemyShape.getPosition().y) {
			enemyShape.move(0, -0.2);
		}
	}
}