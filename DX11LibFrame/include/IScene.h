#pragma once
class IScene
{
public:
	IScene() = default;
	virtual ~IScene() = default;

	virtual int Initialize	()	= 0;
	virtual int Update		()	= 0;
	virtual int Release	()	= 0;
};

