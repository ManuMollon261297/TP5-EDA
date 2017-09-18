#pragma once
#include <allegro5\allegro5.h>
#include <string>
#include "Worm.h"

using namespace std;

class graphic_movement
{

public:

	unsigned int no_motion_count;
	unsigned int warmup_count;
	unsigned int ws_state;
	unsigned int walking_count;
	unsigned int repeat_ws_seq;

	unsigned int jump_count;
	unsigned int landing_count;
	unsigned int not_jump_count;
	
	unsigned int cant_walk_imgs;
	unsigned int cant_jump_imgs;

	ALLEGRO_BITMAP ** jump_img_lib;
	ALLEGRO_BITMAP ** walk_img_lib;
	ALLEGRO_BITMAP * background;

	string prefix_walk;
	string prefix_jump;
	string prefix_background;
	string extension;

	graphic_movement();
	void init();
	void create_images_arr();
	void load_walk_imgs();
	void load_background();
	void flip_background();
	void do_walking_step(Worm worm);
	void do_jumping_step(Worm worm);
	void load_jump_imgs();

	~graphic_movement();
};

