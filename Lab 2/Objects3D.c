#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void renderObject(int id) {
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -5.0f);
	switch(id){
		case 1: glutWireCube(2.0f); break;
		case 2: glutSolidCube(2.0f); break;
		case 3: glutWireCone(2.0f, 1.0f, 20, 20); break;
		case 4: glutSolidCone(2.0f, 2.0f, 20, 20); break;
		case 5: glutWireTorus(0.5f, 2.0f, 20, 20); break;
		case 6: glutSolidTorus(0.5f, 2.0f, 20, 20); break;
		case 7: glutWireTeapot(1.5f); break;
		case 8: glutSolidTeapot(1.5f); break;
	}    
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
	if (key >= '1' && key <= '8') {
		renderObject(key - '0');	
	} 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Press key from 1 to 8");
	glutReshapeFunc(reshape);
    glutDisplayFunc(display);    
	glutKeyboardFunc(keyPressed);
    glutMainLoop();
}
