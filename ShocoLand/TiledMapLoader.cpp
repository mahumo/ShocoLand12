#include "TiledMapLoader.h"

using namespace std;

TiledMapLoader::TiledMapLoader()
{
}


TiledMapLoader::~TiledMapLoader()
{
}

bool TiledMapLoader::Load( const LPWSTR fileName )
{
	ifstream fs( fileName );		// �t�@�C���I�[�v��
	if( !fs )		// �t�@�C���̓ǂݍ��݂ɐ���
	{
		throw std::runtime_error( "Error:Input data file not found");
		return false;
	}

	tileMap = {};
	string curentLine;
	
	// �t�@�C���̍Ō�ɗ���܂ŁA���[�v
	while( !fs.eof() )
	{
		// ���݂̍s��ǂݍ��� (�L�[���[�h�`�F�b�N�̈� )
		fs >> curentLine;

		// �d�v�ȃL�[���[�h�̌��� 
		// �擪�ɂ��̃L�[���[�h��������΁A�F�߂Ȃ�
		if( 0 == curentLine.find( "[header]" ) )
		{
			while( !fs.eof() )
			{
				fs >> curentLine;

				string glit;
				string parameterName;
				int num;		// glit������o�������l
				string strData; // glit������o����������

				// , �͋�
				// // �̓R�����g�A�E�g
				// [������΁A���̃L�[���[�h�ɂȂ�����
				if( 0 == curentLine.find( "," ) ||
					0 == curentLine.find( "//" ) ||
					0 == curentLine.find( "[" ) ) break;

				// �p�����[�^��ǂݍ��ނ��߁A��ނ̔���
				// �������O��������Ɋ܂܂�Ă���̂ŁA=�܂ł̕�����؂���A����Ɣ��肳����
				// = ������ʒu�𒲂ׂ�
				int equalPos = curentLine.find_first_of( "=" );
				parameterName = curentLine.substr( 0, equalPos );			// num���\���Ă���̂́A������̑O�ŁAsubstr���؂���̂͂��̊Ԃ̕�����

				// ���l�̎��o�� & ���l�łȂ����̂̎��o��
				// ������̐��l��
				glit = curentLine.substr( ++equalPos );				// =�͔�΂�
				stringstream ss( glit );
				ss >> num;

				if( "width" == parameterName )
				{
					tileMap.blockNum.x = static_cast<float>(num);
				}
				else if( "height" == parameterName )
				{
					tileMap.blockNum.y = static_cast<float>(num);
				}
				else if( "tilewidth" == parameterName )
				{
					tileMap.tileSize.x = static_cast<float>(num);
				}
				else if( "tileheight" == parameterName )
				{
					tileMap.tileSize.y = static_cast<float>(num);
				}
				else if( "orientation" == parameterName )
				{
					int commaPos = glit.find( "," );
					strData = glit.substr( 0, commaPos );
					tileMap.orientation = strData;
				}
			}
		}		// [header]chack end

		else if( 0 == curentLine.find( "[tilesets]" ) )
		{
			while( !fs.eof() )
			{
				fs >> curentLine;

				if( 0 == curentLine.find( "," ) ||
					0 == curentLine.find( "//" ) ||
					0 == curentLine.find( "[" ) ) break;

				string glit;
				string parameterName;

				int equalPos = curentLine.find( "=" );
				parameterName = curentLine.substr( 0, equalPos );
				glit = curentLine.substr( ++equalPos );

				if( "tileset" == parameterName )
				{
					istringstream stream( glit );		// ��؂蕶���ŕ�����𕪂���
					string strComma = "";
					int numParameter;
					TiledTexture tex;

					// tileType�̔��f
					getline( stream.seekg( 0, ios_base::cur ), strComma, ',' );
					if( "#C" == strComma )
						tex.type = TileTextureType::COLLIECTION;
					else if( "#B" == strComma )
						tex.type = TileTextureType::BASE;
					else return false;

					getline( stream.seekg( 0, ios_base::cur ), strComma, ',' );
					tex.texPath = strComma;


					getline( stream.seekg( 0, ios_base::cur ), strComma, ',' );
					stringstream ss( strComma );
					ss >> numParameter;
					tex.rectSize.x = static_cast<float>(numParameter);

					ss.str( "" );
					ss.clear( stringstream::goodbit );
					getline( stream.seekg( 0, ios_base::cur ), strComma, ',' );
					ss << strComma;
					ss >> numParameter;
					tex.rectSize.y = static_cast<float>(numParameter);


					ss.str( "" );
					ss.clear( stringstream::goodbit );
					getline( stream.seekg( 0, ios_base::cur ), strComma, ',' );
					ss << strComma;
					ss >> numParameter;
					tex.startMargin.x = static_cast<float>(numParameter);
					tex.startMargin.y = static_cast<float>(numParameter);


					ss.str( "" );
					ss.clear( stringstream::goodbit );
					getline( stream.seekg( 0, ios_base::cur ), strComma, ',' );
					ss << strComma;
					ss >> numParameter;
					tex.marginSize.x = static_cast<float>(numParameter);
					tex.marginSize.y = static_cast<float>(numParameter);

					tileMap.tileTex.push_back( tex );
				}
			}
		}
		else if( 0 == curentLine.find( "[layer]" ) )
		{
			fs >> curentLine;
			LoadLayer( fs, curentLine );
		}
	}

	fs.close();		// �t�@�C����

	std::cout << "map���u���b�N��: " << tileMap.blockNum.x << endl;
	std::cout << "map�����u���b�N��: " << tileMap.blockNum.y << endl;
	std::cout << "�^�C��1������̕�: " << tileMap.tileSize.x << endl;
	std::cout << "�^�C��1������̍���: " << tileMap.tileSize.y << endl;
	std::cout << "�}�X�̊�_: " << tileMap.orientation << endl;
	
	for( auto& t : tileMap.tileTex )
	{
		if( TileTextureType::BASE == t.type )
			std::cout << "TileTextureType::BASE" << endl;
		if( TileTextureType::COLLIECTION == t.type )
			std::cout << "TileTextureType::BASE" << endl;
		else
			std::cout << "TileTextureType::UNNOUN" << endl;

		std::cout << "�e�N�X�`����: " << t.texPath << endl;
		std::cout << "�؂�o����:" << t.rectSize.x << endl;
		std::cout << "�؂�o������: " << t.rectSize.y << endl;
		std::cout << "tile�J�n�]���� : " << t.startMargin.x << endl;
		std::cout << "tile�J�n�]������: " << t.startMargin.y << endl;
		std::cout << "tile�Ԃ̕��̗]��: " << t.marginSize.x << endl;
		std::cout << "tile�Ԃ̍����̗]��: " << t.marginSize.y << endl;
	}

	for( const auto& l : tileMap.layer ){
		if( TileLayerType::STAGE == l.type )
		std::cout << "���C���[Type: " << "STAGE" << endl;
		else if( TileLayerType::COLLISION == l.type )
			std::cout << "���C���[Type: " << "COLLISION" << endl;
		else
			std::cout << "���C���[Type: UNNOUN" << endl;
	}

	return true;
}

void TiledMapLoader::LoadLayer( std::ifstream& fs, std::string& curentLine )
{
	TileLayer layer;
	while( !fs.eof() )
	{
		if( 0 == curentLine.find( "," ) ||
			0 == curentLine.find( "//" ) ||
			0 == curentLine.find( "[" ) ) break;

		string glit;
		string parameterName;

		int equalPos = curentLine.find( "=" );
		parameterName = curentLine.substr( 0, equalPos );
		glit = curentLine.substr( ++equalPos );

		// LayerType�̔��f
		if( "type" == parameterName )
		{
			int commaPos = glit.find( "," );
			glit = glit.substr( 0, commaPos );

			if( "stage" == glit )
				layer.type = TileLayerType::STAGE;
			else if( "collision" == glit )
				layer.type = TileLayerType::COLLISION;
			else
				layer.type = TileLayerType::NORMAL;
		}
		// map�f�[�^�̓ǂݍ���
		else if( "data" == parameterName )
		{
			// �ǂݍ��񂾃}�b�v�̏c�}�X���������O�Ɋm�ۂ��Ă���
			layer.table.reserve( static_cast<unsigned int>(tileMap.blockNum.y) );

			while( !fs.eof() )
			{
				fs >> curentLine;

				while( 0 == curentLine.find( "," ) || 0 == curentLine.find( "//" ) )
				{
					fs >> curentLine;
				}

				if(	0 == curentLine.find( "[" ) )
				{
					fs >> curentLine;
					if( layer.table.size() == 0 ) throw std::runtime_error( "tableSize0" );		// �ُ�

					tileMap.layer.push_back( layer );		// ���C���[�̒ǉ�
					LoadLayer(  fs, curentLine );
					return;
				}

				// �t�@�C���Ō�̍s�ɁA���s�����������Ă���ƍŌ�̍s��2��ǂݍ��܂�邱�Ƃɒ���!!!!
				// ����̑Ή���Ƃ��āA#END�Ƃ����I���������v�����i�[�ɒǉ����Ă��炤���Ƃɂ���
				// string::npos��������Ȃ���
				else if( curentLine.find( "#END" ) != string::npos )
				{
					if( layer.table.size() == 0 ) throw std::runtime_error("tableSize0");		// �ُ�

					tileMap.layer.push_back( layer );		// ���C���[�̒ǉ�
					//break;
					return;
				}

				string strComma;
				int numComma;
				vector<int> innerMap;		// �ǂݍ��񂾃}�b�v�̉��}�X���������O�Ɋm�ۂ��Ă���
				innerMap.reserve( static_cast<unsigned int>(tileMap.blockNum.x) );
				istringstream stream( curentLine );
				stringstream ss;

				while( getline( stream.seekg( 0, ios_base::cur ), strComma, ',' ) )
				{
					ss.str( "" );
					ss.clear( stringstream::goodbit );
					ss << strComma;
					ss >> numComma;
					innerMap.push_back( numComma );		// �s
				}
				layer.table.push_back( innerMap );		// ��
			}

		}
		fs >> curentLine;
	}
}
