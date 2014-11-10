#ifndef VECTOR3_H
#define VECTOR3_H
#include "MDTypedefs.h"

class MDVector3Helper
{
public:
	MDVector3Helper();
	~MDVector3Helper();

	// FLOAT3��XMVECTOR�ɕϊ�
	XMVector XMVectorConversion( MDVector3 vec );
	//XMVECTOR��FLOAT3�ɕϊ�
	MDVector3  MDVector3Conversion( XMVector vec );
	//���K��
	MDVector3 Normalize( MDVector3& pout );
	//�A�u�\�����[�g
	MDVector3 Abs( MDVector3& pout );
	//����
	FLOAT Distance( MDVector3 a, MDVector3 b );
	//����
	MDVector3 Dot( MDVector3 lhs, MDVector3 rhs );
	//�|���Z
	MDVector3 Scale( MDVector3 a, MDVector3 b );
	//�O��
	MDVector3 Cross( MDVector3 lhs, MDVector3 rhs );
};

#endif