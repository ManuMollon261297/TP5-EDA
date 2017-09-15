#include "Worm.h"
#include <cstdlib>

Worm::Worm()
{
	pos.x = 701 + (double)(rand()) / ((double)(RAND_MAX / (1212 -701)));
	sentido = (bool) ((int)(pos.x) % 2);
	pos.y = 616;
	frameCount = 0;
	state = IDLE;
	uData = 0;
}

void Worm::startMoving(void)
{
	if (state == IDLE)
	{
		state = MONITOR_MOVING;
		frameCount = 0;
	}
	else if (state == END_MOVEMENT)
	{
		state = MOVING;
	}
}


void Worm::stopMoving(void)
{
	if (state == MOVING)
	{
		state = END_MOVEMENT;
	}
	else if (state == MONITOR_MOVING)
	{
		state = IDLE;
	}
}

void Worm::startJumping(void)
{
	if (state == IDLE)
	{
		state = JUMPING;
		frameCount = 0;
	}
	else if (state == END_JUMPING)
	{
		state = JUMPING;
	}
}

void Worm::stopJumping(void)
{
	if (state == JUMPING)
	{
		state = END_JUMPING;
	}
}

void Worm::update(void)
{
	switch (state)
	{
		case IDLE:
		{
			//nada
		} break;
		case MOVING:
		{
			//calculo prox pos
		} break;
		case MONITOR_MOVING:
		{
			if(frameCount == 5)
			{
				state = MOVING;
			}
			if (uData == keys.right)
			{
				sentido = right;
			}
			else if (uData == keys.left) // l y r son las flechas apretadas, que raducen a los chars nombrados
			{
				sentido = left;
			}
		} break;
		case END_MOVEMENT:
		{
			if (frameCount == 50)
			{
				state = IDLE;
			}
		} break;
		case JUMPING:
		{
			//calcular prox pos
		} break;
		case END_JUMPING:
		{
			if (frameCount == 50)
			{
				state = IDLE;
			}
		} break;
	}
	frameCount++;
}

void Worm::setKeys(char right_, char left_, char up_)
{
	keys.left = left_;
	keys.right = right;
	keys.up = up_;
}