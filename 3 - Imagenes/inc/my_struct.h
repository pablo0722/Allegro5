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










/**********************************************************************
 * 							ENUMS
 **********************************************************************/
enum
{
    IMG_FONDO,  // vale 0 (cero)
    IMG_OSO     // vale 1 (uno)
};










/**********************************************************************
 * 							ESTRUCTURAS
 **********************************************************************/
typedef struct my_app
{
    ALLEGRO_FONT *fonts[MAX_FUENTES];
    ALLEGRO_BITMAP *images[MAX_IMAGENES];   // bitmaps de las imagenes
} my_app_t;










/**********************************************************************
 * 							PROTOTIPOS PUBLICOS
 **********************************************************************/
void init_my_struct(my_app_t *app_struct);
void delete_my_struct(my_app_t *app_struct);










#endif // MY_STRUCT_H_
