#include "my_struct.h"

#include "my_allegro_priv.h"


void init_my_struct(t_my_app *app_struct)
{
    unsigned int i;

	assert(app_struct);

    for(i=0; i<MAX_FONTS; i++)
    {
        app_struct->fonts[i] = NULL;
    }
}

void delete_my_struct(t_my_app *app_struct)
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
}
