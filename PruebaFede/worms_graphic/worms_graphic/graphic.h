#pragma once
#include <allegro5\allegro5.h>
#include <string>

using namespace std;

class graphic
{
	
public:

	unsigned int no_motion_count;
	unsigned int i;
	unsigned int warmup_count;
	unsigned int state;
	unsigned int walking_count;

	
	ALLEGRO_BITMAP ** images_lib;
	//unsigned int cant_images;

	string prefix;
	graphic();
	void init();
	void create_images_arr();
	void load_images();
	void do_walking_step();

	~graphic();
};

