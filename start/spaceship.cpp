/**
* The class of the spaceship.
*
* Copyright 2017 Julia Lameijer
*/

#include "spaceship.h"

SpaceShip::SpaceShip() : Entity()
{
	this->addSprite("assets/spaceship.tga");
	this->velocity = Vector2(0, 0);
	this->acceleration = Vector2(0, 0);
	this->topspeed = 0;
	heading = 0;
	r = 16;
}
SpaceShip::~SpaceShip()
{

}

void SpaceShip::update(float deltaTime)
{
	//Rotation towards future position
	this->rotation.z += HALF_PI * deltaTime; // 90 deg/sec
	if (this->rotation.z > TWO_PI) {
		this->rotation.z -= TWO_PI;
	}
	//Movementspeed
	this->velocity += acceleration;
	this->velocity.limit(topspeed);
	this->position += velocity;
	this->acceleration = Vector2(0,0);	

	//Comes back at the other side of the screen after going out
	if (this->position.x < 0) { this->position.x = SWIDTH; }
	if (this->position.x > SWIDTH) { this->position.x = 0; }
	if (this->position.y < 0) { this->position.y = SHEIGHT; }
	if (this->position.y > SHEIGHT) { this->position.y = 0; }

	//rotation speed
	float rotspeed = 3.14f;


	//Movement
	static Polar polar = Polar((rand() % 360) * DEG_TO_RAD, 400.0f);

	if (input()->getKey(KeyCode::Up) || input()->getKey(KeyCode::W)) {
		velocity = polar.cartesian() - acceleration *-1 * 2 * deltaTime; // thrust
	}
	if (input()->getKey(KeyCode::Right) || input()->getKey(KeyCode::D)) {
		polar.angle += rotspeed * deltaTime; // rotate right
	}
	if (input()->getKey(KeyCode::Left) || input()->getKey(KeyCode::A)) {
		polar.angle -= rotspeed * deltaTime; // rotate left
	}
	this->rotation.z = polar.angle;
	this->position += velocity * deltaTime;
}
