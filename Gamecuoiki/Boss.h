#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

class Boss
{
private:
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	const float HP_MAX = 400.f;
	float hp = HP_MAX;

	//Animation
	sf::IntRect rectSprite;
	sf::Clock clockAnimation;

	//BOOM
	

	bool dead = false;

	//Moverment
	float speedMovement_x;
	float speedMovement_y;
	float upMax;
	// can Attack
	float attackCooldown;
	float attackCooldownMax;

	void initSprite();
	void initMovement();

public:
	Boss();
	virtual ~Boss();

	const sf::Vector2u getSize() const;
	const sf::FloatRect getBounds() const;
	const sf::Vector2f& getPos() const;
	const float getHp() const;
	const bool isDead() const;

	void getDamge(float damage);

	void setBossDead();

	void updateMovement();
	void updateAnimation();
	const bool canAttack();
	void updateAttack();
	void update();

	void render(sf::RenderTarget* target);




};