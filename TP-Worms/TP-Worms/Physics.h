#pragma once
class Physics
{
private:
	static double gravity;
	static double jumpAngle;
	static double velocity;

public:
	Physics(static double gravity_ = 0.24, static double jumpAngle_ = 60,static double velocity_ = 27);
	double getGravity(void);
	double getJumpAngle(void);
	double getVelocity(void);
};

