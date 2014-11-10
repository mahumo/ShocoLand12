#pragma once
#include <comdef.h>	// COM?
#pragma warning(disable:4996)

class Wave
{
public:
	Wave();
	~Wave();
	bool Load( TCHAR* FileName );
	WAVEFORMATEX		waveFormat;	// Waveフォーマット
	byte*						waveData;		// soundデータ
	int							dataSize;			// データサイズ
};

