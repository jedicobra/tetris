#include <stdlib.h>
#ifdef MAC
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>

const float BLOCK_SIZE = 0.1;

struct Color{
    float r, g, b;
};

void draw_square(float x, float y, float w, Color main, Color background)
{
   glBegin(GL_POLYGON);
   glColor3f(main.r, main.g, main.b);
   glVertex2f((x-w/2)*2, y-w/2);
   glVertex2f((x-w/2)*2, y+w/2);
   glVertex2f((x+w/2)*2, y+w/2);
   glVertex2f((x+w/2)*2, y-w/2);
   glEnd();

   glLineWidth(3);
   glBegin(GL_LINE_LOOP);
   glColor3f(background.r, background.g, background.b);
   glVertex2f((x-w/2)*2, y-w/2);
   glVertex2f((x-w/2)*2, y+w/2);
   glVertex2f((x+w/2)*2, y+w/2);
   glVertex2f((x+w/2)*2, y-w/2);
   glEnd();
}

class Tetromino{
    public:
        // Colors are just stored in arrays of 3 floats
        Color mainColor;
        Color outlineColor;

        // Tetromino position using Vertex2f (relative to center)
        float x, y;

        Tetromino() {};

        Tetromino(float x, float y){
            this->x = x;
            this->y = y;
        }

        void draw(){

        }



};

// All the tetromino classes extend Tetromino
// They override the constructor, but in the draw method they should just call Tetromino::Draw()

class O_Tetromino : Tetromino{
    public:
        O_Tetromino() {}

        O_Tetromino(float x, float y){
            mainColor = {1.0, 1.0, 0.0};

            outlineColor = {1.0, 0.643, 0.0};

            this->x = x;
            this->y = y;
        }

        void draw(){
            draw_square(x,y,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x+BLOCK_SIZE,y,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x,y+BLOCK_SIZE,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x+BLOCK_SIZE,y+BLOCK_SIZE,BLOCK_SIZE, mainColor, outlineColor);

            glFlush();
        }
};

class I_Tetromino : Tetromino{
    public:
        I_Tetromino() {}

        I_Tetromino(float x, float y){
            mainColor = {0.251, 0.778, 0.816};
            outlineColor = {0.0, 0.608, 0.820};

            this->x = x;
            this->y = y;
        }

        void draw(){
            draw_square(x,y,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x-BLOCK_SIZE,y,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x+BLOCK_SIZE,y,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x+BLOCK_SIZE*2,y,BLOCK_SIZE, mainColor, outlineColor);

            glFlush();
        }
};

class L_Tetromino : Tetromino{
    public:
        L_Tetromino() {}

        L_Tetromino(float x, float y){
            mainColor = {0.0, 0.0, 0.804};
            outlineColor = {0.0, 0.0, 0.502};

            this->x = x;
            this->y = y;
        }

        void draw(){
            draw_square(x,y,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x-BLOCK_SIZE,y,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x+BLOCK_SIZE,y,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x+BLOCK_SIZE,y+BLOCK_SIZE,BLOCK_SIZE, mainColor, outlineColor);

            glFlush();
        }
};

class J_Tetromino : Tetromino{
    public:
        J_Tetromino() {}

        J_Tetromino(float x, float y){
            mainColor = {1.0, 0.647, 0.0};
            outlineColor = {1.0, 0.271, 0.0};

            this->x = x;
            this->y = y;
        }

        void draw(){
            draw_square(x,y,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x-BLOCK_SIZE,y,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x+BLOCK_SIZE,y,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x-BLOCK_SIZE,y+BLOCK_SIZE,BLOCK_SIZE, mainColor, outlineColor);

            glFlush();
        }
};

class Z_Tetromino : Tetromino{
    public:
        Z_Tetromino() {}

        Z_Tetromino(float x, float y){
            mainColor = {0.863, 0.078, 0.235};
            outlineColor = {0.545, 0.0, 0.0};

            this->x = x;
            this->y = y;
        }

        void draw(){
            draw_square(x,y,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x+BLOCK_SIZE,y,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x,y+BLOCK_SIZE,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x-BLOCK_SIZE,y+BLOCK_SIZE,BLOCK_SIZE, mainColor, outlineColor);

            glFlush();
        }
};

class S_Tetromino : Tetromino{
    public:
        S_Tetromino() {}

        S_Tetromino(float x, float y){
            mainColor = {0.0, 1.0, 0.0};
            outlineColor = {0.196, 0.804, 0.196};

            this->x = x;
            this->y = y;
        }

        void draw(){
            draw_square(x,y,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x-BLOCK_SIZE,y,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x,y+BLOCK_SIZE,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x+BLOCK_SIZE,y+BLOCK_SIZE,BLOCK_SIZE, mainColor, outlineColor);

            glFlush();
        }
};

class T_Tetromino : Tetromino{
    public:
        T_Tetromino() {}
        
        T_Tetromino(float x, float y){
            mainColor = {1.0, 0.0, 1.0};
            outlineColor = {0.545, 0.0, 0.545};

            this->x = x;
            this->y = y;
        }

        void draw(){
            draw_square(x,y,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x-BLOCK_SIZE,y,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x+BLOCK_SIZE,y,BLOCK_SIZE, mainColor, outlineColor);
            draw_square(x,y+BLOCK_SIZE,BLOCK_SIZE, mainColor, outlineColor);

            glFlush();
        }
};