#pragma once

enum TileTextureType;
//class TileIDMap;
// なぜか、上手く先行宣言出来ない
#include "TiledMapObj.h"

#include "LibInclude.h"
class TiledMapObjManager
{
public:
	TiledMapObjManager() = default;
	~TiledMapObjManager() = default;

	void Add( TiledMapObj* obj );
	void Draw( MD2DHelper& helper, TileIDMap& id );																	// 全てのオブジェクトを描画
	void Draw( MD2DHelper& helper, TileIDMap& id, const TileTextureType& type );					// 指定したTileTexturetype飲みを描画

private:
	std::vector<std::unique_ptr<TiledMapObj>> objs;
};

