#include "my_aplication.h"

#include "my_allegro_priv.h"



void my_app_init(t_my_app *app_struct)
{
    assert(app_struct);    // Comprobar valor de los punteros !!!

    init_my_struct(app_struct);

    const char * font_filename = al_browse_file(    "/usr/share/fonts/truetype/",
                                                    "Elegir FONT",
                                                    "*.ttf;*.*");
    int font_size = 16;
    app_struct->fonts[0] = al_load_font(font_filename, font_size, 0);
}

void my_aplicacion(t_my_app *app_struct)
{
    assert(app_struct);

    ALLEGRO_FONT *my_font = app_struct->fonts[0];

    assert(my_font);

    al_draw_line(   300, 0, 300, 300,
                    al_map_rgb(64, 64, 64), 1);

    al_draw_line(   500, 0, 500, 300,
                    al_map_rgb(64, 64, 64), 1);

    al_draw_text(   my_font, al_map_rgb(255,0,0), 
                    300, 0, ALLEGRO_ALIGN_LEFT,
                    "Texto alineado a izquierda");

    al_draw_textf(   my_font, al_map_rgb(0,255,0), 
                    300, 20, ALLEGRO_ALIGN_CENTER,
                    "Texto alineado a centro");

    al_draw_text(   my_font, al_map_rgb(0,0,255), 
                    300, 40, ALLEGRO_ALIGN_RIGHT,
                    "Texto alineado a derecha");

    char *lines[] = {"Dibuja un texto",
                       "justificado dentro",
                       "del area especificado",
                       "entre x1 y x2"};
    int i;
    int y;
    for(i=0, y = 0; i<4; i++, y+=al_get_font_line_height(my_font))
    {
        al_draw_justified_text(   my_font, al_map_rgb(0,255,255), 
                        300, 500,
                        120+y, 200, 0,
                        lines[i]);
    }

    al_flip_display();
}


void my_allegro_exit(t_my_app *app_struct)
{
    // Se debe borrar imagenes y liberar memoria antes de cerrar allegro.

    assert(app_struct);

    delete_my_struct(app_struct);
}
