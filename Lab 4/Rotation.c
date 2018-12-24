#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int movingUp = 0;
float yLocation = 0.0f;
float yRotationAngle = 0.0f;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {  
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();    
    
    glTranslatef(0.0f, 0.0f, -5.0f);    
    glTranslatef(0.0f, yLocation, 0.0f);       
    glRotatef(yRotationAngle, 0.0f, 1.0f, 0.0f);
    
    glutWireCube(2.0f);
    
    if (movingUp) {
        yLocation -= 0.0005f;
    } else {
        yLocation += 0.0005f;
    }
    
    if (yLocation < -3.0f) {
        movingUp = 0;
    } else if (yLocation > 3.0f) {
        movingUp = 1;
    }
    
    yRotationAngle += 0.005f;
    if (yRotationAngle > 360.0f) {
        yRotationAngle -= 360.0f;
    } 
    
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (GLfloat) w / (GLfloat) h, 1.0, 100.0);
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
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
