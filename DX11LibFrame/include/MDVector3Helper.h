#ifndef VECTOR3_H
#define VECTOR3_H
#include "MDTypedefs.h"

class MDVector3Helper
{
public:
	MDVector3Helper();
	~MDVector3Helper();

	// FLOAT3をXMVECTORに変換
	XMVector XMVectorConversion( MDVector3 vec );
	//XMVECTORをFLOAT3に変換
	MDVector3  MDVector3Conversion( XMVector vec );
	//正規化
	MDVector3 Normalize( MDVector3& pout );
	//アブソリュート
	MDVector3 Abs( MDVector3& pout );
	//距離
	FLOAT Distance( MDVector3 a, MDVector3 b );
	//内積
	MDVector3 Dot( MDVector3 lhs, MDVector3 rhs );
	//掛け算
	MDVector3 Scale( MDVector3 a, MDVector3 b );
	//外積
	MDVector3 Cross( MDVector3 lhs, MDVector3 rhs );
};

#endif