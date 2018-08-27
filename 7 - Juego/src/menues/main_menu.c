/****************************************************************************/
/* 							INLCUDES                                        */
/****************************************************************************/
#include <allegro5/allegro.h>

#include "my_struct.h"










/****************************************************************************/
/*							LOGICA MAIN MENU                                */
/****************************************************************************/
bool logic_main_menu(int window_width, int window_height, my_app_t *app_struct)
{
    unsigned char *menu;

	assert(app_struct);

    menu = &(app_struct->menu);

	assert(menu);

    if(al_ext_key(ALLEGRO_KEY_ENTER))
        (*menu) = MENU_GAME_START;

    if(al_ext_key(ALLEGRO_KEY_ESCAPE))
        (*menu) = MENU_EXIT;


    return true;
}











/****************************************************************************/
/*							DRAW MAIN MENU                                  */
/****************************************************************************/
bool draw_main_menu(int window_width, int window_height, my_app_t *app_struct)
{
    ALLEGRO_FONT *font;

	assert(app_struct);


    font = app_struct->fonts[FONT_START];

	assert(font);

    
    al_draw_text(font, al_map_rgb(0, 255, 0), 
                 window_width/2, window_height/2-al_get_font_line_height(font)/2,  
                 ALLEGRO_ALIGN_CENTER, "PRESIONAR ENTER PARA EMPEZAR");

    al_draw_text(font, al_map_rgb(0, 255, 0), 
                 window_width/2, window_height/2+al_get_font_line_height(font)/2, 
                 ALLEGRO_ALIGN_CENTER, "PRESIONAR ESCAPE PARA SALIR");


    return true;
}