#include "TiledMapObjManagerd.h"
#include "TiledMapLoader.h"
#include "TileIDMap.h"


using namespace std;

void TiledMapObjManager::Add( TiledMapObj* obj )
{
	objs.push_back( unique_ptr<TiledMapObj>( obj ) );
}

void TiledMapObjManager::Draw( MD2DHelper& helper, TileIDMap& id )
{
	for( auto& t : objs )
	{
		t->Draw( helper, id );
	}
}

void TiledMapObjManager::Draw( MD2DHelper& helper, TileIDMap& id, const TileTextureType& type )
{
	for( auto& t : objs )
	{
		auto& tileID = id.GetValue( t->GetTileID() );

		// 指定したテクスチャタイプのみを描画
		if( type == tileID->GetTextureType() )
			t->Draw( helper, tileID );
	}
}
