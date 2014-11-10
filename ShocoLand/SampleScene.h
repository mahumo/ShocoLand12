#pragma once
#include "LibInclude.h"
// 汚えけどライブラリを作成している途中なので、取り敢えずこれで
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
