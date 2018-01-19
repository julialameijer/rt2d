/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include "myscene.h"


MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();
	this->averagePos = Vector2(0, 0);
	spaceship = new SpaceShip();
	bullet = new bulletScript();
	srand(time(NULL));
	v = Point2(0, 0);
	radius = 1000;
	neighborCount = 0;
	setUpGame();
}


MyScene::~MyScene(){
	//destructor
	this->removeChild(spaceship);
	delete spaceship;

	for each (bullet in bulletlist) {
		delete bullet;
	}

	for each(enemy in enemylist) {
		this->removeChild(enemy);
		delete enemy;
	}
}

void MyScene::update(float deltaTime)
{
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
	for each (enemy in enemylist) {
		enemy->separate(enemylist);
	}
}

void MyScene::setUpGame()
{
	//The start of the game
	spaceship->scale = Point2(0.5, 0.5);
	spaceship->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	this->addChild(spaceship);
	

	for (size_t i = 0; i <5; i++)
	{
		enemy = new Enemy(spaceship);
		this->addChild(enemy);
		float random = rand() % 360;
		float angle = random* PI * 100000;
		enemy->position.x = SWIDTH / 2 + cos(angle)*radius;
		enemy->position.y = SHEIGHT / 2 + sin(angle)*radius;
		enemy->scale = Point2(0.32, 0.32);
		enemylist.push_back(enemy);
		
	}
}
