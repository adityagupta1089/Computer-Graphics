#include <GL/gl.h>
#include <GL/glut.h>

void display () {
	/* clear window */
	glClear(GL_COLOR_BUFFER_BIT);
	/* draw scene */
	glutWireTeapot(0.25);
	/* flush drawing routines to the window */
	glFlush();
}

int main ( int argc, char * argv[] ) {
	/* initialize GLUT, using any commandline parameters passed to the program */
	glutInit(&argc,argv);
	/* setup the size, position, and display mode for new windows */
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,50);
	glutInitDisplayMode(GLUT_RGB);
	/* create and set up a window */
	glutCreateWindow("hello, teapot!");
	glutDisplayFunc(display);
	/* tell GLUT to wait for events */
	glutMainLoop();
}
