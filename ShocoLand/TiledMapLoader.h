#pragma once
#include <MDTypedefs.h>

enum TileTextureType
{
	BASE,
	COLLIECTION,
	NONE_TEXTURE,
};
struct TiledTexture
{
	std::string texPath;			// 利用するテクスチャのパス ( 現状 テクスチャの名前 )
	TileTextureType type;		// textureを分割するか、1枚絵として使っているか
	MDVector2 rectSize;		// tile1枚の幅,高さ  ( タイルを作るのに使用したtextureを何ドットで切り取るか )
	MDVector2 startMargin;	// tile左上端の余白
	MDVector2 marginSize;	// tile間の余白( 恐らく、左端、上端にはこの余白を作らない )
};
enum TileLayerType
{
	NORMAL,
	STAGE,
	COLLISION,
	NONE_LAYER,
};
struct TileLayer
{
	TileLayerType type;									// タイル・レイヤータイプ
	std::vector<std::vector<int>> table;	// タイル配置配列
};
struct TiledMapEditor
{	
	MDVector2 blockNum;		// チップを横、縦方向にいくつ並べるか
	MDVector2 tileSize;			// タイル1つあたりの幅、高さ
	std::string orientation;			// ?
	std::vector<TiledTexture> tileTex;			// tileTexture構造体
	std::vector<TileLayer> layer;					// tileLayer構造体
};

class TiledMapLoader
{
public:
	TiledMapLoader();
	~TiledMapLoader();

	bool Load( const LPWSTR fileName );
	void LoadLayer( std::ifstream& fs, std::string& curentLine);

public:
	TiledMapEditor tileMap;
};

