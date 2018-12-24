#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

double radians(double degrees) {
	return degrees * M_PI / 180;
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();    
    gluLookAt(5.0, 5.0, 5.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0);
    glScalef(2.0, 3.0, 0.5);
    glColor3f(1, 0, 0);
    // normal cube
    glutWireCube(1.0);
    glTranslated(2.0, 0.0, 0.0);
    glColor3f(0, 1, 0);
    // shifted cube
    glutWireCube(1.0);
    // same but shifted in z to show clearly
    GLdouble translate[16] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1};
    glMultMatrixd(translate);
    glColor3f(0, 0, 1);
    // shifted using multiply 
    glutWireCube(1.0);
    glTranslated(0,0,5);
    glRotated(45, 1, 0, 0);
    glColor3f(1, 1, 0);
    // rotated and shifted
    glutWireCube(1.0);    
    GLdouble rotate[16] = {1,0,0,0,0,cos(radians(80)),sin(radians(80)),0,0,-sin(radians(80)),cos(radians(80)),0,-2,0,-1,1};
    glMultMatrixd(rotate);
    glColor3f(0, 1, 1);
    // rotated and shifted using multiply
    glutWireCube(1.0);
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
