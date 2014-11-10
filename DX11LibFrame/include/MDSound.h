#pragma once
#define DIRECTSOUND_VERSION 0x800

#include "MDCore.h"
#include "MDUncopyable.h"
#include <memory>

// DirectSound�֘A�C���N���[�h����------
#include <dsound.h>
#pragma comment(lib, "dsound.lib")						// DirectSound

class MDSound :private MDUncopyable
{
public:
	MDSound();
	~MDSound() = default;

	// ���͈̂��
	static MDSound* Instance();

	// �T�E���h�f�o�C�X�̍쐬
	void CreateSoundDevice( HWND hWnd );
	// �f�o�C�X�Q��
	IDirectSound8*	RefDevice();

private:
	ComPtr<IDirectSound8> pDirectSound8;		// DirectSound�f�o�C�X
};

inline MDSound* MDSound::Instance(){
	static auto instance = std::make_unique<MDSound>();	// new����v��Ȃ�
	return instance.get();
}

