#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define shoulder0 -45
#define elbow0 75
#define finger10 45
#define finger20 -45
#define ball0 0

static int shoulder = shoulder0, elbow = elbow0, finger1 = finger10, finger2 = finger20, ball = ball0;
int object_visible = 0;
int should_animate = 0;
static int cnt = 0;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void reset() {	
	shoulder = shoulder0;
	elbow = elbow0;
	finger1 = finger10;
	finger2 = finger20;
	ball = ball0;
	object_visible = 0;
	glutPostRedisplay();
}

void display(void) {
	if (should_animate) {
		if (cnt == 0) {
			reset();
			object_visible = 1;
			cnt++;			
		} else if (cnt < 20) {
			shoulder = (shoulder + 1) % 360;
			cnt++;
		} else if (cnt > 30 && cnt < 40) {
			elbow = (elbow + 1) % 360;
			cnt++;
		} else if (cnt > 50 && cnt < 100) {
			finger1 = (finger1 - 1) % 360;
			finger2 = (finger2 + 1) % 360;
			cnt++;
		} else if (cnt > 110 && cnt < 140) {
			shoulder = (shoulder - 1) % 360;
			ball = (ball - 1) % 360;
			cnt++;
		} else if (cnt > 150 && cnt < 200) {
			finger1 = (finger1 + 1) % 360;
			finger2 = (finger2 - 1) % 360;
			cnt++;
		} else if (cnt > 200) {
			should_animate = 0;
			cnt = 0;
		} else {
			cnt++;
		}
	}

	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix(); 
	glTranslatef(-1.0, 0.0, 0.0); // pivot point
	glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0); // pivot cube
	glTranslatef(1.0, 0.0, 0.0); // go back to center
	glPushMatrix(); // shoulder scale
	glScalef(2.0, 0.4, 1.0); 
	glutWireCube(1.0); 
	glPopMatrix(); // shoulder scale
	
	glTranslatef(1.0, 0.0, 0.0); //pivot point
	glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0); // rotate
	glTranslatef(1.0, 0.0, 0.0); // move along shoulder
	glPushMatrix(); // elbow scale
	glScalef(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix(); // elbow scale
	
	glPushMatrix(); // finger
	glTranslatef(1.0, 0.2, 0.0); // pivot point
	glRotatef((GLfloat) finger1, 0.0, 0.0, 1.0); // rotate
	glTranslatef(0.2, 0.0, 0.0); // move to mid
	
	// finger 1.1
	glPushMatrix(); // finger1 scale
	glScalef(2.0, 0.4, 1.0);
	glutWireCube(0.2); 
	glPopMatrix(); // finger1 scale
	// finger 1.2
	glTranslatef(0.0, 0.0, 0.2); // move
	glPushMatrix(); // finger1 scale
	glScalef(2.0, 0.4, 1.0);
	glutWireCube(0.2); 
	glPopMatrix(); // finger1 scale
	// finger 1.3
	glTranslatef(0.0, 0.0, 0.4); // move to mid
	glPushMatrix(); // finger1 scale
	glScalef(2.0, 0.4, 1.0);
	glutWireCube(0.2); 
	glPopMatrix(); // finger1 scale
	
	glPopMatrix(); // elbow
	
	glTranslatef(1.0, -0.2, 0.0); // pivot point
	glRotatef((GLfloat) finger2, 0.0, 0.0, 1.0); // rotate
	glTranslatef(0.2, 0.0, 0.0); // move to mid
	glPushMatrix(); // finger2 scale
	glScalef(2.0, 0.4, 1.0);
	glutWireCube(0.2); 
	glPopMatrix(); // finger2 scale
	
	glPopMatrix(); 
	
	if (object_visible) {		
		glPushMatrix(); // object
		glTranslatef(-1.0, 0.0, 0.0); // pivot point
		glRotatef((GLfloat) ball, 0.0, 0.0, 1.0); // rotate
		// go back and additional (2, 1.1), i.e.
		// (1, 0) + (2, 1.1)
		glTranslatef(3.0, 1.1, 0.0); 
		glutWireSphere(0.1, 10, 10); 
		glPopMatrix();  // object
	}
	
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void animate() {
	should_animate = 1;
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 's':
			shoulder = (shoulder + 5) % 360;
			glutPostRedisplay();
			break;
		case 'S':
			shoulder = (shoulder - 5) % 360;
			glutPostRedisplay();
			break;
		case 'e':
			elbow = (elbow + 5) % 360;
			glutPostRedisplay();
			break;
		case 'E':
			elbow = (elbow - 5) % 360;
			glutPostRedisplay();
			break;
		case 'q':
			finger1 = (finger1 + 5) % 360;
			glutPostRedisplay();
			break;
		case 'Q':
			finger1 = (finger1 - 5) % 360;
			glutPostRedisplay();
			break;
		case 'w':
			finger2 = (finger2 + 5) % 360;
			glutPostRedisplay();
			break;
		case 'W':
			finger2 = (finger2 - 5) % 360;
			glutPostRedisplay();
			break;
		case 'r':
			reset();
			break;
		case 'a':
			animate();
			break;
		case 'p':
			object_visible = 1 - object_visible;
			glutPostRedisplay();
			break;
		default:
			break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
