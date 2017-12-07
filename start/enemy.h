/**
* Copyright 2015 Your Name <you@yourhost.com>
*
* @file myentity.h
*
* @brief description of MyEntity behavior.
*/

#ifndef ENEMY_H
#define ENEMY_H

#include <rt2d/entity.h>

class Enemy : public Entity

{
public:
	/// @brief Constructor
	Enemy();
	/// @brief Destructor
	virtual ~Enemy();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	void applyForce(Vector2 force);
	void thrust();
	void turn(float a);

private:
	/* add your private declarations */
	Vector2 velocity;
	Vector2 acceleration;
	Vector2 force;
	float damping;
	float topspeed;
	float heading;
	float angle;
	float r;

};

#endif
#pragma once
