#include "Physics.h"


Physics::Physics(double gravity_,double jumpAngle_,double velocity_)
{
	gravity = gravity_;
	jumpAngle = jumpAngle_;
	velocity = velocity_;
}

double Physics::getGravity(void)
{
	return gravity;
}

double Physics::getJumpAngle(void)
{
	return jumpAngle;
}

double Physics::getVelocity(void)
{
	return velocity;
}