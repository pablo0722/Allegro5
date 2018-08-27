#ifndef MENUES_H_
#define MENUES_H_










/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include <allegro5/allegro.h>

#include "my_struct.h"










/**********************************************************************
 * 							PROTOTIPOS PUBLICOS
 **********************************************************************/
bool logic_juego(           int window_width, int window_height, my_app_t *app_struct);
bool logic_perdio(          int window_width, int window_height, my_app_t *app_struct);

bool draw_juego(            int window_width, int window_height, my_app_t *app_struct);
bool draw_perdio(           int window_width, int window_height, my_app_t *app_struct);










#endif // MENUES_H_