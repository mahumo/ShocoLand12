#include "TiledMap.h"

#include "StringConvert.h"
#include "MDBitMapKey.h"
#include "TiledMapObj.h"
#include "TiledTextureFactory.h"
#include "TiledObjFactory.h"


using namespace std;

void TiledMap::Initialize()
{
	map = make_shared<TiledMapLoader>();		// 生成

	map->Load( L"Resource/map7.csv" );				// csv読み込み

	
	// csvからマップチップで使用するテクスチャを生成する
	for( const auto& t : map->tileMap.tileTex )
		MDBitMapKey::Instance()->Add( "Resource/", t.texPath );
	/// -----------------------------------------------------------------------
	/// TileMapEditorのtextデータから、必要なテクスチャをサイズごとにカット
	/// TileIDのキーにして、登録していく
	/// -----------------------------------------------------------------------
	TiledTextureFactory tileTexFactory;
	tileTexFactory.InitializeID();
	// 全てのテクスチャをtileサイズに分割して、それぞれ登録していく
	for( auto& t : map->tileMap.tileTex )
		tileTexFactory.Create( t, idMap );


	// -----------------------------------------------------------------------
	// TileMapEditorからマップデータを取得し、ゲームオブジェクトとして
	// 登録していく	 
	/*
	現状プログラム側で、途中で指定したものを追加することが容易ではない
	 ID番号の直接していしか出来ないのである
	[例]	理想 ○○オブジェクト追加
			現実 1番追加  

	ゲーム中に追加していくようなオブジェクトは、
	別に読み込んでいくロジックにした方が良い											*/
	TiledObjFactory tileObjFactory;
	tileObjFactory.Create( TileLayerType::NORMAL, map->tileMap, idMap, tiledObjManager );

}
void TiledMap::Update()
{

}
void TiledMap::Draw( MD2DHelper& help2D ) 
{
	// とりあえず
	//std::vector<TileLayer> stageLayer;

	//// ステージレイヤーを抽出
	//for(auto& layer:map->tileMap.layer)
	//	if( TileLayerType::STAGE == layer.type )
	//		stageLayer.push_back( layer );

	//// ステージレイヤーだけ描画
	//LayerDraw( help2D, stageLayer, TileTextureType::BASE );
	//LayerDraw( help2D, stageLayer, TileTextureType::COLLIECTION );

	tiledObjManager.Draw( help2D,idMap, TileTextureType::BASE );
	tiledObjManager.Draw( help2D, idMap, TileTextureType::COLLIECTION );

	//vector<vector<int>&> tileOnce;
	//vector<vector<int>&> tileCut;
	//
	//for( auto& layer : stageLayer )
	//{
	//	for( layer.table )
	//}
}

void TiledMap::LayerDraw( MD2DHelper& help2D, std::vector<TileLayer>& _layer, const TileTextureType& type )
{
	// ステージレイヤーだけ描画
	for( auto& layer : _layer )
	{
		// 列
		int mapY = 1;
		for( auto& y : layer.table )
		{
			// 行
			int mapX = 1;
			for( auto& x : y )
			{
				if( 0 == x )
				{
					++mapX;
					continue;
				}

				auto& tileObj = idMap.GetValue( x );

				// 指定したtextureタイプでなければ、描画しない
				if( type != tileObj->GetTextureType() )
				{
					++mapX;
					continue;
				}
				help2D.BitMap(
					tileObj->GetTexture(),
					MDVector2( (mapX - 1)*map->tileMap.tileSize.x , (mapY - 1)*map->tileMap.tileSize.y ),
					tileObj->GetRect(),
					1.0f );
				++mapX;
			}
			++mapY;
		}
	}
}
