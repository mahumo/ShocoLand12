#pragma once
#include "MDCore.h"
#include "MDTypedefs.h"
class MD2DBitmap
{
public:
	MD2DBitmap() = default;
	~MD2DBitmap() = default;

	//	�r�b�g�}�b�v���쐬
	HRESULT Create( LPCWSTR fineName );
	//	�r�b�g�}�b�v�C���[�W���쐬
	HRESULT Create( UINT width, UINT height, long stride );

	//	BYTE�z�񂩂�r�b�g�}�b�v�C���[�W�֓W�J
	HRESULT CopyFromMemory( BYTE* pImage, LONG stride );

	//	�r�b�g�}�b�v���擾
	ID2D1Bitmap* RefBitmap()
	{
		return pBitmap.Get();
	}

	//	�r�b�g�}�b�v�T�C�Y���擾
	MDVector2 GetImageSize()
	{
		return imageSize;
	}
private:
	//	�C���[�W�f�R�[�_�[
	ComPtr<ID2D1Bitmap> Decoder( LPCWSTR fileName );

private:
	ComPtr<ID2D1Bitmap>		pBitmap;		//	�r�b�g�}�b�v
	MDVector2			imageSize;		//	�摜�T�C�Y�i�[
};

