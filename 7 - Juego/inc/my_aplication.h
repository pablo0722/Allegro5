#ifndef MY_APLICACION_H_
#define MY_APLICACION_H_










/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include <allegro5/allegro.h>

#include "my_struct.h"










/**********************************************************************
 * 							PROTOTIPOS PUBLICOS
 **********************************************************************/
void my_app_init(   my_app_t *app_struct);

void my_app_start(  int window_width, int window_height, void * arg);
bool my_app_logic(  int window_width, int window_height, void * arg);
void my_app_draw(   int window_width, int window_height, void * arg);

void my_app_exit(   my_app_t *app_struct);










#endif // MY_APLICACION_H_
