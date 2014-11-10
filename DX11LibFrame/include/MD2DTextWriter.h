#pragma once
#include "MDUncopyable.h"
#include "MDCore.h"
#include "MDTypedefs.h"
#include <string>
#include <memory>

class MD2DTextWriter :private MDUncopyable
{
private:
	struct MDWrite
	{
		ComPtr<IDWriteTextFormat>				textFormat;
		ComPtr<IDWriteTextLayout>				textLayout;
	};

public:
	MD2DTextWriter();

	// 通常利用
	static HRESULT CreateWriteTextFormat( const LPCWSTR font, float size, ComPtr<IDWriteTextFormat>& textFormat );
	static HRESULT CreateColorBrush( ComPtr<ID2D1SolidColorBrush>& brush, const MDColorF& color );
	static void SetBrushColor( ComPtr<ID2D1SolidColorBrush>& brush, float R, float G, float B, float A = 1.0f );
	static void SetBrushColor( ComPtr<ID2D1SolidColorBrush>& brush, const MDColorF& color );

	// このクラスのインスタンス専用( クラス分けは今は考えたくないので )
	HRESULT CreateWriteTextFormat( const LPCWSTR font, float size);
	HRESULT CreateColorBrush(const MDColorF& color );
	void SetBrushColor( float R, float G, float B, float A = 1.0f );
	void SetBrushColor( const MDColorF& color );
	
	// 描画
	void TextWrite( const std::string& str, const MDVector2& pos, const ComPtr<ID2D1SolidColorBrush>& brush );
	void TextWrite( const std::string& str, const MDVector2& pos );
	
private:
	HRESULT CreateWriteTextLayout( std::string str, const float x, const float y );

private:
	std::unique_ptr<MDWrite>				devWrite;
	ComPtr<ID2D1SolidColorBrush>		solidBrush;
	
};
