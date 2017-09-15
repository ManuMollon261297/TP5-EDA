#pragma once
#include "Physics.h"


class Worm
{
public:
	Worm();
	enum { IDLE, MOVING, MONITOR_MOVING, END_MOVEMENT, JUMPING,END_JUMPING};
	void setKeys(char right_,char left_, char up_);
	void startMoving(void);
	void stopMoving(void);
	void startJumping(void);
	void stopJumping(void);
	void update(void);
	char uData;

private:
	struct position
	{
		double x;
		double y;
	};
	position pos;
	Physics physicsData;
	bool sentido;
	unsigned int frameCount;
	unsigned int state;

	const bool left = true;
	const bool right = false;

	struct data
	{
		char up;
		char left;
		char right;
	};

	data keys;

};

