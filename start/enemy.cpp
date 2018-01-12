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
	//this->topspeed = 0.2;
	this->maxSteeringForce = 0.3;
	
	
}
Enemy::~Enemy()
{

}
void Enemy::update(float deltaTime)
{
	//Turn towards the player
	this->rotation.z = velocity.getAngle();
	//go after the player
	addForce(pursue());
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

Vector3 Enemy::pursue()
{
	//Steering behaviour
	Vector3 desiredVelocity = spaceship->position - this->position;
	desiredVelocity = desiredVelocity.getNormalized() * topspeed;
	float distance = desiredVelocity.getLength();
	Vector3 futurePosition = spaceship->position + spaceship->velocity *distance;
	Vector3 steering = seek();
	return steering;
}

void Enemy::randomTopspeed()
{
	float random = rand() % 100;
	this->topspeed = random / 120;
	std::cout << topspeed << std::endl;

}
Vector3 Enemy::seek()
{
	//Additional steering behaviour
	Vector3 desiredVelocity = spaceship->position - this->position;
	desiredVelocity.getLength()  * topspeed;
	Vector3 steering = desiredVelocity - velocity;
	steering.limit(maxSteeringForce);
	return steering;
}

