#pragma once
#include <string>

// GitHubに上がっていたものをそのまま使っている不安
// https://gist.github.com/TAMAGO-JP/31f0030d26b321a9548e
class MDStringConvert
{
public:
	MDStringConvert() = default;
	~MDStringConvert() = default;

	//! シングルバイト、マルチバイト文字列化関数
	const std::string TWStringToString( const std::wstring& arg_wstr );
	//! ワイド文字列化関数
	const std::wstring StringToWString( const std::string& arg_str );
};

