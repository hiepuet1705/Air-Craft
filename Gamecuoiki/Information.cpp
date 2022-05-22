#include "Information.h"

void Information::initText()
{
	this->font.loadFromFile("Fonts/menu.ttf");
	this->initText(this->backText, "Back", sf::Vector2f(10.f, 10.f));
}
void Information::initText(sf::Text& text, std::string word, sf::Vector2f pos)
{
	text.setCharacterSize(70.f);
	text.setFillColor(sf::Color::Yellow);
	text.setFont(this->font);
	text.setString(word);
	text.setPosition(pos);
}
Information::Information()
{
	this->textureBackground.loadFromFile("Textures/Information.png");
	this->spriteBackground.setTexture(textureBackground);
	this->initText();

	this->open = true;
}

Information::~Information()
{

}

const bool Information::isOpen() const
{
	return this->open;
}

const sf::FloatRect Information::getBackBounds() const
{
	return this->backText.getGlobalBounds();
}

void Information::run(sf::RenderWindow* window)
{
	this->update(window);
	this->render(window);
}

void Information::updateMouse(sf::RenderWindow* window)
{
	this->mousePosWindow = sf::Mouse::getPosition(*window);
	this->mousePosView = window->mapPixelToCoords(this->mousePosWindow);
}

void Information::update(sf::RenderWindow* window)
{
	this->updateMouse(window);
	this->backText.setCharacterSize(50);
	if (this->backText.getGlobalBounds().contains(this->mousePosView))
	{
		if (this->backText.getFillColor() != sf::Color::Red)
		{
			this->backText.setFillColor(sf::Color::Red);
			
		}
	}
	else
		this->backText.setFillColor(sf::Color::Yellow);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->backText.getGlobalBounds().contains(this->mousePosView))
	{
		this->open = false;
		
	}
	
}

void Information::render(sf::RenderWindow* window)
{
	window->draw(this->spriteBackground);
	window->draw(this->backText);
	window->display();
}

