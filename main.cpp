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

#include "tetromino.cpp"

using namespace std;

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
void displayO()
{
   // glClear(GL_COLOR_BUFFER_BIT);

   // glBegin(GL_POLYGON);
   // glColor3f(1.0, 1.0, 0.0);
   // glVertex2f(-0.25, -0.25);
   // glVertex2f(-0.25, 0.25);
   // glVertex2f(0.25, 0.25);
   // glVertex2f(0.25, -0.25);
   // glEnd();

   // glLineWidth(50.0);

   // glBegin(GL_LINE_LOOP);
   // // Dark yellow
   // glColor3f(1.0, 0.643, 0.0);
   
   // glVertex2f(-0.25, -0.25);
   // glVertex2f(-0.25, 0.25);
   // glVertex2f(0.25, 0.25);
   // glVertex2f(0.25, -0.25);
   // glEnd();

   // glFlush();
   O_Tetromino o = O_Tetromino(-0.5, -0.5);
   
   o.draw();

}

//---------------------------------------
// Main program
//---------------------------------------
int main(int argc, char *argv[])
{
   glutInit(&argc, argv);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(250, 250);
   glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
   glutCreateWindow("Square");
   glutDisplayFunc(displayO);
   init();
   glutMainLoop();
   return 0;
}
