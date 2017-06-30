#include "EnemyBase.h"

EnemyBase::EnemyBase()
:
health(basicHealth),
thyTexture(),
enemyTime(0){
	thyTexture.loadFromFile("Assets/piedrita.png");
	rectSourceSprite.contains(32, 32);
	seinSprite.setTexture(thyTexture);
	seinSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	sonido.loadFromFile("Assets/Squish.wav");
	sonidito.setBuffer(sonido);
}
EnemyBase::EnemyBase(int vida, float tiempo)
:
health(vida),
thyTexture(),
enemyTime(tiempo){
	thyTexture.loadFromFile("Assets/piedrita.png");
	rectSourceSprite.contains(32, 32);
	seinSprite.setTexture(thyTexture);
	seinSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	sonido.loadFromFile("Assets/Squish.wav");
	sonidito.setBuffer(sonido);
}
EnemyBase::~EnemyBase(){
}
void EnemyBase::Attack(sf::Time cuento, PlayerP* niña){
}
void EnemyBase::Draw(sf::RenderWindow &ventana) {
	ventana.draw(seinSprite);
}
bool EnemyBase::Death(){
	if (health <= 0) {
		return true;
	}
	return false;
}
void EnemyBase::AfterLife(PlayerP* asesino){
	if (Death()) {
		health = basicHealth;
		this->Positioning(asesino);
	}
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
			if (piedra->GetShape().getGlobalBounds().intersects(seinSprite.getGlobalBounds())) {
				SetHealth(GetHealth() - GetHealth());
				piedra->GetShape().setPosition(ditchedOutPosition, ditchedOutPosition);
				piedra->SetThrown(false);
				sonidito.play();
			}
		}
	}
}
void EnemyBase::Positioning(PlayerP* amenaza){
	thyPosition = rand() % positionLottery;
	if (thyPosition != amenaza->GetShape().getPosition().x && thyPosition != amenaza->GetShape().getPosition().y){
		if (amenaza->GetShape().getPosition().x > thyPosition) {
			seinSprite.setPosition(thyPosition + playerAway, thyPosition);
		}
		else if (amenaza->GetShape().getPosition().x < thyPosition) {
			seinSprite.setPosition(thyPosition - playerAway, thyPosition);
		}
		if (amenaza->GetShape().getPosition().y > thyPosition) {
			seinSprite.setPosition(thyPosition, thyPosition + playerAway);
		}
		else if (amenaza->GetShape().getPosition().y < thyPosition) {
			seinSprite.setPosition(thyPosition, thyPosition - playerAway);
		}
	}
}
sf::Sprite& EnemyBase::GetShape() {
	return seinSprite;
}
sf::IntRect EnemyBase::GetRect() {
	return rectSourceSprite;
}