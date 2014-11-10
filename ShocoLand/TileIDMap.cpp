#include "TileIDMap.h"
#include "MDBitMapKey.h"
using namespace std;

TileID::TileID( const std::string& name, MD2DBitmap* ptr, const MDRectF& rect, const TileTextureType& type ) :
texName( name ),
texPtr( ptr ),
texRect( rect ),
texType(type)
{
}

std::string&  TileID::GetTextureName() 
{
	return texName;
}
MD2DBitmap* TileID::GetTexture()
{
	return texPtr;
}
MDRectF& TileID::GetRect()
{
	return texRect;
}
TileTextureType& TileID::GetTextureType()
{
	return texType;
}

//void TileID::SearchTexture()
//{
//	texPtr = MDBitMapKey::Instance()->GetValue( texName ).get();
//}
//void  TileID::ComputeTexRect( TiledTexture tile )
//{
//	MDRectF f = D2D1::RectF(
//		tile.startMargin.x, tile.startMargin.y, tile.rectSize.x, tile.rectSize.y );
//	tile.
//}

/// -----------------------------------------------------------------------
/// TileIDMap
/// -----------------------------------------------------------------------
bool TileIDMap::Add( int key, TileID* id )
{
	bool hit = ChackKey( key );

	// “¯‚¶key‚ª‘¶İ‚µ‚È‚¯‚ê‚ÎA’Ç‰Á
	if( !hit )
	{
		// move‚µ‚Ä‚é‚±‚Æ‚É’ˆÓ!!
		auto valuePair = pair<int, unique_ptr<TileID>>( key, move(unique_ptr<TileID>( id )) );
		texID.insert( move( valuePair ) );
	}
	return hit;
}

// key—L–³
bool TileIDMap::ChackKey( int key )
{
	return (0 != texID.count( key ));
}

// ID‚ğ“n‚·
unique_ptr<TileID>& TileIDMap::GetValue( int key )
{
	return texID.at(key);
}

