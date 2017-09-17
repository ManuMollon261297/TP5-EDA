#include "walk_move.h"

unsigned int cant_walk_imgs = 15;
enum { NOMOTION, WARMUP, WALKING };
const unsigned int wwalkingseq_arr[14] = { 4,5,6,7,8,9,10,11,11,12,13,14,15,4 };

walk_move::walk_move()
{
	walk_img_lib = new ALLEGRO_BITMAP*[cant_walk_imgs];
}


walk_move::~walk_move()
{
	for (unsigned int i = 0; i < cant_walk_imgs; i++) {
		al_destroy_bitmap(walk_img_lib[i]);
	}
	delete[] walk_img_lib;
}

void walk_move::init_walk_vars() {


	px = 300.0;
	py = 300.0;

	orientation = 0;


	cant_walk_imgs = 15;
	prefix_walk = "Worms Images/wwalking/wwalk-F";
	walking_count = 0;
	warmup_count = 0;
	ws_state = 0;
	repeat_ws_seq = 3;
	no_motion_count = 0;


	for (unsigned int i = 0; i < cant_walk_imgs; i++) {
		walk_img_lib[i] = nullptr;
	}


}
void walk_move::do_walking_step() {
	switch (ws_state) {
	case NOMOTION:
		if (no_motion_count < 5) {
			printf("nomoves\n");
			no_motion_count++;
		}
		else {
			no_motion_count = 0;
			ws_state = WARMUP; // Si termine el no motion state voy a warmup
		}

		break;
	case WARMUP:
		if (warmup_count < 3) {
			
			al_draw_bitmap(walk_img_lib[warmup_count], px, py, orientation);
			printf("warmup_count=%d \n", warmup_count);
			warmup_count++;
		}
		else {
			ws_state = WALKING;
			warmup_count = 0;
		}
		break;

	case WALKING:
		if (walking_count < 14) { // Tengo la secuencia de 15 imagenes y como itero en un array i llega a 14
			al_draw_bitmap(walk_img_lib[wwalkingseq_arr[walking_count] - 1], px, py, orientation);
				walking_count++;
			if (walking_count == 14 && repeat_ws_seq) {
				walking_count = 0;
				printf("repeat_ws_seq = %d\n", repeat_ws_seq);
				repeat_ws_seq--;
			}
		}
		else {
			walking_count = 0;
			ws_state = NOMOTION;
			repeat_ws_seq = 3;
		}

		break;
	}
}

void walk_move::load_walk_imgs() {
	for (unsigned int i = 0; i < cant_walk_imgs; i++) { // el 1 es por F1, F2.. etc
		string extension = ".png";
		string aux = prefix_walk + to_string(i + 1) + extension;
		printf("%s\n", &aux[0]);
		walk_img_lib[i] = al_load_bitmap(&aux[0]);

	}
}