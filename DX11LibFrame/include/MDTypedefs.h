#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include "MDCore.h"

// Typedef���Ă�΁A�蒼���o���Ȃ����Ȃ��Ǝv��
//	�x�N�g��
typedef DirectX::XMFLOAT2 MDVector2;
typedef DirectX::XMFLOAT3 MDVector3;
typedef DirectX::XMFLOAT4 MDVector4;
typedef DirectX::XMVECTOR XMVector;			// XMVECTOR XMMATRIX �̓X�^�b�N��Ŏg�p���Ȃ���΂Ȃ�Ȃ��B

//	�s��
typedef DirectX::XMFLOAT4X4	Matrix4x4;
typedef DirectX::XMMATRIX		XMMatrix;
typedef D2D1::Matrix3x2F			Matrix3x2;

typedef D2D1_POINT_2F MDPointF;

//	�J���[
typedef D2D1::ColorF MDColorF;

//struct MDColorF
//{
//	float R, G, B, A;
//};

//	��`
typedef D2D1_RECT_F MDRectF;

//struct MDRectF
//{
//	float left, top, right, bottom;
//};

#endif
