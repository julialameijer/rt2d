/**
* The class of the enemy.
*
* Copyright 2018 Julia Lameijer
*/

#include "enemy.h"

Enemy::Enemy(SpaceShip *spaceship) : Entity()
{
	this->addSprite("assets/enemy.tga");
	this->velocity = Vector2(0, 0);
	this->acceleration = Vector2(-0.001, -0.01);
	this->spaceship = spaceship;
	this->maxSteeringForce = 0.005;
	this->topspeed = 0.5;
	this->speed = 300;
	this->maxSteeringForce = 0.005;
	this->seperationStrength = 0.3f;
	this->health = 2;

}

Enemy::~Enemy()
{

}
void Enemy::update(float deltaTime)
{
	//Turn towards the player
	this->rotation.z = velocity.getAngle();

	if (this->position.x -10 >= SWIDTH || this->position.x +10 < 0 || this->position.y  -10>= SHEIGHT || this->position.y +10< 0) {
		this->seperationStrength = 0;
		
	}
	else { this->seperationStrength = 0.4f;
	}
			
	//go after the player
	steeringForce = Vector3(0,0,0);
	steeringForce += seperationSteering * this->seperationStrength;
	steeringForce += pursue() * 1;
	
	steeringForce.limit(maxSteeringForce);
	addForce(steeringForce);
	velocity += acceleration;
	velocity.normalize();
	velocity.limit(topspeed);
	position += velocity *deltaTime * speed;
	//std::cout<<position<<std::endl;
	acceleration = Vector2(0, 0);
}

void Enemy::addForce(Vector2 force)
{
	this->acceleration += force;
}

void Enemy::damage()
{
	health -= 2;
}

int Enemy::getHealth()
{
	return health;
}

Vector3 Enemy::pursue()
{
	//Steering behaviour
	Vector3 desiredVelocity = spaceship->position - this->position;
	desiredVelocity = desiredVelocity.getNormalized() * topspeed;
	float distance = desiredVelocity.getLength();
	Vector3 futurePosition = spaceship->position + spaceship->velocity *distance;
	desiredVelocity.getLength()  * topspeed;
	seek(futurePosition);
	Vector3 steering = desiredVelocity - velocity;
	return steering;
}

Vector3 Enemy::separate(std::vector<Enemy*> list)
{
	int count = 0;
	Vector2 sum = Vector2(0, 0);
	for each (Enemy* e in list) {
		if (e != this) {
			Vector2 length = e->position - this->position;
			if (length.getLength() < 250) {
				count++;
				Vector2 diff = this->position - e->position;
				diff.normalize();
				sum = sum + diff;
			}
			if (count > 0) {
				sum /= count;
				steering = sum - velocity;
				//steering.limit(maxSteeringForce);
				seperationSteering = steering;
			}
		}
	}
	return Vector3();
}

Vector3 Enemy::seek(Vector3 target)
{
	//Additional steering behaviour
	Vector3 desiredVelocity = target - this->position;
	desiredVelocity.getLength()  * topspeed;
	Vector3 steering = desiredVelocity - velocity;
	//steering.limit(maxSteeringForce);
	return steering;
}

