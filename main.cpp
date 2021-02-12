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
   for(int i = -10; i < 10; i+=2){
      float x = i/10.0f;
      glBegin(GL_LINE_LOOP);
      glColor3f(0.439, 0.502, 0.565);
      if(x == 0.0f) glColor3f(1.0, 0.0, 1.0);
      glVertex2f(x, -1.0);
      glVertex2f(x, 1.0);
      glEnd();
   }
   //Draw horizontal lines
   for(int i = -10; i < 10; i+=1){
      float y = i/10.0f;
      glBegin(GL_LINE_LOOP);
      glColor3f(0.439, 0.502, 0.565);
      if(y == 0.0f) glColor3f(1.0, 0.0, 1.0);
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
      case 'O':
         pieces.push_back(new O_Tetromino(0.0, 0.0));
         break;
      case 'i':
      case 'I':
         pieces.push_back(new I_Tetromino(0.0, 0.0));
         break;
      case 'j':
      case 'J':
         pieces.push_back(new J_Tetromino(0.0, 0.0));
         break;
      case 'l':
      case 'L':
         pieces.push_back(new L_Tetromino(0.0, 0.0));
         break;
      case 'z':
      case 'Z':
         pieces.push_back(new Z_Tetromino(0.0, 0.0));
         break;
      case 's':
      case 'S':
         pieces.push_back(new S_Tetromino(0.0, 0.0));
         break;
      case 't':
      case 'T':
         pieces.push_back(new T_Tetromino(0.0, 0.0));
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
            pieces.back()->rotate();
            break;
         case GLUT_KEY_DOWN:
            if(pieces.back()->y > -1.0)
               pieces.back()->y -= 0.1;
            break;
         case GLUT_KEY_LEFT:
            if(pieces.back()->x > -0.5)
               pieces.back()->x -= 0.1;
            break;
         case GLUT_KEY_RIGHT:
            if(pieces.back()->x < 0.5)
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
   glutInitWindowSize(500, 500*SCREEN_RATIO);
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
