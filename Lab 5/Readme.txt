CSL457 - Computer Graphics - Lab 5

"helloteapot.cc" Exercises:
1. compiled and run
2. window size increases and decreases according to given value and position changes according to the given coordinate to window position.
3. wire teapot changes to a wired one and size make teapot smaller or larger.

"helloteapot2.cc" Exercises:
1. glViewport parameters changes the viewing region and resizing resizes the teapot.
2. 
	a) just before "tell GLUT to wait for event" => no resize happens
	b) just before the "create and set up a window" => no resize happens
	

"helloteapot3.cc" Exercises:
1. Because of orthographic projection we have a large region so the teapot appears smaller.
2. Increasing the othographic projection region we get smaller teapot and vice versa.
3. No difference is seen because we are changing projection properties after model projection or not makes no difference.

helloteapot4.cc Exercises:
1. Chaging eye changes size of object that we percieve, changing lookat changes the region that is visible, changing up changes the orientation of the teapot.
2. 
	a) before projection transformation => no change
	b) before viewport transformation => no change
		and omitting load identity => teapot disappears
	c) before "future matrix manipulations should affect the modelview matrix" => no change
	d) before glFlush() => no change
	
"A Different Perspective" exercises:
1. gluPerspective(60, 1, 0, 100);
2. Changing near plane to 0.5 makes teapot look smaller.

"teapotsgalore.cc" Exercises:
1. bottom teapot is at z=-1 which is closer than z=-3 hence bigger.
2. remove translate and pop operations after first teapot
3. use popmatrix after middle teapot and remove translate and popmatrix after that
4. The operation push matrix is applied every time because we are not popping the operations before each flush.
5. bottom teapot disappears because we have more than 2 matrices on the modelview stack (i.e. 3)
6. Size of teapots appears larger as gluLookAt operation matrix is removed from modelview stack.
7. we would like to push matrix before drawing each car element and pop matrix after car's element are complete, in this way we can move the entirity of car in one go, and similarly for the house.
