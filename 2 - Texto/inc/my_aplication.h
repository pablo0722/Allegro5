#ifndef MY_APLICACION_H
#define MY_APLICACION_H


#include "debug.h"
#include "my_struct.h"


void my_app_init(t_my_app *app_struct);

void my_aplicacion(t_my_app *app_struct);

void my_allegro_exit(t_my_app *app_struct);


#endif // MY_APLICACION_H
