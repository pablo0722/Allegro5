#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_


/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include "allegro_extention/al_ext.h"










/**********************************************************************
 * 							DEFINES
 **********************************************************************/
#define NUM_FIRES   8   // Cantidad de "fueguitos" simultaneos
#define FIRE_MS     100 // Tiempo entre cambio de imagenes del fuego










/**********************************************************************
 * 							ENUMS
 **********************************************************************/
enum MY_APP_FONTS
{
    FONT_START,
    MAX_FONTS
};

enum MY_APP_IMAGES
{
    IMG_BACKGROUND,
    IMG_SONIC,
    IMG_FIRE,
    MAX_IMAGES
};

enum MY_APP_SUBIMAGES_SONIC
{
    IMG_SONIC_LEFT,
    IMG_SONIC_RIGTH,
    IMG_SONIC_IDLE,
    IMG_SONIC_MAX
};

enum MY_APP_SUBIMAGES_FIRE
{
    IMG_FIRE_0,
    IMG_FIRE_1,
    IMG_FIRE_2,
    IMG_FIRE_3,
    IMG_FIRE_MAX
};

enum MY_APP_SOUNDS
{
    SND_MUSIC,
    MAX_SOUNDS
};

enum MY_APP_MENU
{
    MENU_MAIN_MENU,
    MENU_GAME_START,
    MENU_GAME_OVER,
    MENU_EXIT,
    MENU_MAX
};










/**********************************************************************
 * 							ESTRUCTURAS
 **********************************************************************/
typedef struct my_app
{
    ALLEGRO_FONT *   fonts[MAX_FONTS];
    ALLEGRO_BITMAP * images[MAX_IMAGES];
    ALLEGRO_SAMPLE * sounds[MAX_SOUNDS];
	
    float time;

    unsigned char menu;

    float pos_x;
    float pos_y;

    float fire_x[NUM_FIRES];
    float fire_y[NUM_FIRES];
    unsigned char fire_img;   // Define la imagen actual del fuego
} my_app_t;










/**********************************************************************
 * 							PROTOTIPOS PUBLICOS
 **********************************************************************/
void my_struct_init(my_app_t *app_struct);
void my_struct_delete(my_app_t *app_struct);










#endif // MY_STRUCT_H_
