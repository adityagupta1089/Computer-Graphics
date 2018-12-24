#include <stdio.h>
#include <GL/glut.h>

#include "Turtle.h"
#include "Drawings.h"


#define SIZE 500  /* the size, in pixels, of the square window to open, YOU CAN CHANGE THIS */

int Example_Number = 2;


//GLUT display callback
void display( void )
{
	// Clear Screen
	// If Example == 1, Draw Square
	// If Example == 2, Draw Original Drawing 1
	// If Example == 3, Draw Original Drawing 2
	// If Example == 4, Draw Instructor's example
	switch (Example_Number) {
		case 1: Square(); break;
		case 2: Original1(); break;
		case 3: Original2(); break;
		case 4: Example(); break;
	}

}


//GLUT callback to handle keyboard events
void keyboard( unsigned char key, int x, int y ) 
{
   // Everytime a key is pressed increase Example
   Example_Number++;
   if(Example_Number > 4 ){
   		Example_Number = 1;
   }    
   display();
}


void main (int argc, char **argv)
{
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE );
  glutInitWindowSize (SIZE, SIZE);
  glutInitWindowPosition (50, 100);
  glutCreateWindow ("Turtle Graphics");

  //Register the GLUT callbacks
  glutDisplayFunc( display );
  glutKeyboardFunc( keyboard );
 
  glutMainLoop();
}
