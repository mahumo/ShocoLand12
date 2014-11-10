#pragma once
#include <string>

// GitHub�ɏオ���Ă������̂����̂܂܎g���Ă���s��
// https://gist.github.com/TAMAGO-JP/31f0030d26b321a9548e
class MDStringConvert
{
public:
	MDStringConvert() = default;
	~MDStringConvert() = default;

	//! �V���O���o�C�g�A�}���`�o�C�g�����񉻊֐�
	const std::string TWStringToString( const std::wstring& arg_wstr );
	//! ���C�h�����񉻊֐�
	const std::wstring StringToWString( const std::string& arg_str );
};

