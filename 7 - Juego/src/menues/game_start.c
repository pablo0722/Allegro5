/****************************************************************************/
/* 							INLCUDES                                        */
/****************************************************************************/
#include <allegro5/allegro.h>

#include "my_struct.h"










/****************************************************************************/
/*							FORWARD PRIVADAS                                */
/****************************************************************************/
void movimiento_sonic   (int window_width, int window_height, my_app_t *app_struct);
void generate_fire      (int window_width, int window_height, my_app_t *app_struct);
void change_fire_img    (int window_width, int window_height, my_app_t *app_struct);
bool colision2D         (float x1, float y1, float w1, float h1, 
                         float x2, float y2, float w2, float h2);
bool colision_all       (int window_width, int window_height, my_app_t *app_struct);

void draw_sonic         (unsigned char sector, my_app_t *app_struct);
void draw_fuegos        (my_app_t *app_struct);










/****************************************************************************/
/*							LOGICA GAME START                               */
/****************************************************************************/
bool logic_game_start(int window_width, int window_height, my_app_t *app_struct)
{
    unsigned char *menu;

	assert(app_struct);

    menu = &(app_struct->menu);

	assert(menu);

    if(al_ext_key(ALLEGRO_KEY_ESCAPE))
    {
        (*menu) = MENU_EXIT;
        return false;
    }

    movimiento_sonic(window_width, window_height, app_struct);

    generate_fire(window_width, window_height, app_struct);
    change_fire_img(window_width, window_height, app_struct);

    if(colision_all(window_width, window_height, app_struct))
    {
        (*menu) = MENU_GAME_OVER;
    }
    
    return true;
}











/****************************************************************************/
/*							DRAW GAME START                                 */
/****************************************************************************/
bool draw_game_start( int window_width, int window_height, my_app_t *app_struct)
{
	assert(app_struct);

    ALLEGRO_BITMAP *background = app_struct->images[IMG_BACKGROUND];

	assert(background);

    al_draw_bitmap(background, 0, 0, 0);

    if(al_ext_key(ALLEGRO_KEY_LEFT))
    {
        draw_sonic(IMG_SONIC_LEFT, app_struct);
    }

    else if(al_ext_key(ALLEGRO_KEY_RIGHT))
    {
        draw_sonic(IMG_SONIC_RIGTH, app_struct);
    }

    else if(al_ext_key(ALLEGRO_KEY_UP))
    {
        draw_sonic(IMG_SONIC_RIGTH, app_struct);
    }

    else if(al_ext_key(ALLEGRO_KEY_DOWN))
    {
        draw_sonic(IMG_SONIC_LEFT, app_struct);
    }

    else
    {
        draw_sonic(IMG_SONIC_IDLE, app_struct);
    }

    draw_fuegos(app_struct);

    return true;
}










/****************************************************************************/
/*							FUNCIONES AUXILIARES DE LOGICA                  */
/****************************************************************************/
void movimiento_sonic(int window_width, int window_height, my_app_t *app_struct)
{
    float desplazamiento = 5;

	assert(app_struct);


    ALLEGRO_BITMAP *sonic = app_struct->images[IMG_SONIC];
    float *pos_x = &(app_struct->pos_x);
    float *pos_y = &(app_struct->pos_y);

	assert(sonic);
	assert(pos_x);
	assert(pos_y);


	// Movimiento
    if(al_ext_key(ALLEGRO_KEY_LEFT))
    {
        (*pos_x) -= desplazamiento;
    }

    if(al_ext_key(ALLEGRO_KEY_RIGHT))
    {
        (*pos_x) += desplazamiento;
    }

    if(al_ext_key(ALLEGRO_KEY_UP))
    {
        (*pos_y) -= desplazamiento;
    }

    if(al_ext_key(ALLEGRO_KEY_DOWN))
    {
        (*pos_y) += desplazamiento;
    }


    int sonic_w = al_get_bitmap_width(sonic)/IMG_SONIC_MAX;
    int sonic_h = al_get_bitmap_height(sonic);


	// Limites
    if( (*pos_x) > window_width - sonic_w/2)
        (*pos_x) = window_width - sonic_w/2;

    if( (*pos_x) < sonic_w/2)
        (*pos_x) = sonic_w/2;

    if( (*pos_y) > window_height - sonic_h/2)
        (*pos_y) = window_height - sonic_h/2;

    if( (*pos_y) < sonic_h/2)
        (*pos_y) = sonic_h/2;
}










void generate_fire(int window_width, int window_height, my_app_t *app_struct)
{
    float desplazamiento = 2;


	assert(app_struct);


    ALLEGRO_BITMAP *fire = app_struct->images[IMG_FIRE];

	assert(fire);


    float *fire_x;
    float *fire_y;
    int i;


    int fire_w = al_get_bitmap_width(fire)/IMG_FIRE_MAX;
    int fire_h = al_get_bitmap_height(fire);


    for(i=0; i<NUM_FIRES; i++)
    {
        fire_x = &(app_struct->fire_x[i]);
        fire_y = &(app_struct->fire_y[i]);

		assert(fire_x);
		assert(fire_y);

        (*fire_y) += desplazamiento;

        if( (*fire_y) > window_height )
        {
            (*fire_y) = - fire_h;
            (*fire_x) = rand()%(window_width - fire_w);
        }
    }
}










void change_fire_img(int window_width, int window_height, my_app_t *app_struct)
{
    float *time;
    unsigned char *fire_img;

	assert(app_struct);

	fire_img = &(app_struct->fire_img);
	time = &(app_struct->time);

	assert(fire_img);
	assert(time);

    (*fire_img) = (((int)(*time)/FIRE_MS)) % IMG_FIRE_MAX;	//Cambia de imagen del fuego 1 vez de cada FIRE_MS milisegundos
}










bool colision2D(float x1, float y1, float w1, float h1, 
                float x2, float y2, float w2, float h2)
{
    bool ret_value = false;

    if( (x1 > x2) && (x1 < x2 + w2) )
    {
        if( (y1 > y2) && (y1 < y2 + h2) )
        {
            ret_value = true;
        }

        else if( (y1 + h1 > y2) && (y1 + h1 < y2 + h2) )
        {
            ret_value = true;
        }
    }

    if( (x1 + w1 > x2) && (x1 + w1 < x2 + w2) )
    {
        if( (y1 > y2) && (y1 < y2 + h2) )
        {
            ret_value = true;
        }

        else if( (y1 + h1 > y2) && (y1 + h1 < y2 + h2) )
        {
            ret_value = true;
        }
    }

    return ret_value;
}










bool colision_all(int window_width, int window_height, my_app_t *app_struct)
{
    bool ret_value = false;

    float pos_x;
    float pos_y;
    int fire_x;
    int fire_y;
    int i;

	assert(app_struct);

    pos_x = app_struct->pos_x;
    pos_y = app_struct->pos_y;


    ALLEGRO_BITMAP *sonic = app_struct->images[IMG_SONIC];
    ALLEGRO_BITMAP *fire = app_struct->images[IMG_FIRE];

	assert(sonic);
	assert(fire);


    int sonic_w = al_get_bitmap_width(sonic)/IMG_SONIC_MAX;
    int sonic_h = al_get_bitmap_height(sonic);


    int fire_w = al_get_bitmap_width(fire)/IMG_FIRE_MAX;
    int fire_h = al_get_bitmap_height(fire);


    for(i=0; i<NUM_FIRES; i++)
    {
        fire_x = app_struct->fire_x[i];
        fire_y = app_struct->fire_y[i];

        if( colision2D(   pos_x - sonic_w/2, pos_y - sonic_h/2, sonic_w, sonic_h,
                        fire_x - fire_w/2, fire_y - fire_h/2, fire_w,  fire_h) )
        {
            ret_value = true;
        }
    }


    return ret_value;
}










/****************************************************************************/
/*							FUNCIONES AUXILIARES DE DRAW                    */
/****************************************************************************/
void draw_sonic(unsigned char sector, my_app_t *app_struct)
{
	assert(app_struct);

    ALLEGRO_BITMAP *sonic = app_struct->images[IMG_SONIC];

	assert(sonic);

    float pos_x = app_struct->pos_x;
    float pos_y = app_struct->pos_y;

    int sonic_w = al_get_bitmap_width(sonic)/3;
    int sonic_h = al_get_bitmap_height(sonic);

    switch(sector)
    {
        case IMG_SONIC_IDLE:
                al_draw_bitmap_region(  sonic, 0, 0, sonic_w, sonic_h, 
                                        pos_x - sonic_w/2, pos_y - sonic_h/2, 0);
            break;

        case IMG_SONIC_LEFT:
                al_draw_bitmap_region(  sonic, sonic_w, 0, sonic_w, sonic_h, 
                                        pos_x - sonic_w/2, pos_y - sonic_h/2, 0);
            break;

        case IMG_SONIC_RIGTH:
                al_draw_bitmap_region(  sonic, sonic_w*2, 0, sonic_w, sonic_h, 
                                        pos_x - sonic_w/2, pos_y - sonic_h/2, 0);
            break;
    }
}










void draw_fuegos(my_app_t *app_struct)
{
	assert(app_struct);


    ALLEGRO_BITMAP *fire = app_struct->images[IMG_FIRE];

    assert(fire);


    unsigned char fire_img;
    int fire_x;
    int fire_y;
    int i;

    
    fire_img = app_struct->fire_img;

    int fire_w = al_get_bitmap_width(fire)/4;
    int fire_h = al_get_bitmap_height(fire);


    for(i=0; i<NUM_FIRES; i++)
    {
        fire_x = app_struct->fire_x[i];
        fire_y = app_struct->fire_y[i];

        switch(fire_img)
        {
            case IMG_FIRE_0:
                    al_draw_bitmap_region(  fire, 0, 0, fire_w, fire_h, 
                                            fire_x - fire_w/2, fire_y - fire_h/2, 0);
                break;
            case IMG_FIRE_1:
                    al_draw_bitmap_region(  fire, fire_w, 0, fire_w, fire_h, 
                                            fire_x - fire_w/2, fire_y - fire_h/2, 0);
                break;
            case IMG_FIRE_2:
                    al_draw_bitmap_region(  fire, fire_w*2, 0, fire_w, fire_h, 
                                            fire_x - fire_w/2, fire_y - fire_h/2, 0);
                break;
            case IMG_FIRE_3:
                    al_draw_bitmap_region(  fire, fire_w*3, 0, fire_w, fire_h, 
                                            fire_x - fire_w/2, fire_y - fire_h/2, 0);
                break;
        }
    }
}