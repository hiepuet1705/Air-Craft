#include "Boom.h"

Boom::Boom(sf::Texture* texture)
{
	this->spriteBoom.setTexture(*texture);

}

Boom::~Boom()
{
}

void Boom::setPos(sf::Vector2f pos)
{
	this->spriteBoom.setPosition(pos);
}

void Boom::render(sf::RenderWindow* window)
{
	window->draw(this->spriteBoom);
}
