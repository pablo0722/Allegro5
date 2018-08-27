CC= gcc
LIBS= -L./lib/allegro_extention/ -lal_ext -lallegro -lallegro_image -lallegro_primitives -lallegro_ttf -lallegro_dialog -lallegro_font -lallegro_audio -lallegro_acodec 
CFLAGS=-Wall -g
INCLUDES=-I./inc
SOURCES=./src/*.c ./src/menues/*.c
EXE=exe

compilar:
	$(CC) $(SOURCES) $(INCLUDES) -o $(EXE) $(CFLAGS) $(LIBS)

ejecutar:
	./$(EXE)

limpiar:
	rm ./$(EXE)
