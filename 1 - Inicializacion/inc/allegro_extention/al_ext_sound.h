#ifndef AL_EXT_SOUND_H_
#define AL_EXT_SOUND_H_










/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>










/**********************************************************************
 * 							PROTOTIPOS PUBLICOS
 **********************************************************************/
ALLEGRO_SAMPLE * al_ext_load_sound(const char * audio_filename, int simultaneous_instances);
void al_ext_play_sound(ALLEGRO_SAMPLE * sample, ALLEGRO_PLAYMODE playmode);










#endif // AL_EXT_SOUND_H_
