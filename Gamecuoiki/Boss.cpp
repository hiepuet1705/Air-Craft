#include "Boss.h"

//#include <cmath>

void Boss::initSprite()
{
	const int RECTSPRITE_LEFT = 0;
	const int RECTSPRITE_TOP = 0;
	const int RECTSPRITE_HEIGHT = 394;
	const int RECTSPRITE_WIDTH = 320;

	this->rectSprite.left = RECTSPRITE_LEFT;
	this->rectSprite.top = RECTSPRITE_TOP;
	this->rectSprite.height = RECTSPRITE_HEIGHT;
	this->rectSprite.width = RECTSPRITE_WIDTH;


	this->image.loadFromFile("Textures/boss1.png");
	this->image.createMaskFromColor(sf::Color(170, 170, 170));
	this->texture.loadFromImage(this->image);

	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(this->rectSprite);
	this->sprite.scale(1.2f, 1.2f);
	const sf::Vector2f posSprite(550, -150);
	this->sprite.setPosition(posSprite);

}

void Boss::initMovement()
{
	this->speedMovement_x = 0.f;
	this->speedMovement_y = 0.5f;
	this->upMax = -70;
}



Boss::Boss()
{
	this->initSprite();
	this->initMovement();
	this->dead = false;
	this->hp = this->HP_MAX;
	this->attackCooldown = 0.f;
	this->attackCooldownMax = 300.f;

}

Boss::~Boss()
{
}

const sf::Vector2u Boss::getSize() const
{
	return this->texture.getSize();
}
const sf::FloatRect Boss::getBounds() const
{
	return this->sprite.getGlobalBounds();
}
const sf::Vector2f& Boss::getPos() const
{
	return this->sprite.getPosition();
}
const float Boss::getHp() const
{
	return this->hp;
}
const bool Boss::isDead() const
{
	return this->dead;
}
void Boss::getDamge(float damage)
{
	this->hp -= damage;
}

void Boss::setBossDead()
{

	this->dead = true;

	

}


void Boss::updateMovement()
{
	if (this->sprite.getPosition().y >= this->upMax)
	{
		this->sprite.setPosition(this->sprite.getPosition().x,this->upMax);
	}
	
	this->sprite.move(this->speedMovement_x, this->speedMovement_y);
}

void Boss::updateAnimation()
{
	if (this->clockAnimation.getElapsedTime().asSeconds() > 0.1f)
	{
		if (this->rectSprite.left == 1920 - 320) {
			this->rectSprite.left = 0;
		}
		else {
			this->rectSprite.left += 320;
		}

		this->sprite.setTextureRect(this->rectSprite);
		this->clockAnimation.restart();
	}
}

void Boss::move(float x, float y)
{
	this->sprite.move(x, y);
}

const bool Boss::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax) {
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Boss::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 1.f;
}

void Boss::update()
{
	if (this->isDead() == false) {
		this->updateMovement();
		this->updateAnimation();
		this->updateAttack();
	}
}



void Boss::render(sf::RenderTarget* target)
{
	if (this->isDead() == false)
		target->draw(this->sprite);
}