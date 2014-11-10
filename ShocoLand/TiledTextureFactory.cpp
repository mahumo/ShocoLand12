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
	// 1���̃e�N�X�`���Ƃ��Ďg��
	if( TileTextureType::COLLIECTION == tiledTexture.type )
	{
		const auto& tex = MDBitMapKey::Instance()->GetValue( tiledTexture.texPath );
		TileID* tileID = new TileID(
			tiledTexture.texPath,
			tex.get(),
			D2D1::RectF( tiledTexture.startMargin.x, tiledTexture.startMargin.y, tiledTexture.rectSize.x, tiledTexture.rectSize.y ),
			tiledTexture.type );

		idMap.Add( id, tileID );		// tile�̓o�^
		++id;									// tile�ԍ���i�߂�
	}
	// �e�N�X�`���𕪊����Ďg��
	else if( TileTextureType::BASE == tiledTexture.type )
	{
		const auto& tex = MDBitMapKey::Instance()->GetValue( tiledTexture.texPath );
		// �c�����ꂼ���texture���Atile�������ɂȂ邩�v�Z ( �d�l�ŁAmap�ԍ���+1 )
		// 1�ӂ�̕����T�C�Y�͌���c�����ɁA�����ł��邱�Ƃ�O��ɂ��Ă��܂��B
		// ����������tile�������z�u���邱�Ƃ͏o���Ă��A�T�C�Y���l�����A�d�Ȃ�Ȃ��悤�z�u���邱�Ƃ͏o���Ȃ��̂Œ���
		MDVector2 tileCutNum = tex->GetImageSize() / tiledTexture.rectSize + MDVector2( 1, 1 );

		// ���̃e�N�X�`���̕������ƑO��܂ł́AID�ԍ��̍��v�����E�l�ƂȂ�
		const int maxCutNum = (int)tileCutNum.x * (int)tileCutNum.y + id;

		// ���̃e�N�X�`���𕪊������Ō��ID�𒴂���܂ŉ�
		while( maxCutNum >= id )
		{
			// id��2�����z��ɕϊ�
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
