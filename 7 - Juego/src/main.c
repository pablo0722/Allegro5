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

    al_ext_init_window(0.5, 0.5);  // Inicializa allegro, instala teclado, mouse, timer y crea una ventana

    my_app_init(&mis_datos);  // Inicializa juego

    al_ext_loop_set_start_callback(my_app_start);
    al_ext_loop_set_logic_callback(my_app_logic);
    al_ext_loop_set_draw_callback(my_app_draw);
    
    al_ext_loop(&mis_datos);
    
    my_app_exit(&mis_datos);  // Se debe borrar imagenes y liberar memoria antes de cerrar allegro.

    return 0;
}

