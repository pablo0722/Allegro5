#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_










/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include <allegro5/allegro.h>

#include "my_struct.h"










/**********************************************************************
 * 							PROTOTIPOS PUBLICOS
 **********************************************************************/
bool logic_main_menu(  int window_width, int window_height, my_app_t *app_struct);

bool draw_main_menu(   int window_width, int window_height, my_app_t *app_struct);










#endif // MAIN_MENU_H_