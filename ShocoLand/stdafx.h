// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���̃C���N���[�h �t�@�C���A�܂���
// �Q�Ɖ񐔂������A�����܂�ύX����Ȃ��A�v���W�F�N�g��p�̃C���N���[�h �t�@�C��
// ���L�q���܂��B
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Windows �w�b�_�[����g�p����Ă��Ȃ����������O���܂��B
// Windows �w�b�_�[ �t�@�C��:
#include <Windows.h>

// C �����^�C�� �w�b�_�[ �t�@�C��
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <mmsystem.h>	// Wave�t�@�C���ǂݍ���

// STL
#include <string>
#include <vector>
#include <sstream>	// �����񂩂琔�l�֕ϊ�
									// ��؂蕶���ŕ�����𕪂���
#include <cassert>
#include <fstream>
#include <iostream>	// �t�@�C���ǂݍ���
#include <memory>
#include <algorithm>
#include <array>
#include <list>
#include <unordered_map>

#include <wincodec.h>		// Input�ŕK�v

//// ���Ƃ������Ȃ�
#include <wrl.h>		// ComPtr�Ƃ����̒��ɓ����Ă�


// TODO: �v���O�����ɕK�v�Ȓǉ��w�b�_�[�������ŎQ�Ƃ��Ă��������B
#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
