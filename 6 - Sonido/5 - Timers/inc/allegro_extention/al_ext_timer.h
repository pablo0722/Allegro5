#ifndef AL_EXT_TIMER_H_
#define AL_EXT_TIMER_H_










/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include <allegro5/allegro.h>










/**********************************************************************
 * 							PROTOTIPOS PUBLICOS
 **********************************************************************/
void al_ext_loop_set_logic_callback(    bool (*logic_callback)(void *arg) );
void al_ext_loop_set_draw_callback(     void (*draw_callback)(void *arg) );
void al_ext_loop(                       void *arg );










#endif // AL_EXT_TIMER_H_
