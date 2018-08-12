#include "my_allegro.h"
#include "my_aplication.h"


int main()
{
    int return_value = 0;
    t_my_app my_data;


    if(al_init_window(0.5, 0.5) == AL_OK)       // Inicializa allegro, instala teclado, mouse, timer y crea una ventana
    {
        my_app_init(&my_data);

        my_aplicacion(&my_data);      // Muestra algunos textos en pantalla

        al_rest(5);                     // Espera 5 segundos

        my_allegro_exit(&my_data);    // Se debe borrar imagenes y liberar memoria antes de cerrar allegro.

        return_value = 0;
    }
    else
    {
        return_value = -1;
    }

    return return_value;
}

