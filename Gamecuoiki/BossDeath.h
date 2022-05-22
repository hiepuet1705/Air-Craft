#pragma once
#include<SFML/Graphics.hpp>
class BossDeath
{
private:
	sf::Image imageDeath;
	sf::Texture textureDeath;
	sf::Sprite spriteDeath;
	sf::Clock clockAnimationDeath;
	sf::IntRect rectDeath;
	void initBoom(sf::Vector2f);
public:
	BossDeath();
	virtual ~BossDeath();
	const sf::Vector2u getSize() const;
	const sf::FloatRect getBounds() const;
	const sf::Vector2f& getPos() const;
	sf::IntRect getRect() {
		return this->rectDeath;
	}

	void setRectLeft(const int& left) { this->rectDeath.left = left; };
	void updateAnimation();
	void update(sf::Vector2f pos);
	void render(sf::RenderTarget* target);

};

