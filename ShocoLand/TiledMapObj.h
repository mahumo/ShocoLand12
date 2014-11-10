#pragma once

class TileID;
class TileIDMap;
#include "LibInclude.h"
#include "MDCollision2D.h"

class TiledMapObj
{
public:
	TiledMapObj();
	TiledMapObj(MDGameObj2D& obj2d, MDVector2& mapNum, int tileId );
	~TiledMapObj() = default;

	MDGameObj2D& GetGameObjct();
	MDVector2&			GetPosition();
	MDVector2&			GetSize();
	MDVector2&			GetCenter();
	MDVector2&			GetMapNumber();
	int						GetTileID();

	void	SetPosition( const MDVector2& pos );
	void Trancelate( const MDVector2& vec );
	void	SetSize( const MDVector2& size );
	void	SetPoint( const MDVector2& point );
	void	Draw( MD2DHelper& helper, TileIDMap& mapID );	// �ʏ�`��
	void Draw( MD2DHelper& helper, std::unique_ptr<TileID>& id );					// �`�悷�邩�̃t�B���^�I��?

private:
	MDGameObj2D obj;					// ��{���W�f�[�^
	MDVector2 mapNumber;				// �z��ԍ�
	int tileID;										// tile�}�b�v�ւ�ID
};




