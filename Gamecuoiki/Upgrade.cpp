#include "Upgrade.h"

void Upgrade::initSprite(float pos_x, float pos_y)
{
	this->rectSprite.left = 0;
	this->rectSprite.top = 0;
	this->rectSprite.height = 41;
	this->rectSprite.width = 1225 / 25;

	this->clockAnimation.restart();

	this->image.loadFromFile("Textures/power.png");
	this->image.createMaskFromColor(sf::Color(170, 170, 170));
	this->upgradeTexture.loadFromImage(this->image);
	this->upgradeSprite.setTexture(this->upgradeTexture);
	this->upgradeSprite.setTextureRect(this->rectSprite);
	this->upgradeSprite.setPosition(pos_x, pos_y);
}

Upgrade::Upgrade()
{
	this->initSprite(0.f, 0.f);
	//this->isExist = false;
	//this->timeAddNewUpgrade.restart();
	this->clockAnimation.restart();
}

Upgrade::~Upgrade()
{
}

const sf::Vector2f Upgrade::getPos() const
{
	return this->upgradeSprite.getPosition();
}

const sf::FloatRect Upgrade::getBounds() const
{
	return this->upgradeSprite.getGlobalBounds();
}

const bool Upgrade::isExistBulletPower() const
{
	return this->isExist;
}

void Upgrade::updateScale(float scale_x, float scale_y)
{
	this->upgradeSprite.scale(scale_x, scale_y);
}

void Upgrade::updatePos(float pos_x, float pos_y)
{
	this->upgradeSprite.setPosition(pos_x, pos_y);
}

void Upgrade::updateNewUpgrade()
{
		
}

void Upgrade::updateAnimation()
{
	
	
}


void Upgrade::updateMoverment()
{
	this->upgradeSprite.move(0.f, 2.f);
}

void Upgrade::update()
{
	
	//this->updateNewUpgrade();
	this->updateAnimation();
	this->updateMoverment();

}

void Upgrade::render(sf::RenderTarget* target)
{
		target->draw(this->upgradeSprite);
}