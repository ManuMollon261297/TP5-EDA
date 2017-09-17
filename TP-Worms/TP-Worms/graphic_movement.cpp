#include "graphic_movement.h"

enum { NOMOTION, WARMUP, WALKING };
const unsigned int wwalkingseq_arr[14] = { 4,5,6,7,8,9,10,11,11,12,13,14,15,4 };
// el salto tarda 33 frames y el resto (o sea 50-33) los hago con las animaciones de "aterrizaje"
const unsigned int wjumpingseq_arr[11] = { 1,2,3,3,3,3,3,3,3,3,3 };
const unsigned int wlandingseq_arr[17] = { 3,3,4,4,4,5,5,5,6,6,7,7,8,8,8,8,9 };

enum { NOT_JUMPING,JUMPING,LANDING};
graphic_movement::graphic_movement()
{
	
};

void graphic_movement::create_images_arr() {

	walk_img_lib = new ALLEGRO_BITMAP*[cant_walk_imgs];
	jump_img_lib = new ALLEGRO_BITMAP*[cant_jump_imgs];
}

void graphic_movement::init() {
	
	prefix_walk = "Worms Images/wwalking/wwalk-F";
	prefix_jump = "Worms Images/wjump/wjump-F";
	prefix_background = "Worms Images/Scenario";
	extension = ".png";
	walking_count = 0;
	no_motion_count = 0;
	landing_count = 0;
	not_jump_count = 0;
	jump_count = 0;
	warmup_count = 0;
	ws_state = 0;
	js_state = 0;
	repeat_ws_seq = 3;

	cant_walk_imgs=15;
	cant_jump_imgs=10;
	for (unsigned int i = 0; i < cant_walk_imgs; i++) {
		walk_img_lib[i] = nullptr;
	}

	for (unsigned int i = 0; i < cant_jump_imgs; i++) {
		jump_img_lib[i] = nullptr;
	}

	background = nullptr;


}

graphic_movement::~graphic_movement()
{
	/*
	for (int i = 0; i < cant_walk_imgs; i++) {
		al_destroy_bitmap(walk_img_lib[i]);
	}
	for (int i = 0; i < cant_jump_imgs; i++) {
		al_destroy_bitmap(jump_img_lib[i]);
	}

	
	delete[] walk_img_lib;
	delete[] jump_img_lib;
	*/
}



void graphic_movement::load_walk_imgs() {

	for (unsigned int i = 0; i < cant_walk_imgs; i++) { // el 1 es por F1, F2.. etc
		//string extension = ".png";
		string aux = prefix_walk + to_string(i+1) + extension;
		printf("%s\n", &aux[0]);
		walk_img_lib[i] = al_load_bitmap(&aux[0]);

	}
}

void graphic_movement::load_jump_imgs() {

	for (unsigned int i = 0; i < cant_jump_imgs; i++) { // el 1 es por F1, F2.. etc
		string extension = ".png";
		string aux = prefix_jump + to_string(i + 1) + extension;
		printf("%s\n", &aux[0]);
		jump_img_lib[i] = al_load_bitmap(&aux[0]);

	}
}

void graphic_movement::load_background()
{
	string aux = prefix_background + extension;
	background = al_load_bitmap(&aux[0]);
}


void graphic_movement::do_jumping_step(Worm worm) {
	switch (js_state) {
	case NOT_JUMPING:
		if (not_jump_count < 5) {
			//printf("nomoves\n");
			not_jump_count++;
		}
		else {
			not_jump_count = 0;
			js_state = JUMPING; // Si termine el no motion state voy a warmup
		}

		break;
	case JUMPING: // deberia saltar y saltar mientras esta saltando
		if (jump_count < 33) {
			//al_draw_bitmap(jump_img_lib[jump_count], 100.0, 100.0, 0);
// IMAGES LIB NO ES EL MIMSO PARA LOS DOS
			
			if (jump_count >= 11) {
				jump_count++;
				al_draw_bitmap(jump_img_lib[wjumpingseq_arr[8]], 100.0, 100.0, 0);

			}
			else {
				al_draw_bitmap(jump_img_lib[wjumpingseq_arr[jump_count] - 1], 100.0, 100.0, 0);
				jump_count++;
			}
		}
		else {
			js_state = LANDING;
			jump_count = 0;		
		}
		break;

	case LANDING:
		if (landing_count < 17) { 
			al_draw_bitmap(jump_img_lib[wlandingseq_arr[landing_count] - 1], 100.0, 100.0, 0);
			landing_count++;
		}
		else {
			landing_count = 0;
			js_state = NOT_JUMPING;
			//repeat_js_seq = 3;
		}

		break;
	}
	
}

void graphic_movement::do_walking_step(Worm worm) {
	switch (ws_state) {
	case NOMOTION:
		if (no_motion_count < 5) {
			//printf("nomoves\n");
			no_motion_count++;
		}
		else {
			no_motion_count = 0;
			ws_state = WARMUP; // Si termine el no motion state voy a warmup
		}

		break;
	case WARMUP:
		if (warmup_count < 3) {
			al_draw_bitmap(walk_img_lib[warmup_count], 200.0, 200.0, 0);
			printf("K=%d",warmup_count);
			warmup_count++;
		}
		else {
			ws_state = WALKING;
			warmup_count = 0;
		}
		break;

	case WALKING:
		if (walking_count < 14){ // Tengo la secuencia de 15 imagenes y como itero en un array i llega a 14
			
			al_draw_bitmap(walk_img_lib[wwalkingseq_arr[walking_count] - 1], 200.0, 200.0, 0);
			walking_count++;
			if (walking_count == 14 && repeat_ws_seq) {
				walking_count = 0;
				printf("wcount = %d\n", repeat_ws_seq);
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

void graphic_movement::flip_background()
{
	al_draw_bitmap(background, 0, 0, 0);
	al_flip_display();
}