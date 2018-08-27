/**********************************************************************
 * 							INCLUDES
 **********************************************************************/
#include "allegro_extention/al_ext_mouse.h"

#include <allegro5/allegro.h>

#include "allegro_extention/al_ext_priv.h"










/**********************************************************************
 * 							FUNCIONES PUBLICAS
 **********************************************************************/
bool al_ext_mouse_button_left()
{
    return _al_ext_global.mouse_state.buttons & (1 << 0);
}










bool al_ext_mouse_button_right()
{
    return _al_ext_global.mouse_state.buttons & (1 << 1);
}










bool al_ext_mouse_button_middle()
{
    return _al_ext_global.mouse_state.buttons & (1 << 2);
}










int al_ext_mouse_pos_x()
{
    return _al_ext_global.mouse_state.x;
}










int al_ext_mouse_pos_y()
{
    return _al_ext_global.mouse_state.y;
}
