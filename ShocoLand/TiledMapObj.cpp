#include "TiledMapObj.h"
#include "TiledMapLoader.h"
#include "TileIDMap.h"

using namespace std;

TiledMapObj::TiledMapObj():
obj( ),
mapNumber( 0 ),
tileID( 0 )
{
}

TiledMapObj::TiledMapObj( MDGameObj2D& obj2d, MDVector2& mapNum, int tileId ) :
obj( obj2d ),
mapNumber( mapNum ),
tileID( tileId )
{
}


MDGameObj2D& TiledMapObj::GetGameObjct()
{
	return obj;
}
MDVector2&	 TiledMapObj::GetPosition()
{
	return obj.pos;
}
MDVector2&	 TiledMapObj::GetSize()
{
	return obj.size;
}
MDVector2&	 TiledMapObj::GetCenter()
{
	return obj.center;
}
MDVector2&	 TiledMapObj::GetMapNumber()
{
	return mapNumber;
}
int TiledMapObj::GetTileID()
{
	return tileID;
}

void	TiledMapObj::SetPosition( const MDVector2& pos )
{
	obj.pos = pos;
}
void TiledMapObj::Trancelate( const MDVector2& vec )
{
	obj.pos = obj.pos + vec;
}
void	TiledMapObj::SetSize( const MDVector2& size )
{
	obj.size = size;
}
void	TiledMapObj::SetPoint( const MDVector2& point )
{
	obj.center = point;
}

void	TiledMapObj::Draw( MD2DHelper& helper, TileIDMap& mapID )
{
	auto& id = mapID.GetValue( tileID );
	helper.BitMap(
		id->GetTexture(),
		obj.pos,
		D2D1::RectF( id->GetRect().left, id->GetRect().top, obj.size.x, obj.size.y ),
		1.0f );
}

void	TiledMapObj::Draw( MD2DHelper& helper, unique_ptr<TileID>& id )
{
	helper.BitMap( 
		id->GetTexture(), 
		obj.pos, 
		D2D1::RectF( id->GetRect().left, id->GetRect().top, obj.size.x, obj.size.y ), 
		1.0f );
}


