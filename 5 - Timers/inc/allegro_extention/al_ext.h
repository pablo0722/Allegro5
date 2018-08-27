#ifndef AL_EXT_H_
#define AL_EXT_H_










/************************************************************************/
/* 							DEFINES                                     */
/************************************************************************/
#define FPS 60.0










/************************************************************************/
/* 							INLCUDES                                    */
/************************************************************************/
#include <allegro5/allegro.h> 
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include "allegro_extention/al_ext_debug.h"
#include "allegro_extention/al_ext_bitmap.h"
#include "allegro_extention/al_ext_timer.h"
#include "allegro_extention/al_ext_keyboard.h"
#include "allegro_extention/al_ext_mouse.h"
#include "allegro_extention/al_ext_sound.h"










/**********************************************************************
 * 							ENUMS
 **********************************************************************/
enum RET_MY_AL_INIT
{
    AL_OK,
    AL_ERROR_ALLEGRO_INIT,
    AL_ERROR_VIDEO_ADAPTER,
    AL_ERROR_WINDOW,
};










/**********************************************************************
 * 							PROTOTIPOS PUBLICOS
 **********************************************************************/
int          al_ext_init_window(            float width_relative, float height_relative);
int          al_ext_init_fullscreen(        int width, int height);
int          al_ext_init_fullscreen_desktop(void);
int          al_ext_init_log(               void);
const char * al_ext_browse_file(            char const * initial_path, char const * title, 
                                            char const * patterns);










#endif // AL_EXT_H_
