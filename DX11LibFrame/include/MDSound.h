#pragma once
#define DIRECTSOUND_VERSION 0x800

#include "MDCore.h"
#include "MDUncopyable.h"
#include <memory>

// DirectSound関連インクルード分等------
#include <dsound.h>
#pragma comment(lib, "dsound.lib")						// DirectSound

class MDSound :private MDUncopyable
{
public:
	MDSound();
	~MDSound() = default;

	// 実体は一つ
	static MDSound* Instance();

	// サウンドデバイスの作成
	void CreateSoundDevice( HWND hWnd );
	// デバイス参照
	IDirectSound8*	RefDevice();

private:
	ComPtr<IDirectSound8> pDirectSound8;		// DirectSoundデバイス
};

inline MDSound* MDSound::Instance(){
	static auto instance = std::make_unique<MDSound>();	// newすら要らない
	return instance.get();
}

