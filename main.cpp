#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef MAC
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <vector>
#include <iostream>

// All the tetris stuff is in this file
#include "tetromino.cpp"

using namespace std;

// Declare 7 global tetrominoes with the default constructors
I_Tetromino i = I_Tetromino(); 
L_Tetromino l = L_Tetromino(); 
J_Tetromino j = J_Tetromino(); 
O_Tetromino o = O_Tetromino(); 
S_Tetromino s = S_Tetromino(); 
T_Tetromino t = T_Tetromino(); 
Z_Tetromino z = Z_Tetromino();

//---------------------------------------
// Init function for OpenGL
//---------------------------------------
void init()
{
   glClearColor(0.0, 0.0, 0.0, 1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

//---------------------------------------
// Display callback for OpenGL
//---------------------------------------
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);

   // The initialization is done in display() so the positions change every time the window is resized
   // x and y are specified in the constructor
   i = I_Tetromino((rand() % 1500 - 999)*0.001, (rand() % 1500 - 999)*0.001);
   l = L_Tetromino((rand() % 1500 - 999)*0.001, (rand() % 1500 - 999)*0.001);
   j = J_Tetromino((rand() % 1500 - 999)*0.001, (rand() % 1500 - 999)*0.001);
   o = O_Tetromino((rand() % 1500 - 999)*0.001, (rand() % 1500 - 999)*0.001);
   s = S_Tetromino((rand() % 1500 - 999)*0.001, (rand() % 1500 - 999)*0.001);
   t = T_Tetromino((rand() % 1500 - 999)*0.001, (rand() % 1500 - 999)*0.001);
   z = Z_Tetromino((rand() % 1500 - 999)*0.001, (rand() % 1500 - 999)*0.001);

   // Call the draw function for each tetromino
   // Right now the tetromino draw method uses the proportions of the window (like in the source code "square" program)
   // So a resized rectangular window means rectangles instead of squares
   //Also the line width doesn't scale with the tetrominoes right now
   i.draw();
   l.draw();
   j.draw();
   o.draw();
   s.draw();
   t.draw();
   z.draw();

}

//---------------------------------------
// Main program
//---------------------------------------
int main(int argc, char *argv[])
{
   srand (time(NULL));

   glutInit(&argc, argv);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(250, 250);
   glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
   glutCreateWindow("Square");
   glutDisplayFunc(display);
   init();
   glutMainLoop();
   return 0;
}
