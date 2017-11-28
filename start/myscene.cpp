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

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	spaceship = new SpaceShip();
	spaceship->scale = Point2(0.5, 0.5);
	spaceship->position = Point2(SWIDTH/2, SHEIGHT/2);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(spaceship);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(spaceship);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete spaceship;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Spacebar scales myentity
	// ###############################################################
	if (input()->getKeyDown(KeyCode::Space)) {
		spaceship->scale = Point(0.5f, 0.5f);
	}
	if (input()->getKeyUp(KeyCode::Space)) {
		spaceship->scale = Point(1.0f, 1.0f);
	}

	// ###############################################################
	// Rotate color
	// ###############################################################
	if (t.seconds() > 0.0333f) {
		RGBAColor color = spaceship->sprite()->color;
		spaceship->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}
}
