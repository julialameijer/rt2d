/**
 * The class of the spaceship.
 *
 * Copyright 2017 Julia Lameijer
 */

#include "spaceship.h"

SpaceShip::SpaceShip() : Entity()
{
	this->addSprite("assets/spaceship.tga");
	this->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	this->velocity = Vector2(0.5,0);
	this->acceleration = Vector2(0.5, 0);
	damping = 0.995;
	topspeed = 0.2;
	heading = 0;
	r = 16;
}

SpaceShip::~SpaceShip()
{
	
}

void SpaceShip::update(float deltaTime)
{

	this->rotation.z += HALF_PI * deltaTime; // 90 deg/sec
	if (this->rotation.z > TWO_PI) {
		this->rotation.z -= TWO_PI;
	}
	
	this->velocity += acceleration;
	this->velocity *= damping;
	this->velocity.limit(topspeed);
	this->position += velocity;
	this->acceleration * 0;
}
void SpaceShip::applyForce(Vector2 force)
{
	acceleration.operator+=(force);
}
void SpaceShip::turn(float a)
{
	heading += a;
}
void SpaceShip::thrust()
{
	

}


	