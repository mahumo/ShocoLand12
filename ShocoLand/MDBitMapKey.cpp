#include "MDBitMapKey.h"
#include "StringConvert.h"

using namespace std;

// �v�f�ǉ�
bool MDBitMapKey::Add( const std::string& path, const std::string& key )
{
	//// move���邩��Akey���R�s�[���Ă���
	//const auto _key = key;

	if( ChackKey( key ) ){
		MDStringConvert c;
		auto tex = make_unique<MD2DBitmap>();
		tex->Create( c.StringToWString( path+key ).c_str() );		// wstring�֕ϊ����K�v

		// move���邩��Akey�����̓R�s�[���Ȃ���΂Ȃ�Ȃ����Ƃɒ���!!
		auto valuePair = pair<string, std::unique_ptr<MD2DBitmap>>( key, move( tex ) );
		texNameNumber.insert( move( valuePair ) );
		return true;
	}
	return false;
}

// ����key�͎󂯕t���Ȃ��p�ɂ���
bool MDBitMapKey::ChackKey( const std::string& key )
{
	return ( 0 == texNameNumber.count( key ) );
}

// texture��n��
unique_ptr<MD2DBitmap>& MDBitMapKey::GetValue( const std::string& key )
{
	return texNameNumber.at( key );
}
