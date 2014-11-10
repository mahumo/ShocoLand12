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
	std::string texName;					// �e�N�X�`���� 
	MD2DBitmap* texPtr;					// �e�N�X�`���ւ̃A�h���X			���󃊃\�[�X�ƃQ�[�����ɉ�������Ƃ܂���
	MDRectF texRect;						// texture�؂���͈�
	TileTextureType texType;				// �e�N�X�`���̕����^�C�v
};

/// -----------------------------------------------------------------------
/// tileID���Ǘ�����N���X
/// -----------------------------------------------------------------------
class TileIDMap :private MDUncopyable
{
public:
	TileIDMap() = default;
	~TileIDMap() = default;

	// move���Ă邱�Ƃɒ���!!
	bool Add( int key, TileID* id );
	bool ChackKey( int key );
	std::unique_ptr<TileID>& GetValue( int key );

private:
	std::unordered_map<int, std::unique_ptr<TileID>> texID = {};
};

