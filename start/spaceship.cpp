/**
 * The class of the spaceship.
 *
 * Copyright 2017 Julia Lameijer
 */

#include "spaceship.h"

SpaceShip::SpaceShip() : Entity()
{
	this->addSprite("assets/spaceship.tga");
	
}

SpaceShip::~SpaceShip()
{

}

void SpaceShip::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	// ###############################################################
	this->rotation.z += HALF_PI * deltaTime; // 90 deg/sec
	if (this->rotation.z > TWO_PI) {
		this->rotation.z -= TWO_PI;
	}
}
