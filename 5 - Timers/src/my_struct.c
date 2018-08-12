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

    for(i=0; i<MAX_FUENTES; i++)
    {
        app_struct->fonts[i] = NULL;
    }

    for(i=0; i<MAX_IMAGENES; i++)
    {
        app_struct->images[i] = NULL;
    }
    
    app_struct->mode = KEYBOARD;

    app_struct->pos_x = 0;
    app_struct->pos_y = 0;
}










void my_struct_delete(my_app_t *app_struct)
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