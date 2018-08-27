/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include "my_struct.h"










/**********************************************************************
 * 							FUNCIONES PUBLICAS
 **********************************************************************/
void my_struct_init(my_app_t *app_struct)
{
    unsigned int i;

	assert(app_struct);

    for(i=0; i<MAX_FONTS; i++)
    {
        app_struct->fonts[i] = NULL;
    }

    for(i=0; i<MAX_IMAGES; i++)
    {
        app_struct->images[i] = NULL;
    }

    for(i=0; i<MAX_SOUNDS; i++)
    {
        app_struct->sounds[i] = NULL;
    }

    app_struct->time = 0;
}










void my_struct_delete(my_app_t *app_struct)
{
    unsigned int i;

	assert(app_struct);

    for(i=0; i<MAX_FONTS; i++)
    {
        if(app_struct->fonts[i])
        {     
            al_destroy_font(app_struct->fonts[i]);
        }
    }

    for(i=0; i<MAX_IMAGES; i++)
    {
        if(app_struct->images[i])
        {
            al_destroy_bitmap(app_struct->images[i]);
        }
    }

    for(i=0; i<MAX_SOUNDS; i++)
    {
        if(app_struct->sounds[i])
        {
            al_destroy_sample(app_struct->sounds[i]);
        }
    }
}
