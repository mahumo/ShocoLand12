#include "Normal.h"



Normal::Normal() :
m_moveSpeed(5),
m_isDead(false),
m_count(0),
flag(false),
x(0)
{}

Normal::~Normal()
{
}

void Normal::Inisialize(MDVector2 vec2){
	help2D.Initialize();
	for (const auto& b : { L"Resource/wait/p_wait1.png", L"Resource/wait/p_wait2.png", L"Resource/wait/p_wait3.png" })
	{
		bitmap[m_count].Create(b);
		m_count++;
		
	}

	m_count = 0;
	g_player = MDGameObj2D({vec2}, bitmap[m_count].GetImageSize());
	
}

void Normal::Update(){
	
	if (x < 20 && !flag){
		x++;
	}
	if (x >= 20)
		flag = true;
	if (x > 0 && flag){
		x--;
	}
	if (x <= 0)
		flag = false;

	if (x < 5 && x  >= 0)
		m_count = 0;
	if (x < 15 && x >= 5)
		m_count = 1;
	if (x < 20 && x >= 15)
		m_count = 2;
}
void Normal::Draw(){
	help2D.BitMap(&bitmap[m_count], g_player.pos, { 0, 0, g_player.size.x , g_player.size.y  }, 1);
}

void Normal::Move(){
	m_Move.Update(g_player, m_moveSpeed);
}
MDGameObj2D Normal::getGameObj(){
	return g_player;
}
bool Normal::isDead(){
	return m_isDead;
}
