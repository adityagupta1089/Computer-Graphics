SOURCES := $(wildcard *.c)
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

all: $(OBJECTS)

clean:
	rm -rf *.o
	
%.o: %.c
	gcc $< -lm -lGL -lGLU -lglut -o $@
