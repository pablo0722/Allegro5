/**********************************************************************
 * 							INCLUDES
 **********************************************************************/
#include "allegro_extention/al_ext_keyboard.h"

#include <allegro5/allegro.h>

#include "allegro_extention/al_ext_priv.h"










/**********************************************************************
 * 							FUNCIONES PUBLICAS
 **********************************************************************/
bool al_ext_key(int keycode)
{
    assert(keycode < ALLEGRO_KEY_MAX);

    return _al_ext_global.key[keycode];
}