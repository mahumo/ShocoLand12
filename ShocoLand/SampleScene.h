#pragma once
#include "LibInclude.h"
// �������ǃ��C�u�������쐬���Ă���r���Ȃ̂ŁA��芸���������
#include "MDCollision2D.h"

#include "Player.h"
#include "PlayerMove.h"

class SampleScene :public MDScene
{
public:
	int Initialize();
	int Update();
	int Release();

public:
	MD2DTextWriter writer;
	MD2DHelper help2D;
	MDCamera mainCamera;

	MDFps fps;
	MD2DBitmap bitmap;
	MD2DBitmap bitmap2;

	MDGameObj2D g_enemy;
	MDGameObj2D g_player;
	std::unique_ptr<Player> m_player;

	IsGround gg;
};
