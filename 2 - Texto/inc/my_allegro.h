#ifndef MY_ALLEGRO_H
#define MY_ALLEGRO_H



#include <allegro5/allegro.h> 
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include "debug.h"



enum RET_MY_AL_INIT
{
    AL_OK,
    AL_ERROR_ALLEGRO_INIT,
    AL_ERROR_VIDEO_ADAPTER,
    AL_ERROR_WINDOW,
};



int al_init_window(float width_relative, float height_relative);
int al_init_fullscreen(int width, int height);
int al_init_fullscreen_desktop();
int al_init_log();

const char * al_browse_file(char const * initial_path, char const * title, char const * patterns);



#endif // MY_ALLEGRO_H
