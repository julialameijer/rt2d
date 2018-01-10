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
	spaceship = new SpaceShip();
	spaceship->scale = Point2(0.5, 0.5);
	spaceship->position = Point2(SWIDTH/2, SHEIGHT/2);
	enemy = new Enemy(spaceship);
	this->addChild(spaceship);
	this->addChild(enemy);
	enemy->scale = Point2(0.25, 0.25);
	enemy->position = Point2(SWIDTH / 2,5, SHEIGHT / 2);
}


MyScene::~MyScene()
{
	this->removeChild(spaceship);
	this->removeChild(enemy);
	
	delete spaceship;
	delete enemy;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}
