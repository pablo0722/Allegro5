#ifndef MY_ALLEGRO_PRIV_H_
#define MY_ALLEGRO_PRIV_H_


#include "allegro_extention/al_ext.h"



typedef struct my_app_priv
{
    bool key[ALLEGRO_KEY_MAX];

    ALLEGRO_DISPLAY *       window_handler;
    ALLEGRO_TIMER *         timer;
    ALLEGRO_EVENT_QUEUE *   event_queue;
    
    ALLEGRO_MOUSE_STATE mouse_state;
    
    bool (*logic_callback)(void *arg);
    void (*draw_callback)(void *arg);

    int num_sounds;
} t_al_ext_global;


extern t_al_ext_global _al_ext_global;



#endif // MY_ALLEGRO_PRIV_H_