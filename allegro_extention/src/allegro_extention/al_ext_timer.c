/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include "allegro_extention/al_ext_timer.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>

#include "allegro_extention/al_ext_priv.h"










/**********************************************************************
 * 							FUNCIONES PUBLICAS
 **********************************************************************/
void al_ext_loop_set_start_callback( void (*start_callback)(int window_width, int window_height, void *arg) )
{
    _al_ext_global.start_callback = start_callback;
}










void al_ext_loop_set_logic_callback( bool (*logic_callback)(int window_width, int window_height, void *arg) )
{
    _al_ext_global.logic_callback = logic_callback;
}










void al_ext_loop_set_draw_callback( void (*draw_callback)(int window_width, int window_height, void *arg) )
{
    _al_ext_global.draw_callback = draw_callback;
}










void al_ext_loop(void *arg)
{
    bool loop = true;
    bool redraw = true;
    ALLEGRO_EVENT event;

    al_reserve_samples(_al_ext_global.num_sounds);

    _al_ext_global.start_callback(_al_ext_global.window_width, 
                                  _al_ext_global.window_height, 
                                  arg);
    
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

        // KEYBOARD
            if(event.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                _al_ext_global.key[event.keyboard.keycode] = true;
            }

            else if(event.type == ALLEGRO_EVENT_KEY_UP)
            {
                _al_ext_global.key[event.keyboard.keycode] = false;
            }

        // MOUSE
            else if( (event.type == ALLEGRO_EVENT_MOUSE_AXES) |
                (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) |
                (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) |
                (event.type == ALLEGRO_EVENT_MOUSE_WARPED) )
            {
                al_get_mouse_state(& _al_ext_global.mouse_state);
            }

        // TIMER
            else if(event.type == ALLEGRO_EVENT_TIMER)
            {
                redraw = true;

                loop = _al_ext_global.logic_callback(_al_ext_global.window_width, 
                                                     _al_ext_global.window_height, 
                                                     arg);
            }

        // KEYBOARD
            if(redraw && al_is_event_queue_empty(_al_ext_global.event_queue))
            {
                _al_ext_global.draw_callback(_al_ext_global.window_width, 
                                             _al_ext_global.window_height, 
                                             arg);
                al_flip_display();
                //al_clear_to_color(al_map_rgb(0, 0, 0));

                redraw = false;
            }
        }
    }
}
