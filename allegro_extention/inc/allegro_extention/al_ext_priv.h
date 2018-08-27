#ifndef MY_ALLEGRO_PRIV_H_
#define MY_ALLEGRO_PRIV_H_


#include "allegro_extention/al_ext.h"



typedef struct my_app_priv
{
    bool key[ALLEGRO_KEY_MAX];

    int window_width;
    int window_height;

    ALLEGRO_DISPLAY *       window_handler;
    ALLEGRO_TIMER *         timer;
    ALLEGRO_EVENT_QUEUE *   event_queue;
    
    ALLEGRO_MOUSE_STATE mouse_state;
    
    void (*start_callback)( int window_width, int window_height, void *arg);
    bool (*logic_callback)( int window_width, int window_height, void *arg);
    void (*draw_callback)(  int window_width, int window_height, void *arg);

    int num_sounds;
} t_al_ext_global;


extern t_al_ext_global _al_ext_global;



#endif // MY_ALLEGRO_PRIV_H_