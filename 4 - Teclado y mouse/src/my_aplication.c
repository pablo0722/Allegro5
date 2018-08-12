/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include "allegro_extention/al_ext.h"
#include "allegro_extention/al_ext_priv.h"
#include "my_aplication.h"










/**********************************************************************
 * 							FORWARDS PRIVADAS
 **********************************************************************/
void logic(my_app_t *app_struct);










/**********************************************************************
 * 							FUNCIONES PUBLICAS
 **********************************************************************/
void init_aplication(my_app_t*app_struct)
{
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *bear = NULL;

	assert(app_struct);

        // Carga imagenes
    background = al_ext_load_img("./imagenes/fondo.bmp");
    bear = al_ext_load_img("./imagenes/oso.bmp");

    assert(background);
    assert(bear);

    app_struct->images[IMG_BACKGROUND] = background;
    app_struct->images[IMG_BEAR] = bear;

    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_flip_display();
}










void do_aplication(my_app_t *app_struct)
{
	assert(app_struct);

    logic(app_struct);
    
    al_flip_display();
}










void logic(my_app_t *app_struct)
{
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *bear = NULL;

	assert(app_struct);

    background = app_struct->images[IMG_BACKGROUND];
    bear = app_struct->images[IMG_BEAR];

	assert(background);
	assert(bear);

    int *pos_x = &(app_struct->pos_x);
    int *pos_y = &(app_struct->pos_y);
    int *mode = &(app_struct->mode);

	assert(pos_x);
	assert(pos_y);
	assert(mode);

    ALLEGRO_KEYBOARD_STATE keyboard_state;
    ALLEGRO_MOUSE_STATE mouse_state;

    al_get_keyboard_state(&keyboard_state);
    al_get_mouse_state(&mouse_state);

    if(al_key_down(&keyboard_state, ALLEGRO_KEY_ENTER)) // Si apreta ENTER
    {
        (*mode) = KEYBOARD;
    }
    
    if (mouse_state.buttons & (1 << 0)) // Si apreta click izquierdo del mouse
    {
        (*mode) = MOUSE;
    }

    if((*mode) == KEYBOARD)
    {
        if(al_key_down(&keyboard_state, ALLEGRO_KEY_UP))
        {
            (*pos_y)--;
        }
        if(al_key_down(&keyboard_state, ALLEGRO_KEY_DOWN))
        {
            (*pos_y)++;
        }
        if(al_key_down(&keyboard_state, ALLEGRO_KEY_LEFT))
        {
            (*pos_x)--;
        }
        if(al_key_down(&keyboard_state, ALLEGRO_KEY_RIGHT))
        {
            (*pos_x)++;
        }
    }
    else
    {
        (*pos_x) = mouse_state.x;
        (*pos_y) = mouse_state.y;
    }

    al_draw_bitmap(background, 0, 0, 0);
    al_draw_bitmap(bear, *pos_x, *pos_y, 0);
}










void my_allegro_exit(my_app_t *app_struct)
{
	assert(app_struct);

    delete_my_struct(app_struct);
}
