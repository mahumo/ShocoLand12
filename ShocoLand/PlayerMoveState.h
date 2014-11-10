#pragma once

enum MoveState{
	LEFT,
	RIGHT
};

enum MoveAnimState{
	IDLE,
	WALK,
	JUMP,
	LADDAR
};

class PlayerMoveState
{
public:
	void Inisialize();
	void Update();
	void Draw();
private:
	MoveState m_moveState;
	MoveAnimState m_moveAnimState;
};

