#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#define MAX_NUMBER_OF_ITEMS 3
class Menu
{
public:
	bool menuClose;
	bool gameStart;
	bool showInformation;

	
private:
	float sizeText;
	sf::Text startText;
	sf::Text quitText;
	sf::Text informationText;
	sf::Font font;
	// Mouse
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	//Music
	bool MusicOn;
	sf::Texture musicOffTexture;
	sf::Sprite musicOffSprite;
	sf::Texture musicTexture;
	sf::Sprite musicSprite;
private:
	sf::Texture textureBackground;
	sf::Sprite spriteBackground;

	sf::Texture textureLogo;
	sf::Sprite spriteLogo;

	sf::Music backgroundMusic;
	void initText();
public:
	Menu();
	virtual ~Menu();

	void run(sf::RenderWindow* window);

	const bool isMenuClose() const;
	const bool isGameStart() const;
	const bool isShowInfo() const;

	const sf::FloatRect getStartBounds() const;
	const sf::FloatRect getInformationBounds() const;
	const sf::FloatRect getQuitBounds() const;

	void updateMouse(sf::RenderWindow* window);
	void updateGUI(sf::RenderWindow* window);
	void updateMusic();
	void update(sf::RenderWindow* window);
	void renderGUI(sf::RenderWindow* window);
	void render(sf::RenderWindow* window);
	
	void restartGame();

};

