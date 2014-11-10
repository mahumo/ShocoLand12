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

	// ������( �u���V���� )
	void Initialize();

	// 2D�`�� �J�n/�I��
	void BeginDraw();
	HRESULT EndDraw();

	// 2D�o�b�N�o�b�t�@���N���A( 3D���p���g�p�s�� )
	void Clear( float R, float G, float B, float A = 1.0f );
	void Clear( const MDColorF& color );

	// 2DLine�u���V�J���[�̕ύX
	void SetLineColor( float R, float G, float B, float A = 1.0f );
	void SetLineColor( const MDColorF& color );

private:
	// �s��̏�����
	void TransformInitialize();

	///--------------------------------------------------------------------------------------------------------------------
	/// �`��֐�
	///--------------------------------------------------------------------------------------------------------------------

public:
	//	���̕`��
	void Line( const MDVector2& start, const MDVector2& end, float strokeWidth = 1.0f );
	void Line( const float startX, const float startY, const float endX, const float endY, float strokeWidth = 1.0f );

	//	��`�`��( �J�蔲�� )
	void Rect( const MDVector2& pos, const MDVector2& size );
	void Rect( float x, float y, float width, float height );

	//	��`�`��( �h��Ԃ� )
	void FillRect( const MDVector2& pos, const MDVector2& size );
	void FillRect( float x, float y, float width, float height );

	//	�ȉ~�̕`��( �J�蔲�� )
	void Ellipse( const MDVector2& center, const MDVector2& radius );
	void Ellipse( const MDVector2& center, float radius );
	void Ellipse( float centerX, float centerY, float radiusX, float radiusY );

	//	�ȉ~�̕`��( �h��Ԃ� )
	void FillEllipse( const MDVector2& center, const MDVector2& radius );
	void FillEllipse( const MDVector2& center, float radius );
	void FillEllipse( float centerX, float centerY, float radiusX, float radiusY );

	//	�r�b�g�}�b�v�̕\��( ������A���W, ���ߓx)
	void BitMap( MD2DBitmap* pBitmap, const MDVector2& pos, float opacity = 1.0f );
	void BitMap( MD2DBitmap* pBitmap, float x, float y, float opacity = 1.0f );

	//	�r�b�g�}�b�v�̕\��( ���W, �����`��, ���ߓx )
	void BitMap( MD2DBitmap* pBitmap, const MDVector2& pos, const MDRectF& rectAngle, float opacity );
	void BitMap( MD2DBitmap* pBitmap, float x, float y, const MDRectF& rectAngle, float opacity);

	//�r�b�g�}�b�v�̕\��( ������, ���W, �x���@,�h�b�g�w���_, ���ߓx )
	void BitMap( MD2DBitmap* pBitmap, const MDVector2& pos, float radian, MDPointF center , float opacity = 1.0f );
	void BitMap( MD2DBitmap* pBitmap, float x, float y, float radian, MDPointF center , float opacity = 1.0f );

	//�r�b�g�}�b�v�̕\��( ���W, �����`��, �g�k��, ���ߓx ) �h�b�g���Z�ɂ��̊g����@
	void BitMap( MD2DBitmap* pBitmap, const MDVector2& pos, const MDRectF& rectAngle, const MDVector2 scale, float opacity);
	void BitMap( MD2DBitmap* pBitmap, const MDVector2& pos, const MDRectF& rectAngle, float scale, float opacity );
	void BitMap( MD2DBitmap* pBitmap, float x, float y, const MDRectF& rectAngle, const MDVector2 scale, float opacity );
	void BitMap( MD2DBitmap* pBitmap, float x, float y, const MDRectF& rectAngle, float scale, float opacity);

private:
	// 2D�`��p�u���V ( Text�͕ʂŎ����Ă� )
	ComPtr<ID2D1SolidColorBrush>		solidBrush;
};

