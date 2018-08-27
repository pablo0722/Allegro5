/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include "allegro_extention/al_ext.h"
#include "allegro_extention/al_ext_priv.h"
#include "my_aplication.h"










/**********************************************************************
 * 							FUNCIONES PUBLICAS
 **********************************************************************/
void my_app_init(my_app_t *app_struct)
{
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *bear = NULL;

	assert(app_struct);
    
    my_struct_init(app_struct);

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










bool my_app_logic(int window_width, int window_height, void * arg)
{
    my_app_t *app_struct = (my_app_t *) arg;

    bool keep_looping = true;

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

    if(al_ext_key(ALLEGRO_KEY_ENTER)) // Si apreta ENTER
    {
        (*mode) = KEYBOARD;
    }
    
    if (al_ext_mouse_button_left()) // Si apreta click izquierdo del mouse
    {
        (*mode) = MOUSE;
    }

    if((*mode) == KEYBOARD)
    {
        if(al_ext_key(ALLEGRO_KEY_UP))
        {
            (*pos_y)--;
        }
        if(al_ext_key(ALLEGRO_KEY_DOWN))
        {
            (*pos_y)++;
        }
        if(al_ext_key(ALLEGRO_KEY_LEFT))
        {
            (*pos_x)--;
        }
        if(al_ext_key(ALLEGRO_KEY_RIGHT))
        {
            (*pos_x)++;
        }
    }
    else
    {
        (*pos_x) = al_ext_mouse_pos_x();
        (*pos_y) = al_ext_mouse_pos_y();
    }
    
    if(al_ext_key(ALLEGRO_KEY_ESCAPE))
    {
        keep_looping = false;
    }

    return keep_looping;
}










void my_app_draw(int window_width, int window_height, void * arg)
{
    my_app_t *app_struct = (my_app_t *) arg;

    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *bear = NULL;

	assert(app_struct);

    background = app_struct->images[IMG_BACKGROUND];
    bear = app_struct->images[IMG_BEAR];

	assert(background);
	assert(bear);

    int *pos_x = &(app_struct->pos_x);
    int *pos_y = &(app_struct->pos_y);

	assert(pos_x);
	assert(pos_y);

    al_draw_bitmap(background, 0, 0, 0);
    al_draw_bitmap(bear, *pos_x, *pos_y, 0);
}










void my_app_exit(my_app_t *app_struct)
{
	assert(app_struct);

    my_struct_delete(app_struct);
}
