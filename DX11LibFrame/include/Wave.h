#pragma once
#include <comdef.h>	// COM?
#pragma warning(disable:4996)

class Wave
{
public:
	Wave();
	~Wave();
	bool Load( TCHAR* FileName );
	WAVEFORMATEX		waveFormat;	// Wave�t�H�[�}�b�g
	byte*						waveData;		// sound�f�[�^
	int							dataSize;			// �f�[�^�T�C�Y
};

