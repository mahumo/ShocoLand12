#include "TiledTextureFactory.h"
#include "LibInclude.h"
#include "TiledMapLoader.h"
#include "TileIDMap.h"
#include "MDBitMapKey.h"


TiledTextureFactory::TiledTextureFactory() :
id( 1 )
{
}


void TiledTextureFactory::Create( TiledTexture& tiledTexture, TileIDMap& idMap )
{
	// 1枚のテクスチャとして使う
	if( TileTextureType::COLLIECTION == tiledTexture.type )
	{
		const auto& tex = MDBitMapKey::Instance()->GetValue( tiledTexture.texPath );
		TileID* tileID = new TileID(
			tiledTexture.texPath,
			tex.get(),
			D2D1::RectF( tiledTexture.startMargin.x, tiledTexture.startMargin.y, tiledTexture.rectSize.x, tiledTexture.rectSize.y ),
			tiledTexture.type );

		idMap.Add( id, tileID );		// tileの登録
		++id;									// tile番号を進める
	}
	// テクスチャを分割して使う
	else if( TileTextureType::BASE == tiledTexture.type )
	{
		const auto& tex = MDBitMapKey::Instance()->GetValue( tiledTexture.texPath );
		// 縦横それぞれにtextureを、tile何分割になるか計算 ( 仕様で、map番号を+1 )
		// 1つ辺りの分割サイズは現状縦横共に、同じであることを前提にしています。
		// 分割無しのtileをただ配置することは出来ても、サイズを考慮し、重ならないよう配置することは出来ないので注意
		MDVector2 tileCutNum = tex->GetImageSize() / tiledTexture.rectSize + MDVector2( 1, 1 );

		// このテクスチャの分割数と前回までの、ID番号の合計が限界値となる
		const int maxCutNum = (int)tileCutNum.x * (int)tileCutNum.y + id;

		// このテクスチャを分割した最後のIDを超えるまで回す
		while( maxCutNum >= id )
		{
			// idを2次元配列に変換
			int rectMapY = (id - 1) / (int)(tileCutNum.x - 1);
			int rectMapX = (id - 1) % (int)(tileCutNum.x - 1);
			MDRectF r = D2D1::RectF( rectMapX*tiledTexture.rectSize.x, rectMapY*tiledTexture.rectSize.y, tiledTexture.rectSize.x, tiledTexture.rectSize.y );
			TileID* tileID = new TileID( tiledTexture.texPath, tex.get(), r, tiledTexture.type );
			idMap.Add( id, tileID );
			++id;
		}
	}	// tile type End
}

void TiledTextureFactory::InitializeID()
{
	id = 1;
}
