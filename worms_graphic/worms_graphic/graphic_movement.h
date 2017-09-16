#pragma once
#include <allegro5\allegro5.h>
#include <string>

using namespace std;

class graphic_movement
{

public:

	unsigned int no_motion_count;
	unsigned int warmup_count;
	unsigned int ws_state;
	unsigned int walking_count;
	unsigned int repeat_ws_seq;

	unsigned int js_state;
	unsigned int jump_count;
	unsigned int landing_count;
	unsigned int not_jump_count;
	
	unsigned int cant_walk_imgs;
	unsigned int cant_jump_imgs;

	ALLEGRO_BITMAP ** jump_img_lib;
	ALLEGRO_BITMAP ** walk_img_lib;

	string prefix_walk;
	string prefix_jump;

	graphic_movement();
	void init();
	void create_images_arr();
	void load_walk_imgs();
	void do_walking_step();
	void do_jumping_step();
	void load_jump_imgs();

	~graphic_movement();
};

