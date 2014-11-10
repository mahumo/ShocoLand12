#pragma once

// DirectX系必要ヘッダ
#include <dxgi1_2.h>
#include <d3d11.h>//_1.h>
#include <d2d1_1.h>	// d2d1じゃなくていいんかな？
#include <d2d1_1helper.h>
#include <dwrite.h>//_1.h>
#include <d3dcompiler.h>
#include <d3d11shader.h>
#include <directxmath.h>
#include <directxcolors.h>

// C++/CX系
#include <wrl.h>		// ComPtrとかこの中に入ってる
template <typename IDXTYPE>
using ComPtr = Microsoft::WRL::ComPtr<IDXTYPE>;

// windows系?
#include <wincodec.h>	//  Bitmap 読み込みに使う

// DXTexLib
#include <include/DirectXTex.h>


// 謎系
#pragma comment( lib, "winmm.lib")
//#pragma comment( lib, "comctl32.lib")					// 下位互換らしい
#pragma comment(lib, "windowscodecs.lib")		// Bitmap 読み込みに使う

// DX
#pragma comment( lib, "d3d11.lib" )
#pragma comment( lib,"d2d1.lib")
#pragma comment( lib,"dwrite.lib")
#pragma comment( lib, "d3dcompiler.lib")				// シェーダーコンパイルに必要なライブラリ


// DXTexLib
#if _DEBUG
#pragma comment(lib,"lib/DirectXTex_mdd.lib")
#else
#pragma comment(lib,"lib/DirectXTex_md.lib")
#endif