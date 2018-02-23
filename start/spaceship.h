/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Entity.h"

class SpaceShip : public Entity

{
public:
	/// @brief Constructor
	SpaceShip();
	/// @brief Destructor
	virtual ~SpaceShip();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	int getHealth();
	void damage();
	Vector2 velocity;

private:
	/* add your private declarations */
	Vector2 force;
	Vector2 acceleration;
	
	float damping;
	float topspeed;
	float health;
	float heading;
	float angle;
	float r;
	
};

#endif
