/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include "allegro_extention/al_ext_sound.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>

#include "allegro_extention/al_ext_priv.h"










/**********************************************************************
 * 							FUNCIONES PUBLICAS
 **********************************************************************/
ALLEGRO_SAMPLE * al_ext_load_sound(const char * audio_filename, int simultaneous_instances)
{
    _al_ext_global.num_sounds += simultaneous_instances;

    return al_load_sample(audio_filename);
}










void al_ext_play_sound(ALLEGRO_SAMPLE * sample, ALLEGRO_PLAYMODE playmode)
{
    al_play_sample(sample, 1, 0, 1, playmode, NULL);
}