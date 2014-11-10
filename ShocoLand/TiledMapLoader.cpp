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
	ifstream fs( fileName );		// ファイルオープン
	if( !fs )		// ファイルの読み込みに成功
	{
		throw std::runtime_error( "Error:Input data file not found");
		return false;
	}

	tileMap = {};
	string curentLine;
	
	// ファイルの最後に来るまで、ループ
	while( !fs.eof() )
	{
		// 現在の行を読み込む (キーワードチェックの為 )
		fs >> curentLine;

		// 重要なキーワードの検索 
		// 先頭にこのキーワードが無ければ、認めない
		if( 0 == curentLine.find( "[header]" ) )
		{
			while( !fs.eof() )
			{
				fs >> curentLine;

				string glit;
				string parameterName;
				int num;		// glitから取り出した数値
				string strData; // glitから取り出した文字列

				// , は空欄
				// // はコメントアウト
				// [があれば、次のキーワードになった証
				if( 0 == curentLine.find( "," ) ||
					0 == curentLine.find( "//" ) ||
					0 == curentLine.find( "[" ) ) break;

				// パラメータを読み込むため、種類の判定
				// 同じ名前が文字列に含まれているので、=までの文字を切り取り、それと判定させる
				// = がある位置を調べる
				int equalPos = curentLine.find_first_of( "=" );
				parameterName = curentLine.substr( 0, equalPos );			// numが表しているのは、文字列の前で、substrが切り取るのはその間の文字列

				// 数値の取り出し & 数値でないものの取り出し
				// 文字列の数値化
				glit = curentLine.substr( ++equalPos );				// =は飛ばす
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
					istringstream stream( glit );		// 区切り文字で文字列を分ける
					string strComma = "";
					int numParameter;
					TiledTexture tex;

					// tileTypeの判断
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

	fs.close();		// ファイル閉じ

	std::cout << "map幅ブロック数: " << tileMap.blockNum.x << endl;
	std::cout << "map高さブロック数: " << tileMap.blockNum.y << endl;
	std::cout << "タイル1つあたりの幅: " << tileMap.tileSize.x << endl;
	std::cout << "タイル1つあたりの高さ: " << tileMap.tileSize.y << endl;
	std::cout << "マスの基準点: " << tileMap.orientation << endl;
	
	for( auto& t : tileMap.tileTex )
	{
		if( TileTextureType::BASE == t.type )
			std::cout << "TileTextureType::BASE" << endl;
		if( TileTextureType::COLLIECTION == t.type )
			std::cout << "TileTextureType::BASE" << endl;
		else
			std::cout << "TileTextureType::UNNOUN" << endl;

		std::cout << "テクスチャ名: " << t.texPath << endl;
		std::cout << "切り出し幅:" << t.rectSize.x << endl;
		std::cout << "切り出し高さ: " << t.rectSize.y << endl;
		std::cout << "tile開始余白幅 : " << t.startMargin.x << endl;
		std::cout << "tile開始余白高さ: " << t.startMargin.y << endl;
		std::cout << "tile間の幅の余白: " << t.marginSize.x << endl;
		std::cout << "tile間の高さの余白: " << t.marginSize.y << endl;
	}

	for( const auto& l : tileMap.layer ){
		if( TileLayerType::STAGE == l.type )
		std::cout << "レイヤーType: " << "STAGE" << endl;
		else if( TileLayerType::COLLISION == l.type )
			std::cout << "レイヤーType: " << "COLLISION" << endl;
		else
			std::cout << "レイヤーType: UNNOUN" << endl;
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

		// LayerTypeの判断
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
		// mapデータの読み込み
		else if( "data" == parameterName )
		{
			// 読み込んだマップの縦マス数だけ事前に確保しておく
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
					if( layer.table.size() == 0 ) throw std::runtime_error( "tableSize0" );		// 異常

					tileMap.layer.push_back( layer );		// レイヤーの追加
					LoadLayer(  fs, curentLine );
					return;
				}

				// ファイル最後の行に、改行文字が入っていると最後の行が2回読み込まれることに注意!!!!
				// 現状の対応策として、#ENDという終了文字をプランナーに追加してもらうことにする
				// string::nposが見つからない時
				else if( curentLine.find( "#END" ) != string::npos )
				{
					if( layer.table.size() == 0 ) throw std::runtime_error("tableSize0");		// 異常

					tileMap.layer.push_back( layer );		// レイヤーの追加
					//break;
					return;
				}

				string strComma;
				int numComma;
				vector<int> innerMap;		// 読み込んだマップの横マス数だけ事前に確保しておく
				innerMap.reserve( static_cast<unsigned int>(tileMap.blockNum.x) );
				istringstream stream( curentLine );
				stringstream ss;

				while( getline( stream.seekg( 0, ios_base::cur ), strComma, ',' ) )
				{
					ss.str( "" );
					ss.clear( stringstream::goodbit );
					ss << strComma;
					ss >> numComma;
					innerMap.push_back( numComma );		// 行
				}
				layer.table.push_back( innerMap );		// 列
			}

		}
		fs >> curentLine;
	}
}
