#pragma once


#include <allegro5\allegro5.h>
#include <allegro5\allegro_image.h>
#include <string>

using namespace std;

class walk_move
{
private:
	unsigned int no_motion_count;
	unsigned int warmup_count;
	unsigned int ws_state;
	unsigned int walking_count;
	unsigned int repeat_ws_seq;
	string prefix_walk;
	ALLEGRO_BITMAP **walk_img_lib;

public:
	double px;
	double py;
	
	bool orientation; // 0 gusano mira izquierda , 1 gusano mira derecha 

	walk_move();

	void load_walk_imgs();
	void init_walk_vars();
	void do_walking_step();

	~walk_move();
};

