/**
* The class of the spaceship.
*
* Copyright 2017 Julia Lameijer
*/

#include "enemy.h"

Enemy::Enemy(SpaceShip *spaceship) : Entity()
{
	this->addSprite("assets/enemy.tga");
	this->velocity = Vector2(0, 0);
	this->acceleration = Vector2(-0.001, -0.01);
	this->spaceship = spaceship;
	this->topspeed = 0.7;
	this->maxSteeringForce = 0.007;

}
Enemy::~Enemy()
{

}
void Enemy::update(float deltaTime)
{
	this->rotation.z += HALF_PI * deltaTime; // 90 deg/sec
	if (this->rotation.z > TWO_PI) {
		this->rotation.z -= TWO_PI;
	}

	//go after the player
	desiredVelocity = (spaceship->position - this->position);
	desiredVelocity.getNormalized() * topspeed;
	steering = desiredVelocity - velocity;
	steering.limit(maxSteeringForce);
	addForce(steering);
	velocity += acceleration;
	velocity.limit(topspeed);
	position += velocity;

}

void Enemy::addForce(Vector2 force)
{
	this->acceleration += force;
}
