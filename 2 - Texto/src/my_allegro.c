
/**********************************************************************
 * 							INLCUDES
 **********************************************************************/
#include "my_allegro.h"

#include "my_allegro_priv.h"










/**********************************************************************
 * 							FORWARDS PRIVADAS
 **********************************************************************/
static void print_pixel_format( ALLEGRO_TEXTLOG * log, int format);










/**********************************************************************
 * 							FUNCIONES PUBLICAS
 **********************************************************************/
int al_init_window(float width_relative, float height_relative)
{
    char return_value = AL_OK;

    if(!al_init())
    {
        // No pudo inicializar allegro

		al_init_native_dialog_addon();
	    al_show_native_message_box( NULL, 
	    							"[ERROR]", "En funcion al_init()", 
	    							"No pudo inicializar allegro. Esta bien instalado?\n", 
	    							NULL, ALLEGRO_MESSAGEBOX_ERROR);
            // Muestra cuadro de error

		return_value = AL_ERROR_ALLEGRO_INIT;
    }
	else
	{
		al_install_keyboard();     	// Inicializa rutinas de teclado
		al_install_mouse();         // Inicializa rutinas de mouse
		al_init_font_addon();		// Inicializa ruitinas de fuentes (texto)
		al_init_ttf_addon();		// Permite cargar fuentes en formato ".ttf"
		al_init_primitives_addon(); // Inicializa rutinas de dibujado de primitivas
		
		int nva = al_get_num_video_adapters();

		if(nva < 1)
		{
			return_value = AL_ERROR_VIDEO_ADAPTER;
		}
		else
		{
			ALLEGRO_MONITOR_INFO monitor_info;
			al_get_monitor_info(0, &monitor_info);
			int desktop_width = (monitor_info.x2 - monitor_info.x1) * width_relative;
			int desktop_height = (monitor_info.y2 - monitor_info.y1) * height_relative;

			al_set_new_display_flags(ALLEGRO_WINDOWED);
			_my_app_priv.window_handler = al_create_display(desktop_width, desktop_height); // Crea la ventana

			if(!_my_app_priv.window_handler)
			{
				return_value = AL_ERROR_WINDOW;
			}
			else
			{
    			al_clear_to_color(al_map_rgb(0, 0, 0));	// Pinta todo el bitmap de un color
			}
		}	
	}

    return return_value;
}










int al_init_fullscreen(int width, int height)
{
    char return_value = AL_OK;

    if(!al_init())
    {
        // No pudo inicializar allegro

		al_init_native_dialog_addon();
	    al_show_native_message_box( NULL, 
	    							"[ERROR]", "En funcion al_init()", 
	    							"No pudo inicializar allegro. Esta bien instalado?\n", 
	    							NULL, ALLEGRO_MESSAGEBOX_ERROR);
            // Muestra cuadro de error

		return_value = AL_ERROR_ALLEGRO_INIT;
    }
	else
	{
		al_install_keyboard();     	// Inicializa rutinas de teclado
		al_install_mouse();         // Inicializa rutinas de mouse
		al_init_font_addon();		// Inicializa ruitinas de fuentes (texto)
		al_init_ttf_addon();		// Permite cargar fuentes en formato ".ttf"
		al_init_primitives_addon(); // Inicializa rutinas de dibujado de primitivas
		
		int nva = al_get_num_video_adapters();

		if(nva < 1)
		{
			return_value = AL_ERROR_VIDEO_ADAPTER;
		}
		else
		{
			al_set_new_display_flags(ALLEGRO_FULLSCREEN);
			_my_app_priv.window_handler = al_create_display(width, height); // Crea la ventana

			if(!_my_app_priv.window_handler)
			{
				return_value = AL_ERROR_WINDOW;
			}
			else
			{
    			al_clear_to_color(al_map_rgb(0, 0, 0));	// Pinta todo el bitmap de un color
			}
		}	
	}

    return return_value;
}










int al_init_fullscreen_desktop()
{
    char return_value = AL_OK;

    if(!al_init())
    {
        // No pudo inicializar allegro

		al_init_native_dialog_addon();
	    al_show_native_message_box( NULL, 
	    							"[ERROR]", "En funcion al_init()", 
	    							"No pudo inicializar allegro. Esta bien instalado?\n", 
	    							NULL, ALLEGRO_MESSAGEBOX_ERROR);
            // Muestra cuadro de error

		return_value = AL_ERROR_ALLEGRO_INIT;
    }
	else
	{
		al_install_keyboard();     	// Inicializa rutinas de teclado
		al_install_mouse();         // Inicializa rutinas de mouse
		al_init_font_addon();		// Inicializa ruitinas de fuentes (texto)
		al_init_ttf_addon();		// Permite cargar fuentes en formato ".ttf"
		al_init_primitives_addon(); // Inicializa rutinas de dibujado de primitivas
		
		int nva = al_get_num_video_adapters();

		if(nva < 1)
		{
			return_value = AL_ERROR_VIDEO_ADAPTER;
		}
		else
		{
			al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
			_my_app_priv.window_handler = al_create_display(1, 1); // Crea la ventana

			if(!_my_app_priv.window_handler)
			{
				return_value = AL_ERROR_WINDOW;
			}
			else
			{
    			al_clear_to_color(al_map_rgb(0, 0, 0));	// Pinta todo el bitmap de un color
			}
		}
	}

    return return_value;
}










int al_init_log()
{
    char return_value = AL_OK;

    if(!al_init())
    {
        // No pudo inicializar allegro

		al_init_native_dialog_addon();
	    al_show_native_message_box( NULL, 
	    							"[ERROR]", "En funcion al_init()", 
	    							"No pudo inicializar allegro. Esta bien instalado?\n", 
	    							NULL, ALLEGRO_MESSAGEBOX_ERROR);
            // Muestra cuadro de error

		return_value = AL_ERROR_ALLEGRO_INIT;
    }
	else
	{
		int nva = al_get_num_video_adapters();
		if(nva < 1)
		{
			return_value = AL_ERROR_VIDEO_ADAPTER;
		}
		else
		{
			int mode_flags[3] =
			{
				ALLEGRO_FULLSCREEN | ALLEGRO_DIRECT3D_INTERNAL,
				ALLEGRO_FULLSCREEN | ALLEGRO_OPENGL,
				ALLEGRO_FULLSCREEN | ALLEGRO_OPENGL_3_0,
			};

			const char * mode_driver_text[3] =
			{
				"ALLEGRO_DIRECT3D",
				"ALLEGRO_OPENGL",
				"ALLEGRO_OPENGL_3_0"
			};

			ALLEGRO_TEXTLOG * log = al_open_native_text_log("info", 0);

			int i, j;
			for( i = 0; i < 3; i++)
			{
				al_set_new_display_flags(mode_flags[i]);

				int num_modes = al_get_num_display_modes();
				
				al_append_native_text_log(log, "%d modos disponibles para %s:\n", num_modes, mode_driver_text[i]);

				for( j = 0; j < num_modes; j++)
				{
					ALLEGRO_DISPLAY_MODE mode;

					if( al_get_display_mode(j, &mode) == &mode)
					{
						al_append_native_text_log(log, "Modo %d: \n", j+1);
						al_append_native_text_log(log, "\t %dx%d @ %d Hz. Pixel format: ",
													mode.width, mode.height, mode.refresh_rate);
						print_pixel_format(log, mode.format);
						al_append_native_text_log(log, "\n");
					}
				}

				al_append_native_text_log(log, "\n");
			}
		}	
	}

    return return_value;
}









const char * al_browse_file(char const * initial_path, char const * title, char const * patterns)
{
	const char * filename = NULL;

    ALLEGRO_FILECHOOSER *window_browser = al_create_native_file_dialog(  initial_path,
                                                        title,
                                                        patterns,
                                                        ALLEGRO_FILECHOOSER_FILE_MUST_EXIST);

    do
    {
        al_show_native_file_dialog(_my_app_priv.window_handler, window_browser);
        filename = al_get_native_file_dialog_path( window_browser, 0);
    } while(!filename);

	return filename;
}










/**********************************************************************
 * 							FUNCIONES PRIVADAS
 **********************************************************************/
static void print_pixel_format( ALLEGRO_TEXTLOG * log, int format)
{
	switch(format)
	{
		case ALLEGRO_PIXEL_FORMAT_ANY:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_ANY");

			break;
		}
		
		case ALLEGRO_PIXEL_FORMAT_ANY_NO_ALPHA:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_ANY_NO_ALPHA");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_ANY_WITH_ALPHA:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_ANY_WITH_ALPHA");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_ANY_15_NO_ALPHA:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_ANY_15_NO_ALPHA");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_ANY_16_NO_ALPHA:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_ANY_16_NO_ALPHA");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_ANY_16_WITH_ALPHA:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_ANY_16_WITH_ALPHA");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_ANY_24_NO_ALPHA:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_ANY_24_NO_ALPHA");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_ANY_32_NO_ALPHA:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_ANY_32_NO_ALPHA");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_ANY_32_WITH_ALPHA:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_ANY_32_WITH_ALPHA");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_ARGB_8888:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_ARGB_8888");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_RGBA_8888:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_RGBA_8888");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_ARGB_4444:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_ARGB_4444");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_RGB_888:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_RGB_888");

			break;
		}

		// 24 bit format
		case ALLEGRO_PIXEL_FORMAT_RGB_565:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_RGB_565");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_RGB_555:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_RGB_555");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_RGBA_5551:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_RGBA_5551");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_ARGB_1555:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_ARGB_1555");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_ABGR_8888:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_ABGR_8888");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_XBGR_8888:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_XBGR_8888");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_BGR_888:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_BGR_888");

			break;
		}

		// 24 bit format
		case ALLEGRO_PIXEL_FORMAT_BGR_565:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_BGR_565");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_BGR_555:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_BGR_555");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_RGBX_8888:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_RGBX_8888");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_XRGB_8888:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_XRGB_8888");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_ABGR_F32:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_ABGR_F32");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_ABGR_8888_LE:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_ABGR_8888_LE");

			break;
		}

		case ALLEGRO_PIXEL_FORMAT_RGBA_4444:
		{
			al_append_native_text_log(log, "ALLEGRO_PIXEL_FORMAT_RGBA_4444");

			break;
		}

		case ALLEGRO_NUM_PIXEL_FORMATS:
		{
			al_append_native_text_log(log, "ALLEGRO_NUM_PIXEL_FORMATS");

			break;
		}

		default:
		{
			al_append_native_text_log(log, "Formato desconocido");

			break;
		}
	}
}