// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーから使用されていない部分を除外します。
// Windows ヘッダー ファイル:
#include <Windows.h>

// C ランタイム ヘッダー ファイル
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <mmsystem.h>	// Waveファイル読み込み

// STL
#include <string>
#include <vector>
#include <sstream>	// 文字列から数値へ変換
									// 区切り文字で文字列を分ける
#include <cassert>
#include <fstream>
#include <iostream>	// ファイル読み込み
#include <memory>
#include <algorithm>
#include <array>
#include <list>
#include <unordered_map>

#include <wincodec.h>		// Inputで必要

//// 何とも言えない
#include <wrl.h>		// ComPtrとかこの中に入ってる


// TODO: プログラムに必要な追加ヘッダーをここで参照してください。
#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
