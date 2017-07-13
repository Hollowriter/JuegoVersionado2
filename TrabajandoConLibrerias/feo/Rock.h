#pragma once
#ifndef ROCK_H
#define ROCK_H

#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
class Rock{
private:
	const int ditchedOutPosition = 1000;
	const float speedMovement = 300.0f;
	int look;
	bool thrown;
	sf::Texture thyTexture;
	sf::IntRect rectSourceSprite;
	sf::Sprite seinSprite;
public:
	Rock();
	~Rock();
	void Path(sf::RenderWindow &ventanita, sf::Time cuento);
	void SetThrown(bool tirado);
	void SetLook(int observado);
	bool GetThrown();
	int GetLook();
	sf::Sprite& GetShape();
	sf::IntRect GetRect();
};

#endif