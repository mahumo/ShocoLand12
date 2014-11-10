#include "TiledObjFactory.h"
#include "TiledMapLoader.h"
#include "TileIDMap.h"
#include "TiledMapObj.h"
#include "TiledMapObjManagerd.h"

// TileMapEditorからマップデータを取得し、ゲームオブジェクトとして
// 登録していく	 
void TiledObjFactory::Create( const TileLayerType& layerType, const TiledMapEditor& editor, TileIDMap& idMap, TiledMapObjManager& manager )
{
	/*
	現状プログラム側で、途中で指定したものを追加することが容易ではない
	ID番号の直接していしか出来ないのである
	[例]	理想 ○○オブジェクト追加
	現実 1番追加

	ゲーム中に追加していくようなオブジェクトは、
	別に読み込んでいくロジックにした方が良い											*/
	for( const auto& layer : editor.layer )
	{
		if( layerType != layer.type )
		{
			int mapY = 0;
			for( const auto& tableY : layer.table )
			{
				int mapX = 0;
				for( const auto& id : tableY )
				{
					// tile番号0は存在しないので、弾く
					if( 0 == id )
					{
						++mapX;
						continue;
					}

					// 座標の事前計算
					auto& rect = idMap.GetValue( id )->GetRect();
					MDGameObj2D gameObj = { MDVector2( (mapX - 1)* editor.tileSize.x, (mapY - 1)*editor.tileSize.y ), MDVector2( rect.right, rect.bottom ) };

					// ゲームオブジェクトとして登録
					TiledMapObj* obj = new TiledMapObj( gameObj, MDVector2( (float)mapX, (float)mapY ), id );
					manager.Add( obj );
					++mapX;
				}
				++mapY;
			}
		}
	}
}
