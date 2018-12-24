#include "Drawings.h"

void Square()
{
	ClearScreen();
	Init( 250, 250, 0 );		// Move to the center (facing right)
	BGColor( 0, 0, 0 );		// Set Background color black
	LineColor( 1 , 1, 1 );		// Set Line color white
	PenDown( false );		// Move without drawing
	Forward( 50 );			// Move forward (right) 50 units
	Left( 90 );			// Turn left 90 degrees (facing up)
	PenDown ( true );		// Start Drawing
	Forward( 50 );			// Move forward (up) 50 units
	Left( 90 );			// Turn left 90 degrees (facing left)
	Forward( 100 );			// ...
	Left( 90 );
	Forward( 100 );
	Left( 90 );
	Forward( 100 );
	Left( 90 );
	Forward( 50 );
}

void Original1()
{
	//Heptagon & Circle
	ClearScreen();
	Init( 0, 0, 0 );		// Move to the center (facing right)
	BGColor( 0, 0, 0 );		// Set Background color black
	LineColor( 1 , 1, 1 );		// Set Line color white
	PenDown( true );		
	for(int i=0;i<7;i++){
		Forward(50);
		Right(360/7);
	}
	PenDown(false);
	Backward(150);
	PenDown(true);
	for(int i=0;i<360;i++){
		Forward(1);
		Right(1);
	}
}

void Original2()
{
	//house
	ClearScreen();
	Init(0,0,0);
	BGColor(1,1,1);
	LineColor(1,0,0);
	PenDown(true);
	Forward(100);
	Left(30);
	Forward(100);
	Left(60);
	Forward(50);
	Right(60);
	Backward(100);
	Left(60);
	Backward(50);
	PenDown(false);
	Forward(50);
	PenDown(true);
	Left(90);
	Forward(100);
	Left(90);
	Forward(50);
	PenDown(false);
	Backward(50);
	Right(225);
	PenDown(true);
	Forward(70);
	PenDown(false);
	Backward(70);
	Right(45);
	Forward(100);
	Left(135);
	PenDown(true);
	Forward(70);
	Right(105);
	Forward(100);
	Left(105);
	Backward(70);
}

void Example()
{
	// For Instructor/TA to fill
	ClearScreen();
	Init(0,0,0);
	BGColor(1,1,1);
	LineColor(1,0,0);
	PenDown(true);
	// draw here
}
