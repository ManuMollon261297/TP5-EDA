#include <iostream>
#include <allegro5\allegro5.h>
#include <allegro5\allegro_image.h>
#include "graphic_movement.h"


const float FPS = 50.0;

int main(void) {

	al_init();

	ALLEGRO_DISPLAY * display = nullptr;
	ALLEGRO_EVENT_QUEUE *	event_queue = nullptr;

	display = al_create_display(800, 600);

	if (display == nullptr) {
		return -1;
	}

	ALLEGRO_TIMER * timer = nullptr;

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	if (!al_init_image_addon()) { // ADDON necesario para manejo(no olvidar el freno de mano) de imagenes
		return -1;
	}

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_start_timer(timer);

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));


	graphic_movement graphic_handler;

	graphic_handler.create_images_arr();
	graphic_handler.init();
	graphic_handler.load_images(graphic_handler.prefix_walk, graphic_handler.walk_img_lib, graphic_handler.cant_walk_imgs);
	graphic_handler.load_images(graphic_handler.prefix_jump, graphic_handler.jump_img_lib, graphic_handler.cant_jump_imgs);
	ALLEGRO_EVENT evs;

	int exit = 0;

	do {
		if (al_get_next_event(event_queue, &evs)) {
			// if event comesup
			if (evs.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				exit = 1;
			}
			else {
				if (evs.type == ALLEGRO_EVENT_TIMER) {
					//graphic_handler.do_walking_step();
					graphic_handler.do_jumping_step();
					al_flip_display();
				}
			}
		}
	

	} while (!exit);
	
	al_destroy_display(display);

	system("pause");
	return 0;

}