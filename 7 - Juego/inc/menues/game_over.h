#ifndef GAME_OVER_H_
#define GAME_OVER_H_










/************************************************************************/
/* 							INLCUDES                                    */
/************************************************************************/
#include <allegro5/allegro.h>

#include "my_struct.h"










/************************************************************************/
/* 							PROTOTIPOS PUBLICOS                         */
/************************************************************************/
bool logic_game_over(int window_width, int window_height, my_app_t *app_struct);

bool draw_game_over (int window_width, int window_height, my_app_t *app_struct);










#endif // GAME_OVER_H_