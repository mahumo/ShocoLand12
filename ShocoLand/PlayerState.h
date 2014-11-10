#pragma once
#include "LibInclude.h"
#include "MDCollision2D.h"
class PlayerState
{
public:
	virtual ~PlayerState(){};
	virtual void Inisialize(MDVector2 vec2) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual void Move() = 0;
	virtual MDGameObj2D getGameObj() = 0;
	bool isDead();
private:
};