#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
class Upgrade
{
private:
	sf::Image image;
	sf::Texture upgradeTexture;
	sf::Sprite upgradeSprite;


	bool isExist;
	sf::Clock timeAddNewUpgrade;
	//Animation

	sf::IntRect rectSprite;
	sf::Clock clockAnimation;

	void initSprite(float pos_x, float pos_y);
public:
	Upgrade();
	virtual  ~Upgrade();
	bool info = false;
	const sf::Vector2f getPos() const;
	const sf::FloatRect getBounds() const;
	const bool isExistBulletPower() const;
	void updateScale(float scale_x, float scale_y);
	void updatePos(float pos_x, float pos_y);


	void updateNewUpgrade();

	void updateAnimation();
	void updateMoverment();
	void update();

	void render(sf::RenderTarget* target);
	void updateBulletPowerDead();
};

