#ifndef BULLETSCRIPT_H
#define BULLETSCRIPT_H

#include <rt2d/entity.h>

class bulletScript : public Entity

{
public:
	/// @brief Constructor
	bulletScript();

	/// @brief Destructor
	virtual ~bulletScript();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Vector2 acceleration;
	Vector2 velocity;
	float topspeed;

	
};
#endif
#pragma once