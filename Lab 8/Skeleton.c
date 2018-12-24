#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define head0 0
#define shoulderLeft0 110
#define shoulderRight0 -110
#define armLeft0 20
#define armRight0 -20
#define torso0 90
#define waist0 0
#define thighLeft0 -30
#define thighRight0 30
#define legRight0 -20
#define legLeft0 50

static int 
	head = head0,
	shoulderLeft = shoulderLeft0,
	shoulderRight = shoulderRight0,
	armLeft = armLeft0,
	armRight = armRight0,
	torso = torso0,
	waist = waist0,
	thighLeft = thighLeft0,
	thighRight = thighRight0,
	legRight = legRight0,
	legLeft = legLeft0;
	
static int t = 0;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display(void) {

	t++;
	t%=100000;

	torso = torso0 + 10 * sin(0.02 * t);
	head = head0 + 20 * sin(0.05 * t);
	shoulderLeft = shoulderLeft0 + 20 * sin(0.2 * t);
	shoulderRight = shoulderRight0 + 80 * sin(0.05 * t);
	thighLeft = thighLeft0 + 30 * sin(0.05 * t);
	thighRight = thighRight0 - 30 * sin(0.05 * t);
	legLeft = legLeft0 + 20 * sin(0.1 * t);
	legRight = legRight0 - 20 * sin(0.1 * t);
	armLeft = armLeft0 + 60 * sin (0.03 * t);
	armRight = armRight0 - 60 * sin (0.03 * t);
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPushMatrix(); // save center
	
	
	glRotatef((GLfloat) 180 * sin(0.02 * t),  0, 1, 0);
	glRotatef((GLfloat) torso, 0.0, 0.0, 1.0);
	
	glPushMatrix(); // save torso4
	glPushMatrix(); // save torso3
	glPushMatrix(); // save torso2
	glPushMatrix(); // save torso
		
	glScalef(1.5, 0.1, 0.1); 
	glColor3f(1,0,0);
	glutWireCube(1.0); 
	
	glPopMatrix(); // get torso
	
	glTranslatef(-0.75,0,0);	
	glColor3f(0.8,0.2,0.6);
	glutWireSphere(0.3,20,20);
	glRotatef((GLfloat) waist, 0.0, 0.0, 1.0);
	glTranslatef(-0.75,0,0);	
	

	glPushMatrix(); // save waist2
	glPushMatrix(); // save waist
	
	glScalef(1.5, 0.1, 0.1); 
	glColor3f(0,1,0);
	glutWireCube(1.0); 
	
	glPopMatrix(); // get waist
		
	glTranslatef(-0.75,0,0);	
	glColor3f(0.8,0.2,0.6);
	glutWireSphere(0.3,20,20);
	glRotatef((GLfloat) thighLeft, 0.0, 0.0, 1.0);
	glTranslatef(-0.75,0,0);	
	
	glPushMatrix(); // save thighleft
	
	glScalef(1.5, 0.1, 0.1); 
	glColor3f(0,0,1);
	glutWireCube(1.0); 	
	
	glPopMatrix(); // get thighleft
	
	glTranslatef(-0.75,0,0);
	glColor3f(0.8,0.2,0.6);
	glutWireSphere(0.3,20,20);	
	glRotatef((GLfloat) legLeft, 0.0, 0.0, 1.0);
	glTranslatef(-0.75,0,0);	
	
	glPushMatrix();
	glScalef(1.5, 0.1, 0.1); 
	glColor3f(0,1,1);
	glutWireCube(1.0); 	
	glPopMatrix();
	
	glTranslatef(-0.75,0,0);
	glColor3f(0.8,0.2,0.6);
	glutWireSphere(0.3,20,20);
	
	glPopMatrix(); // get waist2
	
	glTranslatef(-0.75,0,0);	
	glRotatef((GLfloat) thighRight, 0.0, 0.0, 1.0);
	glTranslatef(-0.75,0,0);	
	
	glPushMatrix(); // save thighright
	
	glScalef(1.5, 0.1, 0.1); 
	glColor3f(1,0,1);
	glutWireCube(1.0); 	
	
	glPopMatrix(); // get thighright
	
	glTranslatef(-0.75,0,0);
	glColor3f(0.8,0.2,0.6);
	glutWireSphere(0.3,20,20);	
	glRotatef((GLfloat) legRight, 0.0, 0.0, 1.0);
	glTranslatef(-0.75,0,0);	
	
	glPushMatrix();
	glScalef(1.5, 0.1, 0.1); 
	glColor3f(1,1,0);
	glutWireCube(1.0);
	glPopMatrix();
	
	glTranslatef(-0.75,0,0);
	glColor3f(0.8,0.2,0.6);
	glutWireSphere(0.3,20,20);
	
	glPopMatrix(); // get torso2
	
	glTranslatef(0.75,0,0);	
	glColor3f(0.8,0.2,0.6);
	glutWireSphere(0.3,20,20);
	glRotatef((GLfloat) shoulderLeft, 0.0, 0.0, 1.0);
	glTranslatef(0.75,0,0);	
	
	glPushMatrix(); // save shoulderleft
	
	glScalef(1.5, 0.1, 0.1); 
	glColor3f(1,0.5,0);
	glutWireCube(1.0); 	
	
	glPopMatrix(); // get shoulderleft
	
	glTranslatef(0.75,0,0);	
	glColor3f(0.8,0.2,0.6);
	glutWireSphere(0.3,20,20);
	glRotatef((GLfloat) armLeft, 1.0, 1.0, 1.0);
	glTranslatef(0.75,0,0);	
	
	glPushMatrix();
	glScalef(1.5, 0.1, 0.1); 
	glColor3f(0.3,0,.1);
	glutWireCube(1.0); 	
	glPopMatrix();
	
	glTranslatef(0.75,0,0);
	glColor3f(0.8,0.2,0.6);
	glutWireSphere(0.3,20,20);
	
	glPopMatrix(); // get torso3
	
	glTranslatef(0.75,0,0);	
	glColor3f(0.8,0.2,0.6);
	glutWireSphere(0.3,20,20);
	glRotatef((GLfloat) shoulderRight, 0.0, 0.0, 1.0);
	glTranslatef(0.75,0,0);	
	
	glPushMatrix(); // save shoulderRight
	
	glScalef(1.5, 0.1, 0.1); 
	glColor3f(0.6,0.2,0);
	glutWireCube(1.0); 	
	
	glPopMatrix(); // get shoulderRight
	
	glTranslatef(0.75,0,0);	
	glColor3f(0.8,0.2,0.6);
	glutWireSphere(0.3,20,20);
	glRotatef((GLfloat) armRight, 0.0, 0.0, 1.0);
	glTranslatef(0.75,0,0);	
	
	glPushMatrix();
	glScalef(1.5, 0.1, 0.1); 
	glColor3f(1,1,1);
	glutWireCube(1.0); 
	glPopMatrix();
	
	glTranslatef(0.75,0,0);
	glColor3f(0.8,0.2,0.6);
	glutWireSphere(0.3,20,20);
	
	glPopMatrix(); // get torso4
	
	glTranslatef(0.75,0,0);	
	glColor3f(0.8,0.2,0.6);
	glutWireSphere(0.3,20,20);
	glRotatef((GLfloat) head, 0.0, 0.0, 1.0);
	glTranslatef(0.75,0,0);	
	
	glPushMatrix(); // save head
	
	glScalef(1.5, 0.1, 0.1); 
	glColor3f(0.5,0.2,0.2);
	glutWireCube(1.0); 
	
	glPopMatrix(); // get head
	
	glTranslatef(1.75,0,0);
	glColor3f(0.8,0.2,0.6);
	glutWireSphere(1,20,20);
	
	
	glPopMatrix(); // get center
	
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -10.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Dancing Skeleton");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
