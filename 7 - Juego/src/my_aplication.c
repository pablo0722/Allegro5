/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include <stdlib.h> // srand(), rand()
#include <time.h>   // time()

#include "allegro_extention/al_ext.h"
#include "my_aplication.h"

#include "menues/main_menu.h"
#include "menues/game_start.h"
#include "menues/game_over.h"










/**********************************************************************
 * 							FUNCIONES PUBLICAS
 **********************************************************************/
void my_app_init(my_app_t *app_struct)
{
    ALLEGRO_FONT    * font          = NULL;
    ALLEGRO_BITMAP  * background    = NULL,
                    * sonic         = NULL,
                    * fire          = NULL;
    ALLEGRO_SAMPLE  * music         = NULL;

	assert(app_struct);
    
    my_struct_init(app_struct);

        // Carga fuentes
    font = al_load_font("/usr/share/fonts/truetype/freefont/FreeSans.ttf", 20, 0);
    
    assert(font);

        // Carga imagenes
    background  = al_ext_load_img("./imagenes/background.bmp");
    sonic       = al_ext_load_img("./imagenes/sonic.bmp");
    fire        = al_ext_load_img("./imagenes/fire.bmp");

    assert(background);
    assert(sonic);
    assert(fire);

        // Carga sonidos
    music = al_ext_load_sound("./sonidos/music.wav", 1);
    
    assert(music);
    
        // Guardo todo en la estructura
    app_struct->fonts[FONT_START]       = font;

    app_struct->images[IMG_BACKGROUND]  = background;
    app_struct->images[IMG_SONIC]       = sonic;
    app_struct->images[IMG_FIRE]        = fire;

    app_struct->sounds[SND_MUSIC] = music;

    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_flip_display();
}










void my_app_start(int window_width, int window_height, void * arg)
{
    my_app_t *app_struct = (my_app_t *) arg;

	assert(app_struct);
    
    unsigned char *menu = &(app_struct->menu);
    float *pos_x = &(app_struct->pos_x);
    float *pos_y = &(app_struct->pos_y);

	assert(menu);
	assert(pos_x);
	assert(pos_y);

    srand(time(NULL));  // Genero semilla

    app_struct->time = 0;

    ALLEGRO_BITMAP *fire = app_struct->images[IMG_FIRE];

	assert(fire);

    int fire_w = al_get_bitmap_width(fire)/IMG_FIRE_MAX;

    int i;

    for(i=0; i<NUM_FIRES; i++)
    {
        app_struct->fire_x[i] = rand()%(window_width - fire_w);
        app_struct->fire_y[i] = -(((i+1)*window_height)/NUM_FIRES);  //Para que se generen con una distancia entre los fuegos
    }

    app_struct->fire_img = IMG_FIRE_0;

    app_struct->pos_x = window_width/2;
    app_struct->pos_y = window_height;
    app_struct->menu = MENU_MAIN_MENU;

    al_ext_play_sound(app_struct->sounds[SND_MUSIC], ALLEGRO_PLAYMODE_LOOP);
}










bool my_app_logic(int window_width, int window_height, void * arg)
{
    my_app_t *app_struct = (my_app_t *) arg;
    bool keep_looping = true;

	assert(app_struct);

	app_struct->time += 1000.0/FPS;

    unsigned char *menu = &(app_struct->menu);

	assert(menu);

    switch(*menu)
    {
        case MENU_MAIN_MENU:
                keep_looping = logic_main_menu(window_width, window_height, app_struct);
            break;

        case MENU_GAME_START:
                keep_looping = logic_game_start(window_width, window_height, app_struct);
            break;

        case MENU_GAME_OVER:
                keep_looping = logic_game_over(window_width, window_height, app_struct);
            break;

        case MENU_EXIT:
                keep_looping = false;
            break;
    }

    return keep_looping;
}










void my_app_draw(int window_width, int window_height, void * arg)
{
    my_app_t *app_struct = (my_app_t *) arg;

	assert(app_struct);

    unsigned char *menu = &(app_struct->menu);
    
	assert(menu);

    switch(*menu)
    {
        case MENU_MAIN_MENU:
                draw_main_menu(window_width, window_height, app_struct);
            break;
        case MENU_GAME_START:
                draw_game_start(window_width, window_height, app_struct);
            break;
        case MENU_GAME_OVER:
                draw_game_over(window_width, window_height, app_struct);
            break;
    }
}










void my_app_exit(my_app_t *app_struct)
{
	assert(app_struct);

    my_struct_delete(app_struct);
}
