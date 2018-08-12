/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include "my_struct.h"










/**********************************************************************
 * 							FUNCIONES PUBLICAS
 **********************************************************************/
void init_my_struct(my_app_t *app_struct)
{
    unsigned int i;

	assert(app_struct);

    for(i=0; i<MAX_FUENTES; i++)
    {
        app_struct->fonts[i] = NULL;
    }

    for(i=0; i<MAX_IMAGENES; i++)
    {
        app_struct->images[i] = NULL;
    }
}










void delete_my_struct(my_app_t *app_struct)
{
    unsigned int i;

	assert(app_struct);

    for(i=0; i<MAX_FUENTES; i++)
    {
        if(app_struct->fonts[i])
        {     
            al_destroy_font(app_struct->fonts[i]);
        }
    }

    for(i=0; i<MAX_IMAGENES; i++)
    {
        if(app_struct->images[i])
        {
            al_destroy_bitmap(app_struct->images[i]);
        }
    }
}
