#include "TiledMap.h"

#include "StringConvert.h"
#include "MDBitMapKey.h"
#include "TiledMapObj.h"
#include "TiledTextureFactory.h"
#include "TiledObjFactory.h"


using namespace std;

void TiledMap::Initialize()
{
	map = make_shared<TiledMapLoader>();		// ����

	map->Load( L"Resource/map7.csv" );				// csv�ǂݍ���

	
	// csv����}�b�v�`�b�v�Ŏg�p����e�N�X�`���𐶐�����
	for( const auto& t : map->tileMap.tileTex )
		MDBitMapKey::Instance()->Add( "Resource/", t.texPath );
	/// -----------------------------------------------------------------------
	/// TileMapEditor��text�f�[�^����A�K�v�ȃe�N�X�`�����T�C�Y���ƂɃJ�b�g
	/// TileID�̃L�[�ɂ��āA�o�^���Ă���
	/// -----------------------------------------------------------------------
	TiledTextureFactory tileTexFactory;
	tileTexFactory.InitializeID();
	// �S�Ẵe�N�X�`����tile�T�C�Y�ɕ������āA���ꂼ��o�^���Ă���
	for( auto& t : map->tileMap.tileTex )
		tileTexFactory.Create( t, idMap );


	// -----------------------------------------------------------------------
	// TileMapEditor����}�b�v�f�[�^���擾���A�Q�[���I�u�W�F�N�g�Ƃ���
	// �o�^���Ă���	 
	/*
	����v���O�������ŁA�r���Ŏw�肵�����̂�ǉ����邱�Ƃ��e�Ղł͂Ȃ�
	 ID�ԍ��̒��ڂ��Ă������o���Ȃ��̂ł���
	[��]	���z �����I�u�W�F�N�g�ǉ�
			���� 1�Ԓǉ�  

	�Q�[�����ɒǉ����Ă����悤�ȃI�u�W�F�N�g�́A
	�ʂɓǂݍ���ł������W�b�N�ɂ��������ǂ�											*/
	TiledObjFactory tileObjFactory;
	tileObjFactory.Create( TileLayerType::NORMAL, map->tileMap, idMap, tiledObjManager );

}
void TiledMap::Update()
{

}
void TiledMap::Draw( MD2DHelper& help2D ) 
{
	// �Ƃ肠����
	//std::vector<TileLayer> stageLayer;

	//// �X�e�[�W���C���[�𒊏o
	//for(auto& layer:map->tileMap.layer)
	//	if( TileLayerType::STAGE == layer.type )
	//		stageLayer.push_back( layer );

	//// �X�e�[�W���C���[�����`��
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
	// �X�e�[�W���C���[�����`��
	for( auto& layer : _layer )
	{
		// ��
		int mapY = 1;
		for( auto& y : layer.table )
		{
			// �s
			int mapX = 1;
			for( auto& x : y )
			{
				if( 0 == x )
				{
					++mapX;
					continue;
				}

				auto& tileObj = idMap.GetValue( x );

				// �w�肵��texture�^�C�v�łȂ���΁A�`�悵�Ȃ�
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
