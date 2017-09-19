#pragma once
#include "Physics.h"

enum { IDLE, MOVING, MONITOR_MOVING, END_MOVEMENT, JUMPING, END_JUMPING };

struct position
{
	double x;
	double y;
};

class Worm
{
public:
	Worm();
	void setKeys(char right_,char left_, char up_);
	void startMoving(void);
	void stopMoving(void);
	void startJumping(void);
	void stopJumping(void);
	void update(void);
	char uData;
	position getPos(void);
	unsigned int getState(void);
	unsigned int getFrameCount(void);
	bool getSentido(void);
	const bool left = false;
	const bool right = true;
	bool key_down;
private:
	position pos;
	Physics physicsData;
	bool sentido;
	unsigned int frameCount;
	unsigned int state;

	struct data
	{
		char up;
		char left;
		char right;
	};

	data keys;

};

