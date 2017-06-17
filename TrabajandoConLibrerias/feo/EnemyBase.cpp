#include "EnemyBase.h"

EnemyBase::EnemyBase()
:
health(basicHealth),
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
		enemyShape.setPosition(ditchedOutPosition, ditchedOutPosition);
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
void EnemyBase::CollideRock(Rock* piedra) {
	if (!Death()) {
		if (piedra != NULL) {
			if (piedra->GetShape().getGlobalBounds().intersects(enemyShape.getGlobalBounds())) {
				SetHealth(GetHealth() - GetHealth());
				piedra->GetShape().setPosition(ditchedOutPosition, ditchedOutPosition);
				piedra->SetThrown(false);
			}
		}
	}
}
void EnemyBase::Positioning(PlayerP* amenaza){
	thyPosition = rand() % positionLottery;
	if (thyPosition != amenaza->GetShape().getPosition().x && thyPosition != amenaza->GetShape().getPosition().y){
		if (amenaza->GetShape().getPosition().x > thyPosition) {
			enemyShape.setPosition(thyPosition + playerAway, thyPosition);
		}
		else if (amenaza->GetShape().getPosition().x < thyPosition) {
			enemyShape.setPosition(thyPosition - playerAway, thyPosition);
		}
		if (amenaza->GetShape().getPosition().y > thyPosition) {
			enemyShape.setPosition(thyPosition, thyPosition + playerAway);
		}
		else if (amenaza->GetShape().getPosition().y < thyPosition) {
			enemyShape.setPosition(thyPosition, thyPosition - playerAway);
		}
	}
}
sf::RectangleShape EnemyBase::GetShape() {
	enemyShape.setFillColor(sf::Color::Black);
	return enemyShape;
}