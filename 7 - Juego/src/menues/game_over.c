/****************************************************************************/
/* 							INLCUDES                                        */
/****************************************************************************/
#include <allegro5/allegro.h>

#include "my_struct.h"
#include "my_aplication.h"










/****************************************************************************/
/*							LOGICA GAME START                               */
/****************************************************************************/
bool logic_game_over(int window_width, int window_height, my_app_t *app_struct)
{
	assert(app_struct);

    unsigned char *menu;

	assert(app_struct);

    menu = &(app_struct->menu);

	assert(menu);

    if(al_ext_key(ALLEGRO_KEY_ENTER))
    {
        my_app_start(window_width, window_height, app_struct);
        (*menu) = MENU_GAME_START;
    }

    if(al_ext_key(ALLEGRO_KEY_ESCAPE))
    {
        (*menu) = MENU_EXIT;
    }
    
    return true;
}










/****************************************************************************/
/*							DRAW GAME START                                 */
/****************************************************************************/
bool draw_game_over( int window_width, int window_height, my_app_t *app_struct)
{
	assert(app_struct);


    ALLEGRO_FONT *font  = app_struct->fonts[FONT_START];

	assert(font);


    al_draw_text(font, al_map_rgb(255, 0, 0), 
                 window_width/2, window_height/2-al_get_font_line_height(font)*3/2,  
                 ALLEGRO_ALIGN_CENTER, "HAS PERDIDO");

    al_draw_text(font, al_map_rgb(0, 255, 0), 
                 window_width/2, window_height/2-al_get_font_line_height(font)/2,  
                 ALLEGRO_ALIGN_CENTER, "PRESIONAR ENTER PARA EMPEZAR");

    al_draw_text(font, al_map_rgb(0, 255, 0), 
                 window_width/2, window_height/2+al_get_font_line_height(font)/2, 
                 ALLEGRO_ALIGN_CENTER, "PRESIONAR ESCAPE PARA SALIR");


    return true;
}