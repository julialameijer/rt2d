/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include "spaceship.h"
#include "enemy.h"
#include "bomb.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	void setUpGame();

private:
	/// @brief the rotating square in the middle of the screen
	SpaceShip* spaceship;
	Enemy* enemy;
	/// @brief a Timer to rotate the color every n seconds
	Timer t;
	std::vector<Enemy*> enemylist;
	std::vector<Bomb*> bomblist;
	float radius;

	Vector2 averagePos;
	Point2 v;
	int neighborCount;
};

#endif /* SCENE00_H */
