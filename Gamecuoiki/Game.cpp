#include "Game.h"

void Game::initWindow() {
	
	this->window = new sf::RenderWindow(sf::VideoMode(1500, 950), "Air Craft", sf::Style::Close | sf::Style::Titlebar);
	this->window->setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width * 0.5 -
			this->window->getSize().x * 0.5, 0));
	this->window->setFramerateLimit(120);
	this->window->setVerticalSyncEnabled(false);
}
void Game::initSound()
{
	this->exploreMusic.openFromFile("Sounds/PlanetExplore.ogg");
}
void Game::initGUI()
{
	this->menu = new Menu();
	this->info = new Information();
	// Load font 
	this->font.loadFromFile("Fonts/GameWin.ttf");
	this->fon2.loadFromFile("Fonts/PixellettersFull.ttf");
	// init point text
	this->pointText.setPosition(1250.f, 10.f);
	this->pointText.setFont(this->fon2);
	this->pointText.setCharacterSize(60);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("Game");
	//Win text
	this->winText.setPosition(600.f, 400.f);
	this->winText.setFont(this->font);
	this->winText.setCharacterSize(70);
	this->winText.setFillColor(sf::Color::Green);
	this->winText.setString("You Win");
	// Game Over
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(50);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("		Game Over! \n Press Space to Play Again");
	this->gameOverText.setPosition(this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f
		, this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f);

	// Init Player GUI
	this->playerHpBar.setSize(sf::Vector2f(300.f, 35.f));
	this->playerHpBar.setFillColor(sf::Color::Green);
	this->playerHpBar.setPosition(sf::Vector2f(0.f, 40.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25,50, 200));
}
void Game::initTexture()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Textures/laserBlue01.png");

	this->textures["Boom1"] = new sf::Texture();
	this->textures["Boom1"]->loadFromFile("Textures/boom4.png");

	this->textures["BossWeapon"] = new sf::Texture();
	this->textures["BossWeapon"]->loadFromFile("Textures/bossWeapon.png");
}
void Game::initBoom()
{
	
	this->boomSpawnTimer = 0;
	this->boomSpawnTimerMax = 5.f;
	this->isBoom = false;
	this->frame = 0;
}
void Game::initWorld()
{
	this->worldBackgroundTex.loadFromFile("Textures/background1.jpg");
	this->worldBackground.setTexture(this->worldBackgroundTex);
}
void Game::initBoss()
{
	this->boss = new Boss();
	this->bossDeath = new BossDeath();
}
void Game::initSystem()
{
	this->points = 0;
	this->isGameEnd = false;
	this->isVictory = false;
	this->isBossExist = false;
}
void Game::initPlayer()
{
	this->player = new Player();
}
void Game::initEnemies()
{
	this->spawnTimerMax = 40.f;

	this->spawnTimer = this->spawnTimerMax;
}
Game::Game()
{
	this->initWindow();
	this->initTexture();
	this->initBoom();
	this->initWorld();
	this->initSound();
	this->initSystem();
	this->initGUI();
	this->initPlayer();
	this->initEnemies();
	this->initBoss();
}

Game::~Game()
{
	delete this->window;
	for (auto i : this->textures) {
		delete i.second;
	}
	for (auto* i : this->bullets) {
		delete i;
	}
	for (auto* i : this->enemies) {
		delete i;
	}
	delete this->player;
	delete this->menu;
	
	delete this->info;
	delete this->boss;
	for (auto* i : this->weapon) {
		delete i;
	}
	delete this->bossDeath;
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvent();
		this->menu->run(this->window);
		if (this->menu->isShowInfo()) {
			this->info->open = true;
			this->info->run(this->window);
			this->menu->menuClose = this->info->isOpen();
			this->menu->showInformation = this->info->isOpen();
		}
		if (this->menu->isGameStart())
			this->runGamePlay();
	}
}
void Game::runGamePlay() {
	if (this->player->getHp() > 0 && !isGameEnd) {
		this->update();
		if (isVictory == true) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				this->player->setHp(50);
				isGameEnd = 0;
				isVictory = false;
				this->points = 0;
				this->update();
				boss = new Boss();
				bossDeath->setRectLeft(0);
			} 
		}
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			this->player->setHp(50);
			isGameEnd = 0;
			isBossExist = 0;
			this->points = 0;
			this->update();
			boss = new Boss();
			bossDeath->setRectLeft(0);
		}
	}
	this->render();
}

void Game::updatePollEvent()
{
	sf::Event ev;
	while (this->window->pollEvent(ev)) {
		if (ev.type == sf::Event::Closed) this->window->close();

	}
}

void Game::updateInput()
{
	// Update
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) this->player->move(0.f, 1.f);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&this->player->canAttack()) {
		
		this->bullets.push_back(new Bullet(this->textures["BULLET"],
			this->player->getPos().x+this->player->getBounds().width/2.f
			, this->player->getPos().y, 0.f, -1.f, 5.f));
		
		
	}
	if (isBossExist && this->boss->canAttack()) {
		this->weapon.push_back(new BossWeapon(this->textures["BossWeapon"], this->boss->getPos().x+this->boss->getBounds().width/2-50.f, this->boss->getPos().y+this->boss->getBounds().height-15.f));
	}
}

void Game::updateGUI()
{
	std::stringstream ss;
	ss << "Points: " << this->points;
	this->pointText.setString(ss.str());


	// update GUI

	float hpPercent = static_cast <float>(this->player->getHp()) / this->player->getHpMax();	
	this->playerHpBar.setSize(sf::Vector2f(300.f*hpPercent, this->playerHpBar.getSize().y));
	

}

void Game::updateWorld()
{
	
}

void Game::updateCollision()
{

	// Left collision
	if (this->player->getBounds().left < 0.f) {
		this->player->setPosition(0.f, this->player->getBounds().top);
	}

	// right
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x) {
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}

	// top
	if (this->player->getBounds().top < 0.f) {
		this->player->setPosition(this->player->getBounds().left, 0.f);
	}
	// bottom
	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y) {
		this->player->setPosition(this->player->getBounds().left,this->window->getSize().y-this->player->getBounds().height);
	}
}

void Game::updateBullet()
{
	unsigned counter = 0;
	for (auto *bullet : this->bullets) {
		bullet->update();
		//Bullet culling(top of screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f) {
			// Delete bullet
			delete this->bullets.at(counter);

			this->bullets.erase(this->bullets.begin() + counter);

		}
		++counter;
	}
}

void Game::updateEnemies()
{
	// spawning
	this->spawnTimer += 0.5f;

	if (this->spawnTimer >= this->spawnTimerMax) {
		this->enemies.push_back(new Enemy(rand() % 1350, -100.f));

		this->spawnTimer = 0.f;
	}
	// update
	unsigned counter = 0;
	for (auto* enemy : this->enemies) {
		enemy->update();
		//Bullet culling(top of screen)
		if (!isVictory) {
		if (enemy->getBounds().top > this->window->getSize().y) {
			// Delete bullet
			delete this->enemies.at(counter);

			this->enemies.erase(this->enemies.begin() + counter);

		}
		else if (enemy->getBounds().intersects(this->player->getBounds())) {
			this->player->loseHp(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			
		}
		++counter;
		}
	}

}

void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); ++i) {
		bool enemy_deleted = false;
		if (!isVictory) {

		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++) {
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds())) {
				this->enemies[i]->loseHp(3);
				delete this->bullets[k];
				bullets.erase(bullets.begin() + k);
				if (this->enemies[i]->getHpOfEnemies() <= 0) {
					
					this->exploreMusic.setPlayingOffset(sf::seconds(0));
					this->exploreMusic.play();
					
					booms.push_back(new Boom(textures["Boom1"]));
					this->isBoom = true;
					for (auto num : booms)
					{
						num->setPos(this->enemies[i]->getPos());
					}
				this->points += enemies[i]->getPoint();
				delete this->enemies[i];
				enemies.erase(enemies.begin() + i);

				
				enemy_deleted = true;
				}
			}
		}
		}
	}
}

void Game::updateBoss()
{
	if (this->points > 50) {
		this->isBossExist = true;
		this->boss->update();
		if (this->clockMove.getElapsedTime().asSeconds() > 1.3f)
		{
			
			this->boss->move((this->player->getPos().x-this->boss->getPos().x)*2/5, 0.f);
			
			this->clockMove.restart();
		}
		for (size_t k = 0; k < this->bullets.size(); k++) {
			if (!isVictory) {
				if (this->boss->getBounds().intersects(this->bullets[k]->getBounds())) {
					this->boss->getDamge(5);
					delete this->bullets[k];
					bullets.erase(bullets.begin() + k);
				}
			}
		}
		if (this->boss->getHp() <= 0) {
			this->boss->setBossDead();
			if (this->boss->isDead()) {
				if (this->bossDeath->getRect().left <= 2200)
					this->bossDeath->update(this->boss->getPos());
			}
			this->isVictory = 1;
			isBossExist = false;
		}
	}
	
}

void Game::updateWeapon()
{
	unsigned counter = 0;
	for (auto* bossWeapon : this->weapon) {
		bossWeapon->update();
		if (bossWeapon->getBound().intersects(this->player->getBounds())) {
			this->player->loseHp(this->weapon.at(counter)->getDamage());
			
			delete this->weapon.at(counter);
			this->weapon.erase(this->weapon.begin() + counter);
		}

	}
}

void Game::update()
{
	this->updateInput();
	this->player->update();
	this->updateCollision();
	this->updateBullet();
	this->updateEnemies();
	this->updateCombat();
	this->updateGUI();
	this->updateWorld();
	this->updateBoss();
	this->updateWeapon();
}


void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}

void Game::renderBoom(sf::RenderWindow* window)
{
	if (isBoom)
	{
		if (boomSpawnTimer > boomSpawnTimerMax)
		{
			boomSpawnTimer = 0.f;
			this->frame += 1.f;
			if (frame >= 1)
			{
				isBoom = false;
				frame = 0;
				boomSpawnTimer = 0.f;
			}
		}
		else {
			booms[frame]->render(window);
			boomSpawnTimer += 1.f;
		}
	}
}

void Game::renderBoss(sf::RenderWindow* window)
{
	if (isBossExist) {
		this->boss->render(this->window);
	}
}


void Game::render()
{
	this->window->clear();

	//Draw world
	this->renderWorld();

	//Draw all the stuffs
	this->player->render(*this->window);

	for (auto* bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}
	this->renderBoom(this->window);

	this->renderBoss(this->window);
	for (auto* weapon : this->weapon)
	{
		weapon->render(this->window);
	}
	this->renderGUI();
	if (this->boss->isDead()) this->bossDeath->render(this->window);
	//Game over screen
	if (this->player->getHp()<=0)
		this->window->draw(this->gameOverText);
	if (isVictory) 
		this->window->draw(this->winText);
	this->window->display();
}

