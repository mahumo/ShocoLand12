#pragma once
#include "IScene.h"

enum  MDSceneStay : int
{
	//	�����o�֐��̓���
	FUNC_PROCESS = 0,		//	�֐����s��
	FUNC_END = 1,				//	�֐����s�I��
	FUNC_ERROR = -1,			// �֐��ُ�I��

	//	�V�[���̎��s���
	PROCESS =0,					//	�V�[�����s��
	END=1,							//	�V�[�����s�I��
};


class MDScene :public IScene
{
public:
	MDScene();
	virtual ~MDScene() = default;

	// �V�[���N���X�����s
	int Exe();

private:
	int (MDScene::*sceneFunc[3])();	//	�֐��|�C���^
	int funcNo;			//	���ݎ��s���Ă���֐�No
};

