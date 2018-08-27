SOURCES = $(wildcard ./src/allegro_extention/*.c)
OBJS = $(subst /src/,/obj/,$(SOURCES:.c=.o))

./lib/allegro_extention/libal_ext.a: $(OBJS)
	ar rcs $@ $^

./obj/allegro_extention/%.o: ./src/allegro_extention/%.c
	gcc -c $< -o $@ -I./inc/

clean:
	rm -f *.o *.a