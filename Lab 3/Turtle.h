#ifndef TURTLE_H
#define TURTLE_H

enum bool {
	true, false
};

void Init(float _x,float _y, float _theta);
void Forward(float dist);
void Backward(float dist);
void Right(float _theta);
void Left(float _theta);
void PenDown( enum bool down );
void LineColor(float r,float g, float b);
void BGColor(float r,float g, float b);
void LineWidth( float width );
void ResetPosition();
void ClearScreen();


#endif
