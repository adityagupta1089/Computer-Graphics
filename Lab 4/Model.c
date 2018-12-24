#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void draw_triangle() {
	glBegin(GL_LINE_LOOP);
    glVertex3f(-0.25, 0, 0);
    glVertex3f(0.25, 0, 0);
    glVertex3f(0, 0.5, 0);
    glEnd();
}

void draw_axis() {
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);
	glEnd();
	
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(10.0, 0.0, 0.0);
	glEnd();
}

void renderPrimitive() {
	glLoadIdentity();
	draw_axis();
	glColor3f(1.0, 1.0, 1.0);
	draw_triangle();
	
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0xF0F0);
	glLoadIdentity();
	glTranslatef(-0.5, 0.0, 0.0);
	draw_triangle();
	
	glLineStipple(1, 0xF00F);
	glLoadIdentity();
	glScalef(1.5, 0.5, 1.0);
	draw_triangle();
	
	glLineStipple(1, 0x8888);
	glLoadIdentity();
	glRotatef(90.0, 0.0, 0.0, 1.0);
	draw_triangle();
	glDisable(GL_LINE_STIPPLE);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();   
    renderPrimitive();
    glFlush(); 
}


void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();  
	glFrustum(-1.0, 1.0, -1.0, 1.0, -1.0, 20.0);
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
