
//Class of the bombs 
#include "bomb.h"

Bomb::Bomb() : Entity()
{
	this->addSprite("assets/bullet.tga");
	exploded = false;
}
Bomb::~Bomb()
{

}

void Bomb::update(float deltaTime)
{
	if (bombtimer.seconds() >= 7) {
		std::cout << bombtimer.seconds() << std::endl;
		exploded = true;
		bombtimer.stop();
	}
}

void Bomb::explode()
{
	bombtimer.start();
}

void Bomb::checkNeighbors(std::vector<Enemy*> list, int radius) {
	for each (Enemy* e in list) {
		Vector2 length = e->position - this->position;
		if (length.getLength() >= 256) {
			std::cout << "outcircle" << std::endl;
			break;
		}
		else { enemy->damage(); }
	}
}


