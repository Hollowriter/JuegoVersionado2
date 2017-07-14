#include "Rock.h"

Rock::Rock()
:
look(0),
thrown(false),
thyTexture(),
seinSprite(){
	thyTexture.loadFromFile("Assets/piedrita.png");
	rectSourceSprite.contains(32, 32);
	seinSprite.setTexture(thyTexture);
	seinSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	seinSprite.setPosition(ditchedOutPosition, ditchedOutPosition);
}
Rock::~Rock(){
}
void Rock::Path(sf::RenderWindow &ventanita, sf::Time cuento){
	if (thrown == true) {
		switch (look) {
		case 0:
			seinSprite.move(0, -speedMovement * cuento.asSeconds());
			break;
		case 1:
			seinSprite.move(speedMovement * cuento.asSeconds(), 0);
			break;
		case 2:
			seinSprite.move(0, speedMovement * cuento.asSeconds());
			break;
		case 3:
			seinSprite.move(-speedMovement * cuento.asSeconds(), 0);
			break;
		}
		if (seinSprite.getPosition().x > ventanita.getSize().x ||
			seinSprite.getPosition().x < 0 ||
			seinSprite.getPosition().y > ventanita.getSize().y ||
			seinSprite.getPosition().y < 0) {
			seinSprite.setPosition(ditchedOutPosition, ditchedOutPosition);
			thrown = false;
		}
	}
}
void Rock::SetThrown(bool tirado){
	thrown = tirado;
}
void Rock::SetLook(int observado){
	look = observado;
}
const bool Rock::GetThrown(){
	return thrown;
}
const int Rock::GetLook(){
	return look;
}
sf::Sprite& Rock::GetShape(){
	return seinSprite;
}
const sf::IntRect Rock::GetRect(){
	return rectSourceSprite;
}