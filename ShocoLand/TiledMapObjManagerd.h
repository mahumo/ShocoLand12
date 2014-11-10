#pragma once

enum TileTextureType;
//class TileIDMap;
// �Ȃ����A��肭��s�錾�o���Ȃ�
#include "TiledMapObj.h"

#include "LibInclude.h"
class TiledMapObjManager
{
public:
	TiledMapObjManager() = default;
	~TiledMapObjManager() = default;

	void Add( TiledMapObj* obj );
	void Draw( MD2DHelper& helper, TileIDMap& id );																	// �S�ẴI�u�W�F�N�g��`��
	void Draw( MD2DHelper& helper, TileIDMap& id, const TileTextureType& type );					// �w�肵��TileTexturetype���݂�`��

private:
	std::vector<std::unique_ptr<TiledMapObj>> objs;
};

