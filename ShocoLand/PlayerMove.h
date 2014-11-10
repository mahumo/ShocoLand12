#pragma once
class MDGameObj2D;
enum IsGround{
	Ground,
	Ladder,
	Flying
};

class PlayerMove
{
public:
	PlayerMove();
	~PlayerMove();
	void Inisialize();
	void Update(MDGameObj2D& obj, float speed);
private:
	IsGround ground;
	static const float Gravity;
	bool m_isGround;
	float m_Speed;
};

