#pragma once
#include "MDUncopyable.h"
#include "MDSound.h"
#include <unordered_map>
//#include <memory>
class Wave;

class MDSoundManager :private MDUncopyable
	
{
public:
	MDSoundManager();
	~MDSoundManager();

	static MDSoundManager* Instance();

	bool AddMove( unsigned int key, Wave& data );
	void Play( unsigned int key, bool	isLoop );
	void Stop( unsigned int key);
	void AllStop();
	void AllClear();

private:
	bool	Create( unsigned int key, Wave& data );

private:
	std::unordered_map<unsigned int, ComPtr<IDirectSoundBuffer8>> secondaryBufferMap;	// セカンダリバッファのマップ
};

inline MDSoundManager* MDSoundManager::Instance(){
	static auto instance = std::make_unique<MDSoundManager>();
	return instance.get();
}

