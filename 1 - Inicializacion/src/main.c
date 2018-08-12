#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>              // printf(), sprintf()


int main()
{
    int color_depth = 32;
    char titulo[64];

	// inicializa allegro. (Devuelve VERDADERO en caso de exito)
	// Se debe llamar al comienzo del programa
    if(!al_init())
	{
	    al_init_native_dialog_addon(); 	// Inicializa rutinas de message_box
	    al_show_native_message_box( NULL, 
	    							"[ERROR]", "En funcion al_init()", 
	    							"No pudo inicializar allegro. Esta bien instalado?\n", 
	    							NULL, ALLEGRO_MESSAGEBOX_ERROR);
	    
		exit(-1);
	}

    al_install_keyboard();     // inicializa rutinas de teclado
    al_install_mouse();        // inicializa rutinas de mouse


    sprintf(titulo, "Titulo de ventana allegro :D - depth: %d", color_depth);

    ALLEGRO_DISPLAY * window_handler = al_create_display(800, 600); // Crea la ventana

    al_set_window_title(window_handler, titulo);            // Setea un titulo a la ventana

    al_rest(5); // Espera 5 segundos

    al_uninstall_system(); /* Desinstala rutinas como mouse, teclado y timer, y cierra Allegro.
                     * No es necesario hacer una llamada explicita a esta funcion porque
                     * allegro_init() la llama en su rutina de salida, por lo que ser�
                     * llamada automaticamente al terminar el programa.
                     * Tener en cuenta que luego de llamar a esta funcion, otras funciones
                     * como destroy_bitmap() podran producir errores en tiempo de ejecucion.
                     */

    return 0;
}