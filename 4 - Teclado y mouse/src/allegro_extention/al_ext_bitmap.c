/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include "allegro_extention/al_ext_bitmap.h"

#include <allegro5/allegro.h>










/**********************************************************************
 * 							FUNCIONES PUBLICAS
 **********************************************************************/
ALLEGRO_BITMAP *al_ext_load_img(char *img_filename)
{
    ALLEGRO_BITMAP *img = NULL;

	assert(img_filename);

	//al_set_new_bitmap_format(ALLEGRO_PIXEL_FORMAT_ANY_32_WITH_ALPHA | ALLEGRO_KEEP_BITMAP_FORMAT);

	img = al_load_bitmap(img_filename);

    al_convert_mask_to_alpha(img, al_map_rgb(255, 0, 255));

    return img;
}
