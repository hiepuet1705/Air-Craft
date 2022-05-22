#include "BossDeath.h"

void BossDeath::initBoom(sf::Vector2f pos)
{
	
}

BossDeath::BossDeath()
{
	this->rectDeath.left = 0;
	this->rectDeath.top = 0;
	this->rectDeath.width = 274;
	this->rectDeath.height = 325;

	this->imageDeath.loadFromFile("Textures/bossdeath.png");
	this->imageDeath.createMaskFromColor(sf::Color(170, 170, 170));
	this->textureDeath.loadFromImage(this->imageDeath);

	this->spriteDeath.setTexture(this->textureDeath);
	this->spriteDeath.setTextureRect(this->rectDeath);
	this->spriteDeath.scale(1.2f, 1.2f);

}

BossDeath::~BossDeath()
{
}

const sf::Vector2u BossDeath::getSize() const
{
	return this->textureDeath.getSize();
}

const sf::FloatRect BossDeath::getBounds() const
{
	return this->spriteDeath.getGlobalBounds();
}

const sf::Vector2f& BossDeath::getPos() const
{
	return this->spriteDeath.getPosition();
}

void BossDeath::updateAnimation()
{
	if (this->clockAnimationDeath.getElapsedTime().asSeconds() > 0.15f && this->rectDeath.left < 2200 - 275)
	{
		//if (this->rectDeath.left >= 1925 - 275) this->rectDeath.left = 0;
		//else 
			this->rectDeath.left += 275;
		this->spriteDeath.setTextureRect(this->rectDeath);
		this->clockAnimationDeath.restart();
	}
}

void BossDeath::update(sf::Vector2f pos)
{
	this->updateAnimation();
	this->spriteDeath.setPosition(pos);
}

void BossDeath::render(sf::RenderTarget* target)
{
	target->draw(this->spriteDeath);
}
