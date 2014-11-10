#pragma once
#include "MDCore.h"
#include "MDTypedefs.h"
class MD2DBitmap
{
public:
	MD2DBitmap() = default;
	~MD2DBitmap() = default;

	//	ビットマップを作成
	HRESULT Create( LPCWSTR fineName );
	//	ビットマップイメージを作成
	HRESULT Create( UINT width, UINT height, long stride );

	//	BYTE配列からビットマップイメージへ展開
	HRESULT CopyFromMemory( BYTE* pImage, LONG stride );

	//	ビットマップを取得
	ID2D1Bitmap* RefBitmap()
	{
		return pBitmap.Get();
	}

	//	ビットマップサイズを取得
	MDVector2 GetImageSize()
	{
		return imageSize;
	}
private:
	//	イメージデコーダー
	ComPtr<ID2D1Bitmap> Decoder( LPCWSTR fileName );

private:
	ComPtr<ID2D1Bitmap>		pBitmap;		//	ビットマップ
	MDVector2			imageSize;		//	画像サイズ格納
};

