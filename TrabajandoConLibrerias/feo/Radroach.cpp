#include "Radroach.h"

Radroach::Radroach():EnemyBase(){
}
Radroach::Radroach(sf::RectangleShape rectangulo, int vida):EnemyBase(rectangulo, vida){
}
Radroach::~Radroach(){
}
void Radroach::Attack(sf::Time cuento, sf::Clock reloj, PlayerP* ni�a){
	cuento = reloj.getElapsedTime();
	if (ni�a->GetShape().getPosition() != enemyShape.getPosition()){
		if (cuento.asSeconds() <= 10) {
			if (ni�a->GetShape().getPosition().x > 0) {
				enemyShape.move(cuento.asSeconds(), 0);
			}
			else if (ni�a->GetShape().getPosition().x < 0) {
				enemyShape.move(cuento.asSeconds() * (-1), 0);
			}
		}
		else if (cuento.asSeconds() > 10 && cuento.asSeconds() <= 20){
			if (ni�a->GetShape().getPosition().y > 0) {
				enemyShape.move(0, cuento.asSeconds());
			}
			else if (ni�a->GetShape().getPosition().y < 0) {
				enemyShape.move(0, cuento.asSeconds() * (-1));
			}
		}
		else{
			reloj.restart();
		}
	}
}