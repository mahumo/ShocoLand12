#pragma once
#include "MDCore.h"
#include "MDUncopyable.h"
#include "MDTypedefs.h"

class MD2DBitmap;

class MD2DHelper : private MDUncopyable
{
public:
	MD2DHelper() = default;
	~MD2DHelper() = default;

	// 初期化( ブラシ生成 )
	void Initialize();

	// 2D描画 開始/終了
	void BeginDraw();
	HRESULT EndDraw();

	// 2Dバックバッファをクリア( 3D併用時使用不可 )
	void Clear( float R, float G, float B, float A = 1.0f );
	void Clear( const MDColorF& color );

	// 2DLineブラシカラーの変更
	void SetLineColor( float R, float G, float B, float A = 1.0f );
	void SetLineColor( const MDColorF& color );

private:
	// 行列の初期化
	void TransformInitialize();

	///--------------------------------------------------------------------------------------------------------------------
	/// 描画関数
	///--------------------------------------------------------------------------------------------------------------------

public:
	//	線の描画
	void Line( const MDVector2& start, const MDVector2& end, float strokeWidth = 1.0f );
	void Line( const float startX, const float startY, const float endX, const float endY, float strokeWidth = 1.0f );

	//	矩形描画( 繰り抜き )
	void Rect( const MDVector2& pos, const MDVector2& size );
	void Rect( float x, float y, float width, float height );

	//	矩形描画( 塗りつぶし )
	void FillRect( const MDVector2& pos, const MDVector2& size );
	void FillRect( float x, float y, float width, float height );

	//	楕円の描画( 繰り抜き )
	void Ellipse( const MDVector2& center, const MDVector2& radius );
	void Ellipse( const MDVector2& center, float radius );
	void Ellipse( float centerX, float centerY, float radiusX, float radiusY );

	//	楕円の描画( 塗りつぶし )
	void FillEllipse( const MDVector2& center, const MDVector2& radius );
	void FillEllipse( const MDVector2& center, float radius );
	void FillEllipse( float centerX, float centerY, float radiusX, float radiusY );

	//	ビットマップの表示( 原寸大、座標, 透過度)
	void BitMap( MD2DBitmap* pBitmap, const MDVector2& pos, float opacity = 1.0f );
	void BitMap( MD2DBitmap* pBitmap, float x, float y, float opacity = 1.0f );

	//	ビットマップの表示( 座標, 部分描画, 透過度 )
	void BitMap( MD2DBitmap* pBitmap, const MDVector2& pos, const MDRectF& rectAngle, float opacity );
	void BitMap( MD2DBitmap* pBitmap, float x, float y, const MDRectF& rectAngle, float opacity);

	//ビットマップの表示( 原寸大, 座標, 度数法,ドット指定基準点, 透過度 )
	void BitMap( MD2DBitmap* pBitmap, const MDVector2& pos, float radian, MDPointF center , float opacity = 1.0f );
	void BitMap( MD2DBitmap* pBitmap, float x, float y, float radian, MDPointF center , float opacity = 1.0f );

	//ビットマップの表示( 座標, 部分描画, 拡縮率, 透過度 ) ドット加算によるの拡大方法
	void BitMap( MD2DBitmap* pBitmap, const MDVector2& pos, const MDRectF& rectAngle, const MDVector2 scale, float opacity);
	void BitMap( MD2DBitmap* pBitmap, const MDVector2& pos, const MDRectF& rectAngle, float scale, float opacity );
	void BitMap( MD2DBitmap* pBitmap, float x, float y, const MDRectF& rectAngle, const MDVector2 scale, float opacity );
	void BitMap( MD2DBitmap* pBitmap, float x, float y, const MDRectF& rectAngle, float scale, float opacity);

private:
	// 2D描画用ブラシ ( Textは別で持ってる )
	ComPtr<ID2D1SolidColorBrush>		solidBrush;
};

