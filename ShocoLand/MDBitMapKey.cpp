#include "MDBitMapKey.h"
#include "StringConvert.h"

using namespace std;

// 要素追加
bool MDBitMapKey::Add( const std::string& path, const std::string& key )
{
	//// moveするから、keyをコピーしておく
	//const auto _key = key;

	if( ChackKey( key ) ){
		MDStringConvert c;
		auto tex = make_unique<MD2DBitmap>();
		tex->Create( c.StringToWString( path+key ).c_str() );		// wstringへ変換が必要

		// moveするから、keyだけはコピーしなければならないことに注意!!
		auto valuePair = pair<string, std::unique_ptr<MD2DBitmap>>( key, move( tex ) );
		texNameNumber.insert( move( valuePair ) );
		return true;
	}
	return false;
}

// 同じkeyは受け付けない用にする
bool MDBitMapKey::ChackKey( const std::string& key )
{
	return ( 0 == texNameNumber.count( key ) );
}

// textureを渡す
unique_ptr<MD2DBitmap>& MDBitMapKey::GetValue( const std::string& key )
{
	return texNameNumber.at( key );
}
