#pragma once	


#include <allegro5\allegro5.h>
#include <allegro5\allegro_image.h>
#include <string>

using namespace std;

class jump_move
{
private:
	unsigned int js_state;
	unsigned int jump_count;
	unsigned int landing_count;
	unsigned int not_jump_count;
	string prefix_jump;
	ALLEGRO_BITMAP **jump_img_lib;

public:
	double px;
	double py;

	bool orientation; // 0 gusano mira izquierda, 1 gusano mira derecha

	jump_move();


	void init_jump_vars();
	void load_jump_imgs();
	void do_jumping_step();


	~jump_move();
};