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

    app_struct->images[IMG_FONDO] = background;
    app_struct->images[IMG_OSO] = bear;

    al_clear_to_color(al_map_rgb(255,0,255));  // Pinta todo el bufer de magenta.
                                                 // El magenta (255, 0, 255), se usa como color transparente.

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

    background = app_struct->images[IMG_FONDO];
    bear = app_struct->images[IMG_OSO];

	assert(background);
	assert(bear);

    al_draw_bitmap(background, 0, 0, 0);

    al_draw_bitmap(bear, 0, 0, 0);
}










void my_allegro_exit(my_app_t *app_struct)
{
	assert(app_struct);

    delete_my_struct(app_struct);
}
