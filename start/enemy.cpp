/**
* The class of the spaceship.
*
* Copyright 2017 Julia Lameijer
*/

#include "enemy.h"

Enemy::Enemy() : Entity()
{
	this->addSprite("assets/spaceship.tga");
	this->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	this->velocity = Vector2(0, 0);
	this->acceleration = Vector2(0, 0);
	damping = 0.995;
	topspeed = 5000;
	heading = 0;
	r = 16;
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

	this->velocity += acceleration;
	this->velocity *= damping;
	this->velocity.limit(topspeed);
	this->position += velocity;
	this->acceleration * 0;

	if (this->position.x < 0) { this->position.x = SWIDTH; }
	if (this->position.x > SWIDTH) { this->position.x = 0; }
	if (this->position.y < 0) { this->position.y = SHEIGHT; }
	if (this->position.y > SHEIGHT) { this->position.y = 0; }

	float rotspeed = 3.14f;

	static Vector2 velocity = Vector2((rand() % 100) - 50, (rand() % 100) - 50);
	static Polar polar = Polar((rand() % 360) * DEG_TO_RAD, 400.0f);

	if (input()->getKey(KeyCode::Up)) {
		velocity += polar.cartesian() * deltaTime; // thrust
	}
	if (input()->getKey(KeyCode::Down)) {
		velocity = polar.cartesian() * deltaTime; // thrust
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
void Enemy::applyForce(Vector2 force)
{
	acceleration.operator+=(force);
}
void Enemy::turn(float a)
{
	heading += a;
}
void Enemy::thrust()
{


}


