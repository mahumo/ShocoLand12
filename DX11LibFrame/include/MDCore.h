#pragma once

// DirectX�n�K�v�w�b�_
#include <dxgi1_2.h>
#include <d3d11.h>//_1.h>
#include <d2d1_1.h>	// d2d1����Ȃ��Ă����񂩂ȁH
#include <d2d1_1helper.h>
#include <dwrite.h>//_1.h>
#include <d3dcompiler.h>
#include <d3d11shader.h>
#include <directxmath.h>
#include <directxcolors.h>

// C++/CX�n
#include <wrl.h>		// ComPtr�Ƃ����̒��ɓ����Ă�
template <typename IDXTYPE>
using ComPtr = Microsoft::WRL::ComPtr<IDXTYPE>;

// windows�n?
#include <wincodec.h>	//  Bitmap �ǂݍ��݂Ɏg��

// DXTexLib
#include <include/DirectXTex.h>


// ��n
#pragma comment( lib, "winmm.lib")
//#pragma comment( lib, "comctl32.lib")					// ���ʌ݊��炵��
#pragma comment(lib, "windowscodecs.lib")		// Bitmap �ǂݍ��݂Ɏg��

// DX
#pragma comment( lib, "d3d11.lib" )
#pragma comment( lib,"d2d1.lib")
#pragma comment( lib,"dwrite.lib")
#pragma comment( lib, "d3dcompiler.lib")				// �V�F�[�_�[�R���p�C���ɕK�v�ȃ��C�u����


// DXTexLib
#if _DEBUG
#pragma comment(lib,"lib/DirectXTex_mdd.lib")
#else
#pragma comment(lib,"lib/DirectXTex_md.lib")
#endif