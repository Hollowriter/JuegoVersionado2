#pragma once
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
class Rock
{
private:
	int look;
	bool thrown;
	sf::RectangleShape seinShape;
public:
	Rock();
	~Rock();
	void Path(sf::RenderWindow &ventanita);
	void SetThrown(bool tirado);
	void SetLook(int observado);
	bool GetThrown();
	int GetLook();
	sf::RectangleShape& GetShape();
};

