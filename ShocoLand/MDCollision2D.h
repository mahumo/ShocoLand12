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
	// ��`�̏Փ˔���
	// ��_�̎w��� 0 ~ 1 �͈̔�
	// ��`�̊�_�͍������{�Ɍv�Z
	static bool RectHit( MDGameObj2D& rect0, MDGameObj2D& rect1 )
	{
		return RectHit( rect0.pos, rect1.pos, rect0.size, rect1.size, rect0.center, rect1.center );
	}
	static bool RectHit( MDVector2& pos0, MDVector2& pos1, MDVector2& size0, MDVector2& size1, 
		MDVector2& center0 = MDVector2( 0, 0 ), MDVector2& center1 = MDVector2( 0, 0 ) )	
	{
		// �I�u�W�F�N�g��_�����ɁA���W�����炷�������Z�o�B���Z����
		// ��{������Ȃ̂ŁA���Z���邾���ŗǂ�
		MDVector2 point0 = center0*size0;
		MDVector2 point1 = center1*size1;
		// ���E
		if( (pos0.x + point0.x + size0.x > pos1.x + point1.x) &&
			(pos0.x + point0.x  < pos1.x + point1.x + size1.x) )
		{
			// �㉺
			if( (pos0.y + point0.y + size0.y > pos1.y + point1.y) &&
				(pos0.y + point0.y< pos1.y + point1.y + size1.y) )
			{
				return true;
			}
		}
		return false;
	}

	// �~�̏Փ˔���
	// ��_�̎w��� -0.5 ~ 0.5 �͈̔�
	// �~�͊�_�𒆐S�ɍl��������������Ղ��ׁA
	// ���S�_����{�Ƃ����v�Z�����Ă���
	static bool CircleHit( MDGameObj2D& circle0, MDGameObj2D& circle1 )
	{
		return CircleHit( circle0.pos, circle1.pos, circle0.size.x, circle1.size.x, circle0.center, circle1.center );
	}
	static bool CircleHit( MDVector2& pos0, MDVector2& pos1, float r0, float r1, 
		MDVector2& center0 = MDVector2( 0, 0 ), MDVector2& center1 = MDVector2( 0, 0 ) )
	{
		// �n���Ă���͉̂~�̔��a�����A��_�����炷�v�Z�ɕK�v�Ȃ̂͒��a�ł��邱�Ƃɒ���
		MDVector2 point0 = center0*r0*2;
		MDVector2 point1 = center1*r1*2;

		// ������
		MDVector2 distance = (pos0 + point0) - (pos1 + point1);

		// �����A���a��2��
		float distanceSqr = distance.x *distance.x + distance.y*distance.y;
		float r = r0+ r1;
		return distanceSqr < r*r;
	}

	// ��`�Ɖ~�̏Փ˔���
	static bool RectToCircleHit( MDGameObj2D& rect, MDGameObj2D& circle )
	{
		return RectToCircleHit( rect.pos, circle.pos, rect.size, circle.size.x, rect.center, circle.center );
	}
	static bool RectToCircleHit( MDVector2& rectPos, MDVector2& circlePos, MDVector2& rectSize, float circleSize,
		MDVector2& rectCenter = MDVector2( 0, 0 ), MDVector2& circleCenter = MDVector2( 0, 0 ) )
	{
		// ��_�ɍ��킹�āA���W�𒲐�
		MDVector2 rectPoint = rectCenter*rectSize;
		MDVector2 circlePoint = circleCenter*circleSize * 2;
		rectPoint = rectPoint + rectPos;
		circlePoint = circlePoint + circlePos;

		// �܂��͑傫�߂Ƀ`�F�b�N
		// ��`�̊e���_����A�~�̔��a�����ɉ~�̒��S�_���܂܂�Ă��邩
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
		bool hit = true;							// �t���O
		float	radiusSqrar = circleSize*circleSize;	// �~�̔��a��2��
		// ���[�`�F�b�N
		if( circlePos.x < rectPos.x ){
			//  ������`�F�b�N
			if( circlePos.y < rectPos.y ){
				// �������ĂȂ����Ƃ𒲂ׂ�
				if( DistanceSqr( rectPos, circlePos ) >= radiusSqrar )
					hit = false;
			}
			else{
				// �������`�F�b�N
				if( circlePos.y > rectPos.y + rectSize.y ){
					if( DistanceSqr( { rectPos.x, rectPos.y + rectSize.y }, circlePos ) >= radiusSqrar )
						hit = false;
				}
			}
		}
		else{
			// �E�[�`�F�b�N
			if( circlePos.x > rectPos.x + rectSize.x ){
				// �E���`�F�b�N
				if( circlePos.y < rectPos.y ){
					if( DistanceSqr( { rectPos.x + rectSize.x, rectPos.y }, circlePos ) >= radiusSqrar )
						hit = false;
				}
				else{
					// �E�����`�F�b�N
					if( circlePos.y > rectPos.y + rectSize.y ){
						if( DistanceSqr( { rectPos.x + rectSize.x, rectPos.y + rectSize.y }, circlePos ) >= radiusSqrar )
							hit = false;
					}
				}
			}
		}
		return hit;
	}

	// ���_�Ԃ̋�����2������߂�
	static float DistanceSqr( const MDVector2& point0, const MDVector2& point1 )
	{
		// ������
		const auto distance = point0 - point1;

		// ����2��
		return distance.x *distance.x + distance.y*distance.y;
	}
};

