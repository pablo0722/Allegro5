/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include <allegro5/allegro.h>

#include "my_struct.h"










bool logic_juego(my_app_t *app_struct)
{
    /*
    unsigned char *menu;

	assert(app_struct);

    menu = &(app_struct->menu);

	assert(menu);

    if(al_ext_key(ALLEGRO_KEY_ESCAPE))
    {
        (*menu) = MENU_EXIT;
        return false;
    }

    movimiento_sonic(app_struct);

    generate_fire(app_struct);
    change_fire_img(app_struct);

    if(colision(app_struct))
    {
        (*menu) = MENU_GAME_OVER;
    }


*/
    return true;
}










bool logic_perdio(my_app_t *app_struct)
{
    /*
    unsigned char *menu;

	assert(app_struct);

    menu = &(app_struct->menu);

	assert(menu);

    if(al_ext_key(ALLEGRO_KEY_ENTER))
    {
        //init_juego_vars(app_struct);
        (*menu) = MENU_GAME_START;
    }

    if(al_ext_key(ALLEGRO_KEY_ESCAPE))
        (*menu) = MENU_EXIT;


*/
    return true;
}










/***************************************************************************/
/*							FUNCIONES AUXILIARES			   			   */
/***************************************************************************/
bool draw_juego(            my_app_t *app_struct)
{

    return true;
}










bool draw_perdio(           my_app_t *app_struct)
{

    return true;
}