#include <iostream>
#include <ctime>
#include <vector>

#include "Worm.h"
#include "Cevent.h"

using namespace std;

void dispatch(Cevent ev, vector<Worm> Worms);

//TERMINAR
// calculos de fisica

int main(void)
{
	//iniciliazacion de allegro
	srand(time(NULL));
	vector<Worm> Worms(2);
	Worms[0].setKeys('d', 'a', 'w');
	Worms[1].setKeys('j','i','l'); //inicializar con las def de allegro
	Cevent ev;
	do {
		//ev = getNextEvent();
		if (ev.eventType != NO_EVENT)
		{
			dispatch(ev, Worms);
		}
		// actualizo display
	} while (ev.eventType != QUIT);

	//cierro allegro

}

void dispatch(Cevent ev, vector<Worm> Worms)
{
	switch (ev.eventType)
	{
		case PRESS_MOVE:
		{
			for (int i = 0; i < Worms.size;i++)
			{
				Worms[i].uData = ev.ud;
				Worms[i].startMoving();
			}
		} break;
		case RELEASE_MOVE:
		{
			for (int i = 0; i < Worms.size; i++)
			{
				Worms[i].uData = ev.ud;
				Worms[i].stopMoving();
			}
		} break;
		case PRESS_JUMP:
		{
			for (int i = 0; i < Worms.size; i++)
			{
				Worms[i].uData = ev.ud;
				Worms[i].startJumping();
			}
		} break;
		case RELEASE_JUMP:
		{
			for (int i = 0; i < Worms.size; i++)
			{
				Worms[i].uData = ev.ud;
				Worms[i].stopJumping();
			}
		} break;
		case REFRESH:
		{
			for (int i = 0; i < Worms.size; i++)
			{
				Worms[i].uData = ev.ud;
				Worms[i].update();
			}
		} break;
	}
}
