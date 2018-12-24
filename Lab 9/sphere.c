#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <irrKlang.h>

// texture variables
int width, height, nrChannels;
unsigned int texture;
unsigned char* data;

GLUquadric* sphere;

// sound variables
irrklang::ISoundEngine* engine = irrklang::createIrrKlangDevice();

void loadGLTextures() {
	// load texture object
	data = stbi_load("earth.jpg", &width, &height, &nrChannels, 0); 
	// create texture object
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // Linear Filtering
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // Linear Filtering
}

GLfloat xrot;
GLfloat yrot;
GLfloat zrot;

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// rotation
	glPushMatrix(); 
	glRotatef(xrot,1.0f,0.0f,0.0f); // Rotate On The X Axis
	glRotatef(yrot,0.0f,1.0f,0.0f); // Rotate On The Y Axis
	glRotatef(zrot,0.0f,0.0f,1.0f); // Rotate On The Z Axis
	// draw sphere
	gluQuadricDrawStyle(sphere, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, texture);
	gluQuadricTexture(sphere, GL_TRUE);
	gluQuadricNormals(sphere, GLU_SMOOTH);
	gluSphere(sphere, 1.0, 50, 50);
	// rotation
	xrot+=0.3f; // X Axis Rotation
	yrot+=0.2f; // Y Axis Rotation
	zrot+=0.4f; // Z Axis Rotation
	// swap buffers
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat) w / (GLfloat) h, 1.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -3);
}
 
void init(void) {
	sphere = gluNewQuadric();
	loadGLTextures();
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearColor(1.0f, 1.0f, 1.0f, 0.5f); // black background
	glClearDepth(1.0f); // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing
	glDepthFunc(GL_LEQUAL); // The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations
	glEnable(GL_CULL_FACE);
	engine->play2D("bensound-newdawn.mp3", GL_TRUE);
}
 
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Cube");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	init();
	glutMainLoop();
	
	return 0;
}
