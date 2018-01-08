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
	this->topspeed = 0.5;
	this->maxSteeringForce = 0.3;

}
Enemy::~Enemy()
{

}
void Enemy::update(float deltaTime)
{
	this->rotation.z = velocity.getAngle();

	//go after the player
	desiredVelocity = (spaceship->position - this->position);
	desiredVelocity.getNormalized();
	steering = desiredVelocity - velocity;
	steering.limit(maxSteeringForce);
	addForce(steering);
	velocity += acceleration;
	velocity.normalize();
	velocity.limit(topspeed);
	position += velocity;
	acceleration = Vector2(0, 0);




}

void Enemy::addForce(Vector2 force)
{
	this->acceleration += force;
}