/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include "allegro_extention/al_ext.h"

#include "my_aplication.h"
#include "my_struct.h"










/**********************************************************************
 * 							MAIN
 **********************************************************************/
int main(void)
{
    my_app_t mis_datos;

    init_my_struct(&mis_datos);

    al_ext_init_window(0.5, 0.5);  // Inicializa allegro, instala teclado, mouse, timer y crea una ventana

    init_aplication(&mis_datos);  // Inicializa juego

    ALLEGRO_KEYBOARD_STATE keystate;
    do                    // Dibuja hasta que se presiona escape
    {
        do_aplication(&mis_datos);              // Dibuja y analiza otras teclas

        al_get_keyboard_state(&keystate);
    } while(!(al_key_down(&keystate, ALLEGRO_KEY_ESCAPE)));

    my_allegro_exit(&mis_datos);  // Se debe borrar imagenes y liberar memoria antes de cerrar allegro.


    return 0;
}

