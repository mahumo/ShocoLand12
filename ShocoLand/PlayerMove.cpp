#include "PlayerMove.h"
#include "LibInclude.h"
#include "MDCollision2D.h"


const float PlayerMove::Gravity = 9.8f;
PlayerMove::PlayerMove()
{
}


PlayerMove::~PlayerMove()
{
}
void PlayerMove::Inisialize(){}
void PlayerMove::Update(MDGameObj2D& obj, float speed)
{
	if (MDInput::Instance()->GetKeyState(KEYS_D) == DOWN){
		obj.pos.x += speed;
	}
	if (MDInput::Instance()->GetKeyState(KEYS_A) == DOWN){
		obj.pos.x -= speed;
	}
	if (MDInput::Instance()->GetKeyState(KEYS_W) == DOWN){
		obj.pos.y -= speed;
	}
	if (MDInput::Instance()->GetKeyState(KEYS_S) == DOWN){
		obj.pos.y += speed;
	}
	
}
