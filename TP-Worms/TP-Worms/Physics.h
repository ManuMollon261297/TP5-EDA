#pragma once
class Physics
{
private:
	/*
	static double gravity;
	static double jumpAngle;
	static double velocity;
	*/
	double gravity;
	double jumpAngle;
	double velocity;

public:
	Physics(double gravity_ = 0.24, double jumpAngle_ = 60,double velocity_ = 27);
	double getGravity(void);
	double getJumpAngle(void);
	double getVelocity(void);
};

