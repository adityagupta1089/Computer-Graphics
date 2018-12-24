#include "Turtle.h"
#include <GL/glut.h>
#include <math.h>

float x=0;
float y=0;
float theta=0;
float width=1;
enum bool draw=true;
float scale = 500.0f;

void Init(float _x,float _y, float _theta)
{
	//Implement this function
	x=_x;
	y=_y;
	theta=_theta;	
}

void Forward(float dist)
{
	//Implement this function
	// 180 = PI
	float dx = dist * cos(theta*M_PI / 180);
	float dy = dist * sin(theta*M_PI / 180);
	if(draw==true){
		glBegin(GL_LINES);
		glVertex3f(x/scale,y/scale,0.0f);
		x+=dx;
		y+=dy;
		glVertex3f(x/scale,y/scale,0.0f);
		glEnd();
	}	else{
		x+=dx;
		y+=dy;
	}
    glFlush();
}

void Backward(float dist)
{
	//Implement this function
	float dx = dist * cos(theta*M_PI / 180);
	float dy = dist * sin(theta*M_PI/ 180);
	if(draw==true){
		glBegin(GL_LINES);
		glVertex3f(x/scale,y/scale,0.0f);
		x-=dx;
		y-=dy;
		glVertex3f(x/scale,y/scale,0.0f);
		glEnd();
	} else {
		x-=dx;
		y-=dy;
	}
    glFlush();
}

void Right(float _theta)
{
	//Implement this function
	theta-=_theta;
}

void Left(float _theta)
{
	//Implement this function
	theta+=_theta;
}

void PenDown( enum bool down ) 
{
	//Implement this function
	draw = down;
}

void LineColor(float r,float g, float b)
{
	//Implement this function
	glColor3f(r, g, b);
}

void BGColor(float r,float g, float b)
{
	//Implement this function
	glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);	
	
}

void LineWidth( float _width ) 
{
	//Implement this function	
	glLineWidth(width);
}

void ResetPosition() 
{
	//Implement this function
	x=0;
	y=0;
}

void ClearScreen()
{
	//Implement this function
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
}

