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
	this->rotation.z += HALF_PI * deltaTime; // 90 deg/sec
	if (this->rotation.z > TWO_PI) {
		this->rotation.z -= TWO_PI;
	}
	
	this->velocity += acceleration;
	this->velocity.limit(topspeed);
	this->position += velocity;
	this->acceleration * 0;
	if (this->position.x < 0) { this->position.x = SWIDTH; }
	if (this->position.x > SWIDTH) { this->position.x = 0; }
	if (this->position.y < 0) { this->position.y = SHEIGHT; }
	if (this->position.y > SHEIGHT) { this->position.y = 0; }

	float rotspeed = 3.14f;

	Vector2 velocity = Vector2((rand() % 100) - 50, (rand() % 100) - 50);
	static Polar polar = Polar((rand() % 360) * DEG_TO_RAD, 400.0f);

	if (input()->getKey(KeyCode::Up)) {
		velocity = polar.cartesian() - acceleration *-1 * 2 * deltaTime; // thrust
	}
	if (input()->getKey(KeyCode::Right)) {
		polar.angle += rotspeed * deltaTime; // rotate right
	}
	if (input()->getKey(KeyCode::Left)) {
		polar.angle -= rotspeed * deltaTime; // rotate left
	}
	this->rotation.z = polar.angle;
	this->position += velocity * deltaTime;
}


