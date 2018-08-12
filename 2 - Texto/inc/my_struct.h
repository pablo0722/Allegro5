#ifndef MY_STRUCT_H
#define MY_STRUCT_H


#include "debug.h"
#include "my_allegro.h"


#define MAX_FONTS 32

typedef struct my_app
{
    ALLEGRO_FONT *fonts[MAX_FONTS];
} t_my_app;


void init_my_struct(t_my_app *app_struct);

void delete_my_struct(t_my_app *app_struct);


#endif // MY_STRUCT_H
