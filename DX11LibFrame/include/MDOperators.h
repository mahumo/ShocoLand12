#ifndef MDOPERATORS_H
#define MDOPERATORS_H
#include "MDTypedefs.h"

inline
MDVector2 operator+ (const MDVector2& v0, const MDVector2& v1)
{
	return{ v0.x + v1.x, v0.y + v1.y };
}

inline
MDVector2 operator- (const MDVector2& v0, const MDVector2& v1)
{
	return{ v0.x - v1.x, v0.y - v1.y };
}

inline
MDVector2 operator* (const MDVector2& v0, const MDVector2& v1)
{
	return{ v0.x * v1.x, v0.y * v1.y };
}

inline
MDVector2 operator* (const MDVector2& v0, const float f1)
{
	return{ v0.x * f1, v0.y * f1 };
}

inline
MDVector2 operator* (const MDVector2& v0, const int i1)
{
	return{ v0.x * i1, v0.y * i1 };
}

inline
MDVector2 operator/ (const MDVector2& v0, const float i1)
{
	return{ v0.x / i1, v0.y / i1 };
}

inline
MDVector2 operator/ (const MDVector2& v0, const MDVector2& v1)
{
	return{ v0.x / v1.x, v0.y / v1.y };
}

#endif