#pragma once
#include "PlayerState.h"
#include "PlayerMoveState.h"
#include "MDCollision2D.h"

class Player
{
public:
	Player(std::unique_ptr<PlayerState> state);
	~Player();
	void Inisialize(MDVector2 vec2);
	void Update();
	void Draw();
	void Move();
	void StateChange(std::unique_ptr<PlayerState> state);
public:
	bool isGround;
	MDGameObj2D g_player;
private:
	// è»ó™î≈
	/*template<typename T>
	using PlayerPtr = std::unique_ptr<T>;
	PlayerPtr<PlayerState> aa__a;
	PlayerPtr<Player> re;*/
	std::unique_ptr<PlayerState> m_pState;

	PlayerMoveState m_pmState;
	static const float GRAVITY;
};

