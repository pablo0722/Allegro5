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

    do_aplication(&mis_datos);

    al_rest(5);

    my_allegro_exit(&mis_datos);  // Se debe borrar imagenes y liberar memoria antes de cerrar allegro.

    return 0;
}

