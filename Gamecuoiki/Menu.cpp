#include "Menu.h"

void Menu::initText() {
	this->sizeText = 60.f;

	if (!this->font.loadFromFile("Fonts/menu.ttf"))
		printf("NOT LOAD FONT START\n");

	this->startText.setFont(this->font);
	this->startText.setCharacterSize(this->sizeText);
	this->startText.setFillColor(sf::Color::White);
	this->startText.setString("START");

	this->informationText.setFont(this->font);
	this->informationText.setCharacterSize(this->sizeText);
	this->informationText.setFillColor(sf::Color::White);
	this->informationText.setString("INFORMATION");

	this->quitText.setFont(this->font);
	this->quitText.setCharacterSize(this->sizeText);
	this->quitText.setFillColor(sf::Color::White);
	this->quitText.setString("QUIT");

	//Position text
	this->startText.setPosition(750.f-startText.getGlobalBounds().width/2, 550.f);
	this->informationText.setPosition(750.f - informationText.getGlobalBounds().width/2, 650.f);
	this->quitText.setPosition(750.f - quitText.getGlobalBounds().width/2, 750.f);

	//Music
	this->musicOffTexture.loadFromFile("Textures/MusicOff.png");
	this->musicOffSprite.setTexture(this->musicOffTexture);
	this->musicOffSprite.setPosition(1400, 10);
	this->musicTexture.loadFromFile("Textures/musicIcon.png");
	this->musicSprite.setTexture(this->musicTexture);
	this->musicSprite.setPosition(1400.f, 10.f);
	
}
Menu::Menu() {
	this->textureBackground.loadFromFile("Textures/Bkmenu.png");
	this->spriteBackground.setTexture(textureBackground);
	
	//
	this->menuClose = false;
	this->gameStart = false;
	this->showInformation = false;
	// Music
	this->MusicOn = true;
	this->backgroundMusic.openFromFile("Sounds/MenuMusic.wav");
	this->backgroundMusic.setLoop(true);
	this->backgroundMusic.setPlayingOffset(sf::seconds(0));
	this->backgroundMusic.play();
	this->initText();

}
Menu::~Menu(){

}
void Menu::run(sf::RenderWindow* window)
{
	if (this->isMenuClose() == false)
	{
		
		this->update(window);
		this->render(window);
	}

}
const bool Menu::isMenuClose() const
{
	return this->menuClose;
}

const bool Menu::isGameStart() const
{
	return this->gameStart;
}
const bool Menu::isShowInfo() const
{
	return this->showInformation;
}
const sf::FloatRect Menu::getStartBounds() const
{
	return this->startText.getGlobalBounds();
}


const sf::FloatRect Menu::getInformationBounds() const
{
	return this->informationText.getGlobalBounds();
}

const sf::FloatRect Menu::getQuitBounds() const
{
	return this->quitText.getGlobalBounds();
}
void Menu::updateMouse(sf::RenderWindow* window)
{
	this->mousePosWindow = sf::Mouse::getPosition(*window);
	this->mousePosView = window->mapPixelToCoords(this->mousePosWindow);
}
void Menu::updateGUI(sf::RenderWindow* window){
	if (this->startText.getGlobalBounds().contains(this->mousePosView)) {
		if (this->startText.getFillColor()!= sf::Color::Red) {
			this->startText.setFillColor(sf::Color::Red);
		}
	}
	else this->startText.setFillColor(sf::Color::White);
	if (this->informationText.getGlobalBounds().contains(this->mousePosView)) {
		if (this->informationText.getFillColor() != sf::Color::Red) {
			this->informationText.setFillColor(sf::Color::Red);
		}
	}
	else this->informationText.setFillColor(sf::Color::White);
	if (this->quitText.getGlobalBounds().contains(this->mousePosView)) {
		if (this->quitText.getFillColor() != sf::Color::Red) {
			this->quitText.setFillColor(sf::Color::Red);
		}
	}
	else this->quitText.setFillColor(sf::Color::White);
	// Mouse click
	if (this->startText.getGlobalBounds().contains(this->mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		this->gameStart = true;
		this->menuClose = true;
		this->backgroundMusic.pause();
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->informationText.getGlobalBounds().contains(this->mousePosView))
	{
		
		this->showInformation = true;
		this->menuClose = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->quitText.getGlobalBounds().contains(this->mousePosView))
	{
		window->close();
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->musicSprite.getGlobalBounds().contains(this->mousePosView)) {
		this->MusicOn = false;
	}
}

void Menu::updateMusic()
{
	if (!MusicOn) this->backgroundMusic.pause();
	
}



void Menu::update(sf::RenderWindow* window)
{
	this->updateMouse(window);
	this->updateMusic();
	this->updateGUI(window);
}

void Menu::renderGUI(sf::RenderWindow* window)
{
	window->draw(this->startText);
	window->draw(this->informationText);
	window->draw(this->quitText);
}


void Menu::render(sf::RenderWindow* window)
{
	window->clear();

	window->draw(this->spriteBackground);
	window->draw(this->spriteLogo);
	if (MusicOn) window->draw(this->musicSprite);
	else window->draw(this->musicOffSprite);
	this->renderGUI(window);

	window->display();
}
