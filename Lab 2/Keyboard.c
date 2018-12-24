#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void renderSquare(void) {
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.0f);
    glBegin(GL_QUADS);
    glVertex3f(-0.5, -0.5f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 0.0f);
    glVertex3f(0.5f, 0.5f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glEnd();
    glFlush();
}

void renderTriangle(void) {
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.0f);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, -0.5f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glEnd();
    glFlush();
}

void renderPentagon(void) {
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();    
	glTranslatef(0.0f, 0.0f, -2.0f);
   	glBegin(GL_POLYGON);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glEnd();
    glFlush();
}

void display(void) {
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.0f);
    glFlush();
}

void reshape (int width, int height) {  
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();  
	gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0);   
	glMatrixMode(GL_MODELVIEW); 
}  

void keyPressed(unsigned char key, int x, int y) {
	if (key == 's') {
		renderSquare();	
	} else if (key == 't') {
		renderTriangle();
	} else if (key == 'p') {
		renderPentagon();
	}
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello World");
	glutReshapeFunc(reshape);
    glutDisplayFunc(display);
	glutKeyboardFunc(keyPressed);
    glutMainLoop();
}
