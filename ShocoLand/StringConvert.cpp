#include "StringConvert.h"

const std::string MDStringConvert::TWStringToString( const std::wstring& arg_wstr )
{
	// 文字数
	size_t length = arg_wstr.size();
	// 変換後文字数
	size_t convLength;
	// 仮の受け皿を用意（文字数×2ありゃ十分でしょう）
	char *c = (char*)malloc( sizeof( char )* length * 2 );
	// 変換
	wcstombs_s( &convLength, c, sizeof( char ) * length * 2, arg_wstr.c_str(), length * 2 );
	// 返り値へ保存
	std::string result( c );
	// 仮の受け皿を破棄
	free( c );
	return result;
};

//! ワイド文字列化関数
const std::wstring MDStringConvert::StringToWString( const std::string& arg_str )
{
	// 文字数
	size_t length = arg_str.size();
	// 変換後文字数
	size_t convLength;
	// 仮の受け皿を用意
	wchar_t *wc = (wchar_t*)malloc( sizeof( wchar_t )* (length + 2) );
	// 変換
	mbstowcs_s( &convLength, wc, length + 1, arg_str.c_str(), _TRUNCATE );
	// 返り値へ保存
	std::wstring str( wc );
	// 仮の受け皿を破棄
	free( wc );

	return str;
};