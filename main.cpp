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
void display()
{


   glClear(GL_COLOR_BUFFER_BIT);

   I_Tetromino i = I_Tetromino((rand() % 1500 - 999)*0.001, (rand() % 1500 - 999)*0.001);
   i.draw();

   L_Tetromino l = L_Tetromino((rand() % 1500 - 999)*0.001, (rand() % 1500 - 999)*0.001);
   l.draw();

   J_Tetromino j = J_Tetromino((rand() % 1500 - 999)*0.001, (rand() % 1500 - 999)*0.001);
   j.draw();

   O_Tetromino o = O_Tetromino((rand() % 1500 - 999)*0.001, (rand() % 1500 - 999)*0.001);
   o.draw();

   S_Tetromino s = S_Tetromino((rand() % 1500 - 999)*0.001, (rand() % 1500 - 999)*0.001);
   s.draw();

   T_Tetromino t = T_Tetromino((rand() % 1500 - 999)*0.001, (rand() % 1500 - 999)*0.001);
   t.draw();

   Z_Tetromino z = Z_Tetromino((rand() % 1500 - 999)*0.001, (rand() % 1500 - 999)*0.001);
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
