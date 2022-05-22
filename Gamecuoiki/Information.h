#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
class Information
{
private:
	sf::Texture textureBackground;
	sf::Sprite spriteBackground;
	
	sf::Font font;

	sf::Text backText;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	void initText();
	void initText(sf::Text& text, std::string word, sf::Vector2f pos);
public:
	Information();
	virtual ~Information();
	bool open;
	const bool isOpen() const;
	const sf::FloatRect getBackBounds() const;
	void run(sf::RenderWindow* window);
	void updateMouse(sf::RenderWindow *window);
	void update(sf::RenderWindow* window);
	void render(sf::RenderWindow* window);
};

