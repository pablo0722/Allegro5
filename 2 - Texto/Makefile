CC= gcc
LIBS= -l allegro -lallegro_image -l allegro_primitives -l allegro_ttf -l allegro_dialog -l allegro_font -l allegro_audio -l allegro_acodec
CFLAGS=-Wall -g
INCLUDES=-I./inc
SOURCES=./src/*.c
EXE=exe

compilar:
	$(CC) $(SOURCES) $(INCLUDES) -o $(EXE) $(CFLAGS) $(LIBS)

ejecutar:
	./$(EXE)

limpiar:
	rm ./$(EXE)
