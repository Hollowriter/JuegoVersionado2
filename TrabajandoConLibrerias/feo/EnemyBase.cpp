#include "EnemyBase.h"

EnemyBase::EnemyBase()
:
health(20),
enemyShape(sf::Vector2f(50, 50)),
enemyTime(0){
}
EnemyBase::EnemyBase(sf::RectangleShape rectangulo, int vida, float tiempo)
:
health(vida),
enemyShape(rectangulo),
enemyTime(tiempo){
}
EnemyBase::~EnemyBase(){
}
void EnemyBase::Attack(sf::Time cuento, PlayerP* niña){
}
void EnemyBase::Draw(sf::RenderWindow &ventana) {
	ventana.draw(enemyShape);
}
bool EnemyBase::Death(){
	if (health <= 0) {
		enemyShape.setPosition(1000, 1000);
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
void EnemyBase::SetEnemyTime(float timing) {
	enemyTime = timing;
}
float EnemyBase::GetEnemyTime() {
	return enemyTime;
}
sf::RectangleShape EnemyBase::GetShape() {
	enemyShape.setFillColor(sf::Color::Black);
	return enemyShape;
}