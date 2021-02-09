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

void drawGrid(){
   glLineWidth(3);
   
   
   //Draw vertical lines
   for(float x = -1.0; x < 1.0; x+=0.2){
      glBegin(GL_LINE_LOOP);
      glColor3f(0.439, 0.502, 0.565);
      glVertex2f(x, -1.0);
      glVertex2f(x, 1.0);
      glEnd();
   }
   //Draw horizontal lines
   for(float y = -1.0; y < 1.0; y+=0.1){
      glBegin(GL_LINE_LOOP);
      glColor3f(0.439, 0.502, 0.565);
      glVertex2f(-1.0, y);
      glVertex2f(1.0, y);
      glEnd();
   }
   glFlush();
}

//---------------------------------------
// Display callback for OpenGL
//---------------------------------------
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);

   drawGrid();

   // The initialization is done in display() so the positions change every time the window is resized
   // x and y are specified in the constructor
   i = I_Tetromino(0, 0);

   // Call the draw function for each tetromino
   // Right now the tetromino draw method uses the proportions of the window (like in the source code "square" program)
   // So a resized rectangular window means rectangles instead of squares
   //Also the line width doesn't scale with the tetrominoes right now
   i.draw();

}

//---------------------------------------
// Main program
//---------------------------------------
int main(int argc, char *argv[])
{
   srand (time(NULL));

   glutInit(&argc, argv);
   glutInitWindowSize(500, 1000);
   glutInitWindowPosition(250, 250);
   glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
   glutCreateWindow("Max's Tetris");
   glutDisplayFunc(display);
   init();
   glutMainLoop();
   return 0;
}
