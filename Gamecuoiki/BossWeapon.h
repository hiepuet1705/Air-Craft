#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Enemy.h"
class BossWeapon 
{
private:
	sf::Sprite sprite;
	bool Exist;

	//Animation
	sf::IntRect rectSprite;
	sf::Clock clockAnimation;

	//SPEED
	float speedMovement_x;
	float speedMovement_y;
	void initSprite();
	
public:
	const int& getDamage() const;
	BossWeapon(sf::Texture *texture, float x, float y);
	~BossWeapon();
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBound() const;
	const bool canAttack() ;
	void updateAttack();
	void updateMovement();
	void updateAnimation();
	void update();
	void render(sf::RenderTarget* target);
};

