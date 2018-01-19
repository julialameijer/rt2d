/**
* The class of the bullets.
*
* Copyright 2018 Julia Lameijer
*/

#include "bulletScript.h"

bulletScript::bulletScript() : Entity()
{
	this->addSprite("assets/bullet.tga");
	this->velocity = Vector2(0, 0);
	this->acceleration = Vector2(-0.001, -0.01);
	this->topspeed = 0.5;

}

bulletScript::~bulletScript()
{

}

void bulletScript::update(float deltaTime)
{

}

