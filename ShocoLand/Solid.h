#pragma once
#include "PlayerState.h"
#include "PlayerMove.h"
class Solid : public PlayerState
{
public:
	Solid();
	~Solid();

	void Inisialize(MDVector2 vec2);
	void Update();
	void Draw();

	void Move();
	MDGameObj2D getGameObj();
	bool isDead();
private:
	MDVector2 pos;
	float m_moveSpeed;
	bool m_isDead;

	MD2DHelper help2D;
	std::array<MD2DBitmap, 3> bitmap;
	PlayerMove m_Move;

	int m_count;
	bool flag;
	float x;
public:
	MDGameObj2D g_player;

};

