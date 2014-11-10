#include "StringConvert.h"

const std::string MDStringConvert::TWStringToString( const std::wstring& arg_wstr )
{
	// ������
	size_t length = arg_wstr.size();
	// �ϊ��㕶����
	size_t convLength;
	// ���̎󂯎M��p�Ӂi�������~2�����\���ł��傤�j
	char *c = (char*)malloc( sizeof( char )* length * 2 );
	// �ϊ�
	wcstombs_s( &convLength, c, sizeof( char ) * length * 2, arg_wstr.c_str(), length * 2 );
	// �Ԃ�l�֕ۑ�
	std::string result( c );
	// ���̎󂯎M��j��
	free( c );
	return result;
};

//! ���C�h�����񉻊֐�
const std::wstring MDStringConvert::StringToWString( const std::string& arg_str )
{
	// ������
	size_t length = arg_str.size();
	// �ϊ��㕶����
	size_t convLength;
	// ���̎󂯎M��p��
	wchar_t *wc = (wchar_t*)malloc( sizeof( wchar_t )* (length + 2) );
	// �ϊ�
	mbstowcs_s( &convLength, wc, length + 1, arg_str.c_str(), _TRUNCATE );
	// �Ԃ�l�֕ۑ�
	std::wstring str( wc );
	// ���̎󂯎M��j��
	free( wc );

	return str;
};