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
	Vector3 seek(Vector3 target);
	Vector3 pursue();
	Vector3 separate(std::vector<Enemy*> enemy);
	Vector3 velocity;

	//std::vector<Enemy*> enemylist;
	int enemieslength = 5;

private:
	Vector3 acceleration;
	Vector3 dir;
	Vector3 desiredVelocity;
	Vector3 steering;
	Vector3 seperationSteering;
	Vector3 steeringForce;
	SpaceShip *spaceship;
	float topspeed;
	float maxSteeringForce;
	int seperationStrength;
	

};
#endif
#pragma once