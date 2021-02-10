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

vector<Tetromino*> pieces;


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

   for(int i = 0; i < pieces.size(); i++){
      pieces.at(i)->draw();
   }

}


void keyboard(unsigned char key, int x, int y)
{
   switch(key)
   {
      case 'o':
         pieces.push_back(new O_Tetromino(0.0, 0.0));
         break;
   }
   
   // Redraw objects
   glutPostRedisplay();
}




//---------------------------------------
// Keyboard callback for OpenGL
//---------------------------------------
void special(int key, int x, int y)
{
   if(pieces.size() > 0){
      switch(key)
      {
         case GLUT_KEY_UP:
            pieces.back()->y += 0.1;
            break;
         case GLUT_KEY_DOWN:
            pieces.back()->y -= 0.1;
            break;
         case GLUT_KEY_LEFT:
            pieces.back()->x -= 0.1;
            break;
         case GLUT_KEY_RIGHT:
            pieces.back()->x += 0.1;
            break;
         default:
            break;
      }

      // Redraw objects
      glutPostRedisplay();
   }
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
   glutSpecialFunc(special);
   glutKeyboardFunc(keyboard);
   init();
   glutMainLoop();
   return 0;
}
