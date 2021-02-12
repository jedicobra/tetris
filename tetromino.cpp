#include <stdlib.h>
#ifdef MAC
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <vector>
using namespace std;

const float BLOCK_SIZE = 0.1;
const int SCREEN_RATIO = 2;

struct Color{
    float r, g, b;
};

void draw_square(float x, float y, float w, Color main, Color background)
{
    glBegin(GL_POLYGON);
    glColor3f(main.r, main.g, main.b);
    glVertex2f((x)*SCREEN_RATIO, y);
    glVertex2f((x)*SCREEN_RATIO, y+w);
    glVertex2f((x+w)*SCREEN_RATIO, y+w);
    glVertex2f((x+w)*SCREEN_RATIO, y);
    glEnd();
 
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(background.r, background.g, background.b);
    glVertex2f((x)*SCREEN_RATIO, y);
    glVertex2f((x)*SCREEN_RATIO, y+w);
    glVertex2f((x+w)*SCREEN_RATIO, y+w);
    glVertex2f((x+w)*SCREEN_RATIO, y);
    glEnd();
}

class Tetromino{
    public:
        Color mainColor;
        Color outlineColor;

        // Tetromino position using Vertex2f (relative to center)
        float x, y;
        int rotation;

        
        // The dimensions of the square array (4, 3, or 2)
        int dimension;
        // The shape of the piece as a square vector of booleans
        vector<vector<bool>> shape;

        Tetromino() {};

        Tetromino(float x, float y){
            this->x = x;
            this->y = y;

            this->rotation = 0;

            this->shape = {
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}
            };
        }

        void draw(){
            for(int i = 0; i < shape.size(); i++){
                for(int j = 0; j < shape.size(); j++){
                    if(shape[i][j]){
                        cout << x+i*BLOCK_SIZE << ' ' << y+j*BLOCK_SIZE << endl << flush;
                        draw_square(x-i*BLOCK_SIZE,y-j*BLOCK_SIZE,BLOCK_SIZE, mainColor, outlineColor);
                                
                    }
                }
            }
            glFlush();
        }

        void rotate(){
            vector<vector<bool>> rotated(shape.size(), vector<bool>(shape.size(), 0));
            for(int i = 0; i < shape.size(); i++){
                for(int j = 0; j < shape.size(); j++){
                    rotated[i][j] = shape[shape.size() - j - 1][i];
                }
            }
            shape = rotated;
        }

};

// All the tetromino classes extend Tetromino
// They override the constructor, but in the draw method they should just call Tetromino::Draw()

class O_Tetromino : public Tetromino{
    public:
        O_Tetromino() {}

        O_Tetromino(float x, float y){
            mainColor = {1.0, 1.0, 0.0};

            outlineColor = {1.0, 0.643, 0.0};

            this->x = x;
            this->y = y;

            this->rotation = 0;

            this->shape = {
                {1, 1},
                {1, 1}
            };
        }

        void draw(){
            Tetromino::draw();
        }

        void rotate(){
            Tetromino::rotate();
        }

        
};

class I_Tetromino : public Tetromino{
    public:
        I_Tetromino() {}

        I_Tetromino(float x, float y){
            mainColor = {0.251, 0.778, 0.816};
            outlineColor = {0.0, 0.608, 0.820};

            this->x = x;
            this->y = y;

            this->rotation = 0;

            this->shape = {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 1, 1},
                {0, 0, 0, 0}
            };
        }

        void draw(){
            Tetromino::draw();
        }
};

class L_Tetromino : public Tetromino{
    public:
        L_Tetromino() {}

        L_Tetromino(float x, float y){
            mainColor = {0.0, 0.0, 0.804};
            outlineColor = {0.0, 0.0, 0.502};

            this->x = x;
            this->y = y;

            this->rotation = 0;

            this->shape = {
                {1, 0, 0},
                {1, 1, 1},
                {0, 0, 0}
            };
        }

        void draw(){
            Tetromino::draw();
        }
};

class J_Tetromino : public Tetromino{
    public:
        J_Tetromino() {}

        J_Tetromino(float x, float y){
            mainColor = {1.0, 0.647, 0.0};
            outlineColor = {1.0, 0.271, 0.0};

            this->x = x;
            this->y = y;

            this->rotation = 0;

            this->shape = {
                {0, 0, 1},
                {1, 1, 1},
                {0, 0, 0}
            };
        }

        void draw(){
            Tetromino::draw();
        }
};

class Z_Tetromino : public Tetromino{
    public:
        Z_Tetromino() {}

        Z_Tetromino(float x, float y){
            mainColor = {0.863, 0.078, 0.235};
            outlineColor = {0.545, 0.0, 0.0};

            this->x = x;
            this->y = y;

            this->rotation = 0;

            this->shape = {
                {1, 1, 0},
                {0, 1, 1},
                {0, 0, 0}
            };
        }

        void draw(){
            Tetromino::draw();
        }
};

class S_Tetromino : public Tetromino{
    public:
        S_Tetromino() {}

        S_Tetromino(float x, float y){
            mainColor = {0.0, 1.0, 0.0};
            outlineColor = {0.196, 0.804, 0.196};

            this->x = x;
            this->y = y;

            this->rotation = 0;

            this->shape = {
                {0, 1, 1},
                {1, 1, 0},
                {0, 0, 0}
            };
        }

        void draw(){
            Tetromino::draw();
        }
};

class T_Tetromino : public Tetromino{
    public:
        T_Tetromino() {}
        
        T_Tetromino(float x, float y){
            mainColor = {1.0, 0.0, 1.0};
            outlineColor = {0.545, 0.0, 0.545};

            this->x = x;
            this->y = y;

            this->rotation = 0;

            this->shape = {
                {0, 1, 0},
                {1, 1, 1},
                {0, 0, 0}
            };
        }

        void draw(){
            Tetromino::draw();
        }
};