//Julia Lameijer 2017 Header


#ifndef BOMB_H
#define BOMB_H

#include <rt2d/entity.h>
#include "spaceship.h"
#include "enemy.h"

class Bomb : public Entity
{
public:

	//Ususal stuff
	Bomb();
	virtual ~Bomb();
	virtual void update(float deltaTime);
	void explode();
	void checkNeighbors(std::vector<Enemy*> list, int radius);
	bool exploded;

private:
	SpaceShip* spaceship;
	Enemy* enemy;
	int strength;
	Timer bombtimer;
	
};
#endif