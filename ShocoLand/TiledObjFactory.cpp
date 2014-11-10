#include "TiledObjFactory.h"
#include "TiledMapLoader.h"
#include "TileIDMap.h"
#include "TiledMapObj.h"
#include "TiledMapObjManagerd.h"

// TileMapEditor����}�b�v�f�[�^���擾���A�Q�[���I�u�W�F�N�g�Ƃ���
// �o�^���Ă���	 
void TiledObjFactory::Create( const TileLayerType& layerType, const TiledMapEditor& editor, TileIDMap& idMap, TiledMapObjManager& manager )
{
	/*
	����v���O�������ŁA�r���Ŏw�肵�����̂�ǉ����邱�Ƃ��e�Ղł͂Ȃ�
	ID�ԍ��̒��ڂ��Ă������o���Ȃ��̂ł���
	[��]	���z �����I�u�W�F�N�g�ǉ�
	���� 1�Ԓǉ�

	�Q�[�����ɒǉ����Ă����悤�ȃI�u�W�F�N�g�́A
	�ʂɓǂݍ���ł������W�b�N�ɂ��������ǂ�											*/
	for( const auto& layer : editor.layer )
	{
		if( layerType != layer.type )
		{
			int mapY = 0;
			for( const auto& tableY : layer.table )
			{
				int mapX = 0;
				for( const auto& id : tableY )
				{
					// tile�ԍ�0�͑��݂��Ȃ��̂ŁA�e��
					if( 0 == id )
					{
						++mapX;
						continue;
					}

					// ���W�̎��O�v�Z
					auto& rect = idMap.GetValue( id )->GetRect();
					MDGameObj2D gameObj = { MDVector2( (mapX - 1)* editor.tileSize.x, (mapY - 1)*editor.tileSize.y ), MDVector2( rect.right, rect.bottom ) };

					// �Q�[���I�u�W�F�N�g�Ƃ��ēo�^
					TiledMapObj* obj = new TiledMapObj( gameObj, MDVector2( (float)mapX, (float)mapY ), id );
					manager.Add( obj );
					++mapX;
				}
				++mapY;
			}
		}
	}
}
