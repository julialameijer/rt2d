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
	for (int i = 0; i < bomblist.size(); i++) {
		this->removeChild(bomblist[i]);
		delete bomblist[i];

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
	
	if (input()->getKeyDown(Space)) {
		if (bomblist.size() != 5) {
			////Adds bomb to screen
			Bomb *singleBomb = new Bomb;
			this->addChild(singleBomb);
			singleBomb->position = spaceship->position;
			singleBomb->scale = Point2(0.5, 0.5);

			////Adds bomb to arraylist
			bomblist.push_back(singleBomb);

			////Function in bomb that starts the timer
			singleBomb->explode();
		}
		else(std::cout << "too much bombs" << std::endl);
	}

	////Checks if it is exploded, and calls the function that get the enemies killed
	for each(Bomb* b in bomblist) {
		if (b->exploded) {
			b->checkNeighbors(enemylist, 64);	
			this->removeChild(b);
			b->exploded = false;
		}
	}
	for each (Enemy* e in enemylist) {
		enemy->separate(enemylist);
		if (e->getHealth() <= 0) {
			std::cout << "health" << std::endl;
			this->removeChild(e);
		}
	}
}

void MyScene::setUpGame()
{
	//The start of the game
	spaceship->scale = Point2(1, 1);
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