#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_


/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include "allegro_extention/al_ext.h"










/**********************************************************************
 * 							DEFINES
 **********************************************************************/
#define MAX_FUENTES     8
#define MAX_IMAGENES    32
#define MAX_SOUNDS      8










/**********************************************************************
 * 							ENUMS
 **********************************************************************/
enum MY_APP_IMAGES
{
    IMG_BACKGROUND, // vale 0 (cero)
    IMG_BEAR        // vale 1 (uno)
};

enum MY_APP_SOUNDS
{
    SND_BACKGROUND  // vale 0 (cero)
};

enum MY_APP_MODE
{
    KEYBOARD,       // vale 0 (cero)
    MOUSE           // vale 1 (uno)
};










/**********************************************************************
 * 							ESTRUCTURAS
 **********************************************************************/
typedef struct my_app
{
    ALLEGRO_FONT *   fonts[MAX_FUENTES];   // Fuentes de texto
    ALLEGRO_BITMAP * images[MAX_IMAGENES]; // Imagenes
    ALLEGRO_SAMPLE * sounds[MAX_SOUNDS];   // Sonidos

    int mode;   // Modo: teclado / mouse

    int pos_x;
    int pos_y;
} my_app_t;










/**********************************************************************
 * 							PROTOTIPOS PUBLICOS
 **********************************************************************/
void my_struct_init(my_app_t *app_struct);
void my_struct_delete(my_app_t *app_struct);










#endif // MY_STRUCT_H_
