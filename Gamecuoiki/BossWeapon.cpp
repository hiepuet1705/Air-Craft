#include "BossWeapon.h"

void BossWeapon::initSprite()
{
	this->rectSprite.left = 0;
	this->rectSprite.top = 0;
	this->rectSprite.width = 28.f;
	this->rectSprite.height = 110.f;
	this->sprite.setTextureRect(this->rectSprite);
}

const int& BossWeapon::getDamage() const
{
	return 10;
}

BossWeapon::BossWeapon(sf::Texture *texture,float x,float y)
{
	this->sprite.setTexture(*texture);
	//this->initSprite();
	this->speedMovement_x = 0.f;
	this->speedMovement_y = 3.f;
	this->sprite.setPosition(x, y);
}

BossWeapon::~BossWeapon()
{
}

const sf::Vector2f& BossWeapon::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect BossWeapon::getBound() const
{
	return this->sprite.getGlobalBounds();
}


void BossWeapon::updateAttack()
{
}

void BossWeapon::updateMovement()
{
	this->sprite.move(this->speedMovement_x, this->speedMovement_y);
}


void BossWeapon::update()
{
	//this->updateAnimation();
	this->updateMovement();
}

void BossWeapon::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}


