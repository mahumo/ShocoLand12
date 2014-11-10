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
	std::string texPath;			// ���p����e�N�X�`���̃p�X ( ���� �e�N�X�`���̖��O )
	TileTextureType type;		// texture�𕪊����邩�A1���G�Ƃ��Ďg���Ă��邩
	MDVector2 rectSize;		// tile1���̕�,����  ( �^�C�������̂Ɏg�p����texture�����h�b�g�Ő؂��邩 )
	MDVector2 startMargin;	// tile����[�̗]��
	MDVector2 marginSize;	// tile�Ԃ̗]��( ���炭�A���[�A��[�ɂ͂��̗]�������Ȃ� )
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
	TileLayerType type;									// �^�C���E���C���[�^�C�v
	std::vector<std::vector<int>> table;	// �^�C���z�u�z��
};
struct TiledMapEditor
{	
	MDVector2 blockNum;		// �`�b�v�����A�c�����ɂ������ׂ邩
	MDVector2 tileSize;			// �^�C��1������̕��A����
	std::string orientation;			// ?
	std::vector<TiledTexture> tileTex;			// tileTexture�\����
	std::vector<TileLayer> layer;					// tileLayer�\����
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

