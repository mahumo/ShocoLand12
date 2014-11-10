#pragma once
#include "LibInclude.h"
#include "MDCollision2D.h"
#include "TiledMap.h"


class GameScene :public MDScene
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
	std::array<MD2DBitmap, 3> bitmap ;

	MDGameObj2D back;
	MDGameObj2D stage;
	MDGameObj2D player;
	MDGameObj2D circle0;
	MDGameObj2D circle1;
	TiledMap map;

	ID2D1Bitmap* copyTexture;

};
