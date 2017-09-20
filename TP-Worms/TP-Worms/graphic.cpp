#include "graphic.h"
#define MOV 9

enum { NOMOTION, WARMUP, WALKING };
const unsigned int cant_images = 15;
const unsigned int wwalkingseq_arr[14] = { 4,5,6,7,8,9,10,11,11,12,13,14,15,4 };
graphic::graphic()
{
	
}

void graphic::create_images_arr() {
	images_lib = new ALLEGRO_BITMAP*[cant_images];
}

void graphic::init() {
	prefix = "Worms Images/wwalking/wwalk-F";
	walking_count = 0;
	no_motion_count = 0;
	warmup_count = 0;
	state = 0;
	for (unsigned int i = 0; i < cant_images; i++) {
		images_lib[i] = nullptr;

	}
}

graphic::~graphic()
{
	for (int i = 0; i < cant_images; i++) {
		al_destroy_bitmap(images_lib[i]);
	}

	delete[] images_lib;
}



void graphic::load_images() {

	for (unsigned int i = 0; i < cant_images; i++) { // el 1 es por F1, F2.. etc
		string extension = ".png";
		string aux = prefix+ to_string(i+1) + extension;
		printf("%s\n", &aux[0]);
		images_lib[i] = al_load_bitmap(&aux[0]);

	}
}



void graphic::do_walking_step() {
	switch (state) {
	case NOMOTION:
		if (no_motion_count < 5) {
			printf("nomoves\n");
			no_motion_count++;
		}
		else {
			no_motion_count = 0;
			state = WARMUP; // Si termine el no motion state voy a warmup
		}

		break;
	case WARMUP:
		if (warmup_count < 3) {
			al_draw_bitmap(images_lib[warmup_count], 100.0, 100.0, 0);
			printf("K=%d",warmup_count);
			warmup_count++;
		}
		else {
			state = WALKING;
			warmup_count = 0;
		}
		break;

	case WALKING:
		if (walking_count < 14){ // Tengo la secuencia de 15 imagenes y como itero en un array i llega a 14
			printf("I = %d\n", i);
			al_draw_bitmap(images_lib[wwalkingseq_arr[walking_count] - 1], 100.0, 100.0, 0);
			walking_count++;

		}
		else {
			walking_count = 0;
			state = NOMOTION;
		}

		break;
	}
}