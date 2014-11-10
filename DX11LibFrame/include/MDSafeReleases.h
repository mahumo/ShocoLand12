#ifndef MDSAFERELEASE_H
#define MDSAFERELEASE_H 

#include <WinUser.h>

//	SafeRelease : �_�u���|�C���^��
template<class Interface>
inline void
SafeRelease( Interface **ppInterfaceToRelease )
{
	if( *ppInterfaceToRelease != nullptr )
	{
		(*ppInterfaceToRelease)->Release();

		(*ppInterfaceToRelease) = nullptr;
	}
}

template<class T>
inline void
SafeDeleteArray( T** ppDeleteArray )
{
	if( *ppDeleteArray != nullptr )
	{
		delete[]( *ppDeleteArray );
		
		(*ppDeleteArray) = nullptr;
	}
}

template<class T>
inline void
SafeDelete( T** ppDelete )
{
	if( *ppDelete != nullptr )
	{
		delete (*ppDelete);

		(*ppDelete) = nullptr;
	}
}

//	�G���[���b�Z�[�W�o�͗p�̊ȈՊ֐�
inline void ErrMsg( LPCWSTR text )
{
	MessageBoxW( nullptr, text, L"error", MB_OK );
}

inline void ErrMsg( char* text )
{
	MessageBoxA( nullptr, text, "error", MB_OK );
}
#endif
