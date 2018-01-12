//Julia Lameijer 2017 Header


#ifndef ENEMY_H
#define ENEMY_H

#include <rt2d/entity.h>
#include "spaceship.h"

class Enemy : public Entity

{
public:
	/// @brief Constructor
	Enemy(SpaceShip *spaceship);
	
	/// @brief Destructor
	virtual ~Enemy();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	void addForce(Vector2 force);
	void seperation();
	void randomTopspeed();
	Vector3 seek();
	Vector3 pursue();
	//std::vector<Enemy*> enemylist;
	int enemieslength = 5;

private:
	Vector3 velocity;
	Vector3 acceleration;
	Vector3 dir;
	Vector3 desiredVelocity;
	Vector3 steering;
	SpaceShip *spaceship;
	float topspeed;
	float maxSteeringForce;

};
#endif
#pragma once