#pragma once
#include "MDUncopyable.h"
#include <stack>
#include <memory>
class MDScene;

class MDSceneManager :private MDUncopyable
	
{
public:
	MDSceneManager();
	~MDSceneManager();

	static MDSceneManager* Instance();

	//	�X�^�b�N�ɐς܂�Ă���V�[�������s
	void Exe();

	//	�X�^�b�N�ɃV�[����ς�
	void PushScene( MDScene* ptr );

	//	�J�����g�V�[�����s��ɃV�[����ς���
	void ReserveNextScene( MDScene* ptr );

	//	�X�^�b�N�ɐς܂�Ă���S�V�[�������
	void Release();


private:
	MDScene* currentScene;	//	���ݎ��s���Ă���V�[��
	MDScene* nextScene;		//	�I����ςގ����\�񂳂ꂽ�V�[��

	std::stack<MDScene*> sceneStack;				//	�V�[�����i�[����X�^�b�N
};

inline MDSceneManager* MDSceneManager::Instance()
{
	static auto instance = std::make_unique<MDSceneManager>();
	return instance.get();
}

