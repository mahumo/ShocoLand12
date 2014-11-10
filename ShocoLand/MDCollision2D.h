#pragma once
#include <MDCore.h>
#include <MDOperators.h>

class MDGameObj2D
{
public:
	MDGameObj2D() :pos( 0,0 ), size( 0,0 ),center(0,0){}
	MDGameObj2D( MDVector2 _pos, MDVector2 _size, MDVector2 _center = MDVector2(0, 0))
		:pos(_pos), size(_size), center(_center){}
	~MDGameObj2D() = default;

	MDVector2 pos;
	MDVector2 size;
	MDVector2 center;
};

class MDCollision2D
{
public:
	// 矩形の衝突判定
	// 基準点の指定は 0 ~ 1 の範囲
	// 矩形の基準点は左上を基本に計算
	static bool RectHit( MDGameObj2D& rect0, MDGameObj2D& rect1 )
	{
		return RectHit( rect0.pos, rect1.pos, rect0.size, rect1.size, rect0.center, rect1.center );
	}
	static bool RectHit( MDVector2& pos0, MDVector2& pos1, MDVector2& size0, MDVector2& size1, 
		MDVector2& center0 = MDVector2( 0, 0 ), MDVector2& center1 = MDVector2( 0, 0 ) )	
	{
		// オブジェクト基準点を元に、座標をずらす長さを算出。加算する
		// 基本が左上なので、加算するだけで良い
		MDVector2 point0 = center0*size0;
		MDVector2 point1 = center1*size1;
		// 左右
		if( (pos0.x + point0.x + size0.x > pos1.x + point1.x) &&
			(pos0.x + point0.x  < pos1.x + point1.x + size1.x) )
		{
			// 上下
			if( (pos0.y + point0.y + size0.y > pos1.y + point1.y) &&
				(pos0.y + point0.y< pos1.y + point1.y + size1.y) )
			{
				return true;
			}
		}
		return false;
	}

	// 円の衝突判定
	// 基準点の指定は -0.5 ~ 0.5 の範囲
	// 円は基準点を中心に考えた方が分かり易い為、
	// 中心点を基本とした計算をしている
	static bool CircleHit( MDGameObj2D& circle0, MDGameObj2D& circle1 )
	{
		return CircleHit( circle0.pos, circle1.pos, circle0.size.x, circle1.size.x, circle0.center, circle1.center );
	}
	static bool CircleHit( MDVector2& pos0, MDVector2& pos1, float r0, float r1, 
		MDVector2& center0 = MDVector2( 0, 0 ), MDVector2& center1 = MDVector2( 0, 0 ) )
	{
		// 渡しているのは円の半径だが、基準点をずらす計算に必要なのは直径であることに注意
		MDVector2 point0 = center0*r0*2;
		MDVector2 point1 = center1*r1*2;

		// 距離差
		MDVector2 distance = (pos0 + point0) - (pos1 + point1);

		// 距離、半径の2乗
		float distanceSqr = distance.x *distance.x + distance.y*distance.y;
		float r = r0+ r1;
		return distanceSqr < r*r;
	}

	// 矩形と円の衝突判定
	static bool RectToCircleHit( MDGameObj2D& rect, MDGameObj2D& circle )
	{
		return RectToCircleHit( rect.pos, circle.pos, rect.size, circle.size.x, rect.center, circle.center );
	}
	static bool RectToCircleHit( MDVector2& rectPos, MDVector2& circlePos, MDVector2& rectSize, float circleSize,
		MDVector2& rectCenter = MDVector2( 0, 0 ), MDVector2& circleCenter = MDVector2( 0, 0 ) )
	{
		// 基準点に合わせて、座標を調整
		MDVector2 rectPoint = rectCenter*rectSize;
		MDVector2 circlePoint = circleCenter*circleSize * 2;
		rectPoint = rectPoint + rectPos;
		circlePoint = circlePoint + circlePos;

		// まずは大きめにチェック
		// 矩形の各頂点から、円の半径未満に円の中心点が含まれているか
		if( (circlePoint.x > rectPoint.x - circleSize) &&
			(circlePoint.x < rectPoint.x + rectSize.x + circleSize) &&
			(circlePoint.y > rectPoint.y - circleSize) &&
			(circlePoint.y < rectPoint.y + rectSize.y + circleSize) )
		{
			return RectToCircleInner( rectPoint, circlePoint, rectSize, circleSize );
		}
		return false;
	}

	bool static RectToCircleInner( MDVector2& rectPos, MDVector2& circlePos, MDVector2& rectSize, float circleSize )
	{
		bool hit = true;							// フラグ
		float	radiusSqrar = circleSize*circleSize;	// 円の半径の2乗
		// 左端チェック
		if( circlePos.x < rectPos.x ){
			//  左上隅チェック
			if( circlePos.y < rectPos.y ){
				// 当たってないことを調べる
				if( DistanceSqr( rectPos, circlePos ) >= radiusSqrar )
					hit = false;
			}
			else{
				// 左下隅チェック
				if( circlePos.y > rectPos.y + rectSize.y ){
					if( DistanceSqr( { rectPos.x, rectPos.y + rectSize.y }, circlePos ) >= radiusSqrar )
						hit = false;
				}
			}
		}
		else{
			// 右端チェック
			if( circlePos.x > rectPos.x + rectSize.x ){
				// 右隅チェック
				if( circlePos.y < rectPos.y ){
					if( DistanceSqr( { rectPos.x + rectSize.x, rectPos.y }, circlePos ) >= radiusSqrar )
						hit = false;
				}
				else{
					// 右下隅チェック
					if( circlePos.y > rectPos.y + rectSize.y ){
						if( DistanceSqr( { rectPos.x + rectSize.x, rectPos.y + rectSize.y }, circlePos ) >= radiusSqrar )
							hit = false;
					}
				}
			}
		}
		return hit;
	}

	// 頂点間の距離の2乗を求める
	static float DistanceSqr( const MDVector2& point0, const MDVector2& point1 )
	{
		// 距離差
		const auto distance = point0 - point1;

		// 距離2乗
		return distance.x *distance.x + distance.y*distance.y;
	}
};

