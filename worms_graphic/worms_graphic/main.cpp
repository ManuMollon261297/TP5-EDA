#include <iostream>
#include <allegro5\allegro5.h>
#include <allegro5\allegro_image.h>


#include "walk_move.h"
#include "jump_move.h"

using namespace std;

const float FPS = 50.0;

int main(void) {

	ALLEGRO_DISPLAY * display = nullptr;
	ALLEGRO_EVENT_QUEUE *	event_queue = nullptr;
	ALLEGRO_TIMER * timer = nullptr;


	if (!al_init()) {
		return -1;
	}

	display = al_create_display(800, 600);

	if (display == nullptr) {
		return -1;
	}

	
	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		return -1;
	}

	if (!al_init_image_addon()) { // ADDON necesario para manejo(no olvidar el freno de mano) de imagenes
		return -1;
	}

	event_queue = al_create_event_queue();
	if (!event_queue) {
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_start_timer(timer);

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));


	jump_move jmv;
	jmv.init_jump_vars();
	jmv.load_jump_imgs();

	walk_move wmv;
	wmv.init_walk_vars();
	wmv.load_walk_imgs();


	ALLEGRO_EVENT evs;



	int exit = 0;

	while (!exit) {
		if (al_get_next_event(event_queue, &evs)) {

			switch (evs.type) {
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				exit = 1;
				break;
			case ALLEGRO_EVENT_TIMER:

				wmv.do_walking_step();
				jmv.do_jumping_step();
				wmv.px++;
				wmv.py++;
				jmv.px++;
				jmv.py++;
				
				jmv.orientation = 1;
				al_flip_display();
				break;
			}
		}
	}
	
	al_destroy_display(display);

	system("pause");
	return 0;

}