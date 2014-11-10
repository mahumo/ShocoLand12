#pragma once

#include "LibInclude.h"
#include "TiledMapLoader.h"
#include "TileIDMap.h"
#include "TiledMapObjManagerd.h"


class TiledMap
{
public:
	TiledMap() = default;
	~TiledMap() = default;

	void Initialize();
	void Update();
	void Draw( MD2DHelper& help2D );
	void LayerDraw( MD2DHelper& help2D, std::vector<TileLayer>& layer, const TileTextureType& type );

	std::shared_ptr<TiledMapLoader> map = {};
	
	// TileTextureIDマップ
	TileIDMap idMap;
	// TileGameObjマネージャー
	TiledMapObjManager tiledObjManager;
};

