#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

GLuint suzanne;
float suzannerot;
char ch = '1';

void loadObj(char* fname) {
  FILE * fp;
  int read;
  GLfloat x, y, z;
  char ch;
  suzanne = glGenLists(1);
  fp = fopen(fname, "r");
  glPointSize(5.0);
  glNewList(suzanne, GL_COMPILE); {
    glPushMatrix();
    glBegin(GL_POINTS);
    while (!(feof(fp))) {
      read = fscanf(fp, "%c %f %f %f", & ch, & x, & y, & z);
      if (read == 4 && ch == 'v') {
        glVertex3f(x*500, y*500, z*500);
      }
    }
    glEnd();
  }
  glPopMatrix();
  glEndList();
  fclose(fp);
}

void reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, (GLfloat) w / (GLfloat) h, 0.1, 1000.0);
  glMatrixMode(GL_MODELVIEW);
}

void drawMonkey() {
  glPushMatrix();
  glTranslatef(0, -50, -100);
  glColor3f(0, 0, 1);
  glScalef(0.1, 0.1, 0.1);
  glRotatef(suzannerot, 0, 1, 0);
  glCallList(suzanne);
  glPopMatrix();
  suzannerot = suzannerot + 1;
  if (suzannerot > 360) suzannerot = suzannerot - 360;
}

void display(void) {
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  drawMonkey();
  glutSwapBuffers();
}

int main(int argc, char ** argv) {
  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(20, 20);
  glutCreateWindow("Suzanne");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutIdleFunc(display);
  loadObj("monkey.obj");
  glutMainLoop();
  return 0;
}
