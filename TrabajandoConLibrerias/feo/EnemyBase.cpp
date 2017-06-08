#include "EnemyBase.h"

EnemyBase::EnemyBase()
:
health(0),
enemyShape(sf::Vector2f(100, 100)){
}
EnemyBase::EnemyBase(sf::RectangleShape rectangulo, int vida)
:
health(vida),
enemyShape(rectangulo) {
}
EnemyBase::~EnemyBase(){
}
void EnemyBase::Attack(sf::Time cuento, sf::Clock reloj, PlayerP* niña){
}
void EnemyBase::Draw(sf::RenderWindow &ventana) {
	ventana.draw(enemyShape);
}
bool EnemyBase::Death(){
	if (health <= 0) {
		return true;
	}
	return false;
}
void EnemyBase::SetHealth(int vida) {
	health = vida;
}
int EnemyBase::GetHealth() {
	return health;
}
sf::RectangleShape EnemyBase::GetShape() {
	enemyShape.setFillColor(sf::Color::Black);
	return enemyShape;
}