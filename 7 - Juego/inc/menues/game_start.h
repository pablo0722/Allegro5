#ifndef GAME_START_H_
#define GAME_START_H_










/************************************************************************/
/* 							INLCUDES                                    */
/************************************************************************/
#include <allegro5/allegro.h>

#include "my_struct.h"










/************************************************************************/
/* 							PROTOTIPOS PUBLICOS                         */
/************************************************************************/
bool logic_game_start   (int window_width, int window_height, my_app_t *app_struct);

bool draw_game_start    (int window_width, int window_height, my_app_t *app_struct);










#endif // GAME_START_H_