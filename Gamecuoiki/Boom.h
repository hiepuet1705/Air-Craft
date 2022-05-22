#pragma once
#include<SFML/Graphics.hpp>
class Boom
{
private:
	sf::Sprite spriteBoom;

public:
	Boom(sf::Texture *texture);
	virtual ~Boom();
	void setPos(sf::Vector2f pos);
	void render(sf::RenderWindow* window);
};

