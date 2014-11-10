#pragma once
#include "LibInclude.h"
#include "TiledMapLoader.h"

class TileID
{
public:
	TileID( const std::string& name, const TileTextureType& type );
	TileID( const std::string& name, MD2DBitmap* ptr, const MDRectF& rect ,const TileTextureType& type);
	~TileID() = default;

	std::string& GetTextureName();
	MD2DBitmap* GetTexture();
	MDRectF& GetRect();
	TileTextureType& GetTextureType();

	//void SearchTexture();
	//void  ComputeTexRect( TiledTexture tile);

private:
	std::string texName;					// テクスチャ名 
	MD2DBitmap* texPtr;					// テクスチャへのアドレス			現状リソースとゲーム中に解放されるとまずい
	MDRectF texRect;						// texture切り取り範囲
	TileTextureType texType;				// テクスチャの分割タイプ
};

/// -----------------------------------------------------------------------
/// tileIDを管理するクラス
/// -----------------------------------------------------------------------
class TileIDMap :private MDUncopyable
{
public:
	TileIDMap() = default;
	~TileIDMap() = default;

	// moveしてることに注意!!
	bool Add( int key, TileID* id );
	bool ChackKey( int key );
	std::unique_ptr<TileID>& GetValue( int key );

private:
	std::unordered_map<int, std::unique_ptr<TileID>> texID = {};
};

