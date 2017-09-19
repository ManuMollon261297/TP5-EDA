#include "jump_move.h"
#include <cmath>
#define JUMP_ANG ((60.0*3.1415)/180)
#define JUMP_VEL (4.5/50)

unsigned int cant_jump_imgs = 10;
enum { NOT_JUMPING, JUMPING, LANDING };

// el salto tarda 33 frames y el resto (o sea 50-33) los hago con las animaciones de "aterrizaje"
const unsigned int wjumpingseq_arr[11] = { 1,2,3,3,3,3,3,3,3,3,3 };
const unsigned int wlandingseq_arr[17] = { 3,3,4,4,4,5,5,5,6,6,7,7,8,8,8,8,9 };


jump_move::jump_move()
{
	jump_img_lib = new ALLEGRO_BITMAP*[cant_jump_imgs];
}


jump_move::~jump_move()
{
	for (int i = 0; i < cant_jump_imgs; i++) {
		al_destroy_bitmap(jump_img_lib[i]);
	}

	delete[] jump_img_lib;
}

void jump_move::init_jump_vars() {
	cant_jump_imgs = 10;
	prefix_jump = "Worms Images/wjump/wjump-F";
	
	px = 100.0;
	py = 100.0;

	orientation = 0;


	landing_count = 0;
	not_jump_count = 0;
	jump_count = 0;
	js_state = 0;

	for (unsigned int i = 0; i < cant_jump_imgs; i++) {
		jump_img_lib[i] = nullptr;
	}
	
}

void jump_move::do_jumping_step() {
	al_clear_to_color(al_map_rgb_f(0, 0, 0));									//FEDE
	switch (js_state) {
	case NOT_JUMPING:
		if (not_jump_count < 5) {
			printf("nomoves\n");
			not_jump_count++;
		}
		else {
			not_jump_count = 0;
			js_state = JUMPING; // Si termine el no motion state voy a warmup
		}

		break;
	case JUMPING: // deberia saltar y saltar mientras esta saltando
		if (jump_count < 33) {

			if (jump_count >= 11) {
				//Calculo de next position
				px = 100.0 - JUMP_VEL*cos((double)JUMP_ANG)*(((double)jump_count - 11.0) / 50.0);
				py = 100.0 - JUMP_VEL*sin((double)JUMP_ANG)*(((double)jump_count - 11.0) / 50.0) + (0.5)*( 0.24)*pow(((((double)jump_count - 11.0) / 50.0)),2);
				printf("%f %f\n", px, py);
				jump_count++;
				al_draw_bitmap(jump_img_lib[wjumpingseq_arr[8]], px, py, orientation);
				// 8 es el fijo que se queda saltando
			}
			else {
				al_draw_bitmap(jump_img_lib[wjumpingseq_arr[jump_count] - 1], px, py, orientation);
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
			al_draw_bitmap(jump_img_lib[wlandingseq_arr[landing_count] - 1], px, py, orientation);
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

void jump_move::load_jump_imgs() {

	for (unsigned int k = 0; k < cant_jump_imgs; k++) { // el 1 es por F1, F2.. etc
		string extension = ".png";
		string aux = prefix_jump + to_string(k + 1) + extension;
		printf("%s\n", &aux[0]);
		jump_img_lib[k] = al_load_bitmap(&aux[0]);

	}

}
