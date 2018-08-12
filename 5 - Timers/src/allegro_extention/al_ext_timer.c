/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include "allegro_extention/al_ext_timer.h"

#include <allegro5/allegro.h>

#include "allegro_extention/al_ext_priv.h"










/**********************************************************************
 * 							FUNCIONES PUBLICAS
 **********************************************************************/
void al_ext_loop_set_logic_callback( bool (*logic_callback)(void *arg) )
{
    _al_ext_global.logic_callback = logic_callback;
}

void al_ext_loop_set_draw_callback( void (*draw_callback)(void *arg) )
{
    _al_ext_global.draw_callback = draw_callback;
}



void al_ext_loop(void *arg)
{
    bool loop = true;
    ALLEGRO_EVENT event;

    al_start_timer(_al_ext_global.timer);

    while(loop)
    {    
        al_wait_for_event(_al_ext_global.event_queue, &event);

        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            loop = false;
        }

        else 
        {
            if(event.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                _al_ext_global.key[event.keyboard.keycode] = true;
            }

            if(event.type == ALLEGRO_EVENT_KEY_UP)
            {
                _al_ext_global.key[event.keyboard.keycode] = false;
            }

            if( (event.type == ALLEGRO_EVENT_MOUSE_AXES) |
                (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) |
                (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) |
                (event.type == ALLEGRO_EVENT_MOUSE_WARPED) )
            {
                al_get_mouse_state(& _al_ext_global.mouse_state);
            }

            if(event.type == ALLEGRO_EVENT_TIMER)
            {
                loop = _al_ext_global.logic_callback(arg);
            }

            if(al_is_event_queue_empty(_al_ext_global.event_queue))
            {
                _al_ext_global.draw_callback(arg);
                al_flip_display();
                al_clear_to_color(al_map_rgb(0, 0, 0));
            }
        }
    }
}
