#include "Physics.h"


Physics::Physics(static double gravity_, static double jumpAngle_, static double velocity_)
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