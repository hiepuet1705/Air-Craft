#ifndef ENEMY_H
#define ENEMY_H
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include<string>
#include<map>
class Enemy {
private:

	unsigned pointCount;
	sf::Texture shapeTexture;
	sf::Sprite shapeSprite;

	std::map<std::string, int> type;
	
	std::string Star;
	int hp;
	int hpOfEnemies;
	int hpMax;
	int damage;
	int points;
	float speed;
	


	void initVariables();
	void intShape();

	 

public:
	Enemy(float posX,float posY);
	virtual ~Enemy();
	const sf::FloatRect getBounds() const;
	void update();

	void render(sf::RenderTarget* target);
	const int& getPoint() const;
	const int& getDamage() const;
	const int& getHpOfEnemies() const;
	void loseHp(const int value);
	void setOrigin();
	sf::Vector2f getPos();

};
#endif 