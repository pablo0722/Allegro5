#ifndef MY_ALLEGRO_PRIV_H
#define MY_ALLEGRO_PRIV_H


#include "my_allegro.h"



typedef struct my_app_priv
{
    ALLEGRO_DISPLAY * window_handler;
} t_my_app_priv;


extern t_my_app_priv _my_app_priv;



#endif // MY_ALLEGRO_PRIV_H