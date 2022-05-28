#include "Enemy.h"



void Enemy::initVariables()
{
	this->pointCount = rand() % 10 + 3; // 
	this->hpOfEnemies = this->pointCount;
	this->speed = static_cast<float>(0.5f+this->pointCount*2/5) ;
	this->hpMax = static_cast<int> (this->pointCount);
	this->hp = this->hpMax;
	this->Star = "";
	type["Textures/thienthach.png"] = 1;
	type["Textures/thienthach1.png"] = 2;
	type["Textures/thienthach2.png"] = 3;
	type["Textures/thienthach3.png"] = 4;
	type["Textures/thienthach4.png"] = 5;
	this->damage = this->pointCount;
	this->points = this->pointCount;
}
void Enemy::intShape()
{
	const static std::string fallingStars[] = { "Textures/thienthach.png","Textures/thienthach1.png" ,"Textures/thienthach2.png" ,
		"Textures/thienthach3.png" ,"Textures/thienthach4.png","Textures/thienthach5.png","Textures/thienthach.png","Textures/thienthach7.png" };
	this->Star = fallingStars[rand() % 8];
	if (!this->shapeTexture.loadFromFile(Star)) {
		std::cout << "Error";
	}
	
	this->shapeSprite.setTexture(this->shapeTexture);


}

Enemy::Enemy(float posX,float posY) {
	
	this->initVariables();
	this->intShape();
	this->shapeSprite.setPosition(posX, posY);
}
Enemy::~Enemy() {

}

const sf::FloatRect Enemy::getBounds() const
{
	return this->shapeSprite.getGlobalBounds();
}

void Enemy::update()
{
	if (type[Star] == 5) {
		
		this->damage = 10;
		this->shapeSprite.move(0.5f, 1 + this->speed * 2);
	} 
	else this->shapeSprite.move(0.f, this->speed);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shapeSprite);
}

const int& Enemy::getPoint() const
{
	// TODO: insert return statement here

	return this->points;
}

const int& Enemy::getDamage() const
{
	// TODO: insert return statement here
	return this->damage;
}

const int& Enemy::getHpOfEnemies() const
{
	return this->hpOfEnemies;
}

void Enemy::loseHp(const int value)
{
	this->hpOfEnemies -= value;
	if (this->hpOfEnemies <= 0) this->hpOfEnemies = 0;
}


void Enemy::setOrigin()
{
	this->shapeSprite.setOrigin(this->shapeSprite.getGlobalBounds().width / 2, this->shapeSprite.getGlobalBounds().width / 2);
}

sf::Vector2f Enemy::getPos()
{
	return sf::Vector2f(this->shapeSprite.getPosition().x ,this->shapeSprite.getPosition().y );
}
