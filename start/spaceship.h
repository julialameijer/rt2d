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

private:
	/* add your private declarations */
	Vector2 force;
	Vector2 acceleration;
	Vector2 velocity;
	float damping;
	float topspeed;
	float heading;
	float angle;
	float r;
	
};

#endif
