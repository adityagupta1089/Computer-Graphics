all:
	gcc Turtle.c -lm -lGLU -lglut -lGL -c -o Turtle.o
	gcc Drawings.c -lm -lGLU -lglut -lGL -c -o Drawings.o
	gcc TurtleGraphics.c Drawings.o Turtle.o -lm -lGLU -lglut -lGL -o turtle
clean:
	rm -rf *.o
