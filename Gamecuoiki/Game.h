#pragma once
#include"Player.h"
#include <map>
#include "Bullet.h"
#include "Enemy.h"
#include <string>
#include<Windows.h>
#include<SFML/Window.hpp>
#include<sstream>
#include"Menu.h"
#include"Information.h"
#include"Boom.h"
#include"Upgrade.h"
#include"Boss.h"
#include"BossWeapon.h"
#include"BossDeath.h"
class Game {
private:
	sf::RenderWindow* window;

	// 
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	//GUI giao dien do hoa nguoi dung
	sf::Font font;
	sf::Text pointText;

	sf::Text gameOverText;

	sf::Text winText;
	sf::Font fon2;
	// Player GUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	//World
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;



	//System
	unsigned points;

	// Player
	Player *player;
	
	bool isVictory;
	bool isLose;

	// EnemIES
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

	// Boom
	std::vector<Boom*> booms;
	float boomSpawnTimer;
	float boomSpawnTimerMax;
	float frame;

	bool isBoom;

	
	bool isGameEnd;
	// Menu
	Menu* menu;
	Information* info;
	//Music
	sf::Music exploreMusic;
	//Boss
	Boss* boss;
	bool isBossExist;

	//boss death
	BossDeath* bossDeath;
	//Weapon
	vector<BossWeapon*> weapon;
	void initWindow();
	void initSound();
	void initGUI();
	void initTexture();
	void initUpgrade();
	void initBoom();
	void initWorld();
	void initBoss();
	void initSystem();
	void initPlayer();
	void initEnemies();

public:
	
	Game();
	virtual ~Game();
	void run();

	void updatePollEvent();
	void updateInput();
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateBullet();
	void updateEnemies();
	void updateCombat();
	void updateBoss();
	void updateWeapon();
	void update();

	void runGamePlay();
	void renderGUI();
	void renderWorld();
	void renderBoom(sf::RenderWindow* window);
	void renderBoss(sf::RenderWindow* window);

	void render();
	void restartGame();
	bool isWin = false;
};