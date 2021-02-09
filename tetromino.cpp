#include <stdlib.h>
#ifdef MAC
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>

const float BLOCK_SIZE = 0.12;

class Tetromino{
    public:
        // Right now I store the shapes in a 4x4 matrix (enough to hold the I-tetromino)
        // It might be better to just store the direction to increment the vertices by
        // So like down right up for the O-tetromino
        bool matrix[4][4];

        // Colors are just stored in arrays of 3 floats
        float mainColor[3];
        float outlineColor[3];

        // Tetromino position using Vertex2f (relative to center)
        float x, y;

        Tetromino() {};

        Tetromino(float x, float y){

            this->x = x;
            this->y = y;
        }

        void draw(){
            // Loop through the 2d array to find the positions that have squares
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    if(matrix[i][j]){
                        // Draw each vertex of the square
                        glBegin(GL_POLYGON);
                        glColor3f(mainColor[0], mainColor[1], mainColor[2]);

                        glVertex2f(x + i*BLOCK_SIZE, y + j*BLOCK_SIZE);
                        glVertex2f(x + i*BLOCK_SIZE, y + (j+1)*BLOCK_SIZE);
                        glVertex2f(x + (i+1)*BLOCK_SIZE, y + (j+1)*BLOCK_SIZE);
                        glVertex2f(x + (i+1)*BLOCK_SIZE, y + j*BLOCK_SIZE);
                        
                        glEnd();

                        // Draw the outline
                        glLineWidth(2.5);

                        glBegin(GL_LINE_LOOP);

                        glColor3f(outlineColor[0], outlineColor[1], outlineColor[2]);
                        
                        glVertex2f(x + i*BLOCK_SIZE, y + j*BLOCK_SIZE);
                        glVertex2f(x + i*BLOCK_SIZE, y + (j+1)*BLOCK_SIZE);
                        glVertex2f(x + (i+1)*BLOCK_SIZE, y + (j+1)*BLOCK_SIZE);
                        glVertex2f(x + (i+1)*BLOCK_SIZE, y + j*BLOCK_SIZE);
                        
                        glEnd();

                        glFlush();
                    }

                }
            }

            
        }

};

// All the tetromino classes extend Tetromino
// They override the constructor, but in the draw method they should just call Tetromino::Draw()

class O_Tetromino : Tetromino{
    public:
        O_Tetromino() {}

        O_Tetromino(float x, float y){
            matrix[0][0] = 1;
            matrix[0][1] = 1;
            matrix[0][2] = 0;
            matrix[0][3] = 0;

            matrix[1][0] = 1;
            matrix[1][1] = 1;
            matrix[1][2] = 0;
            matrix[1][3] = 0;

            matrix[2][0] = 0;
            matrix[2][1] = 0;
            matrix[2][2] = 0;
            matrix[2][3] = 0;

            matrix[3][0] = 0;
            matrix[3][1] = 0;
            matrix[3][2] = 0;
            matrix[3][3] = 0;
            

            mainColor[0] = 1.0;
            mainColor[1] = 1.0;
            mainColor[2] = 0.0;

            outlineColor[0] = 1.0;
            outlineColor[1] = 0.643;
            outlineColor[2] = 0.0;

            this->x = x;
            this->y = y;
        }

        void draw(){
            Tetromino::draw();
        }



};

class I_Tetromino : Tetromino{
    

    public:
        I_Tetromino() {}

        I_Tetromino(float x, float y){
            matrix[0][0] = 1;
            matrix[0][1] = 0;
            matrix[0][2] = 0;
            matrix[0][3] = 0;

            matrix[1][0] = 1;
            matrix[1][1] = 0;
            matrix[1][2] = 0;
            matrix[1][3] = 0;

            matrix[2][0] = 1;
            matrix[2][1] = 0;
            matrix[2][2] = 0;
            matrix[2][3] = 0;

            matrix[3][0] = 1;
            matrix[3][1] = 0;
            matrix[3][2] = 0;
            matrix[3][3] = 0;
            

            mainColor[0] = 0.251;
            mainColor[1] =  0.778;
            mainColor[2] = 0.816;

            outlineColor[0] = 0.0;
            outlineColor[1] = 0.608;
            outlineColor[2] = 0.820;

            this->x = x;
            this->y = y;
        }

        void draw(){
            Tetromino::draw();
        }
};

class L_Tetromino : Tetromino{
    

    public:
        L_Tetromino() {}

        L_Tetromino(float x, float y){
            matrix[0][0] = 1;
            matrix[0][1] = 1;
            matrix[0][2] = 0;
            matrix[0][3] = 0;

            matrix[1][0] = 0;
            matrix[1][1] = 1;
            matrix[1][2] = 0;
            matrix[1][3] = 0;

            matrix[2][0] = 0;
            matrix[2][1] = 1;
            matrix[2][2] = 0;
            matrix[2][3] = 0;

            matrix[3][0] = 0;
            matrix[3][1] = 0;
            matrix[3][2] = 0;
            matrix[3][3] = 0;
            

            mainColor[0] = 0.0;
            mainColor[1] = 0.0;
            mainColor[2] = 0.804;

            outlineColor[0] = 0.0;
            outlineColor[1] = 0.0;
            outlineColor[2] = 0.502;

            this->x = x;
            this->y = y;
        }

        void draw(){
            Tetromino::draw();
        }
};

class J_Tetromino : Tetromino{
    

    public:
        J_Tetromino() {}

        J_Tetromino(float x, float y){
            matrix[0][0] = 0;
            matrix[0][1] = 1;
            matrix[0][2] = 0;
            matrix[0][3] = 0;

            matrix[1][0] = 0;
            matrix[1][1] = 1;
            matrix[1][2] = 0;
            matrix[1][3] = 0;

            matrix[2][0] = 1;
            matrix[2][1] = 1;
            matrix[2][2] = 0;
            matrix[2][3] = 0;

            matrix[3][0] = 0;
            matrix[3][1] = 0;
            matrix[3][2] = 0;
            matrix[3][3] = 0;
            

            mainColor[0] = 1.0;
            mainColor[1] = 0.647;
            mainColor[2] = 0.0;

            outlineColor[0] = 1.0;
            outlineColor[1] = 0.271;
            outlineColor[2] = 0.0;

            this->x = x;
            this->y = y;
        }

        void draw(){
            Tetromino::draw();
        }
};

class Z_Tetromino : Tetromino{
    

    public:
        Z_Tetromino() {}

        Z_Tetromino(float x, float y){
            matrix[0][0] = 0;
            matrix[0][1] = 1;
            matrix[0][2] = 0;
            matrix[0][3] = 0;

            matrix[1][0] = 1;
            matrix[1][1] = 1;
            matrix[1][2] = 0;
            matrix[1][3] = 0;

            matrix[2][0] = 1;
            matrix[2][1] = 0;
            matrix[2][2] = 0;
            matrix[2][3] = 0;

            matrix[3][0] = 0;
            matrix[3][1] = 0;
            matrix[3][2] = 0;
            matrix[3][3] = 0;
            

            mainColor[0] = 0.863;
            mainColor[1] = 0.078;
            mainColor[2] = 0.235;

            outlineColor[0] = 0.545;
            outlineColor[1] = 0.0;
            outlineColor[2] = 0.0;

            this->x = x;
            this->y = y;
        }

        void draw(){
            Tetromino::draw();
        }
};

class S_Tetromino : Tetromino{
    

    public:
        S_Tetromino() {}

        S_Tetromino(float x, float y){
            matrix[0][0] = 0;
            matrix[0][1] = 0;
            matrix[0][2] = 0;
            matrix[0][3] = 0;

            matrix[1][0] = 1;
            matrix[1][1] = 0;
            matrix[1][2] = 0;
            matrix[1][3] = 0;

            matrix[2][0] = 1;
            matrix[2][1] = 1;
            matrix[2][2] = 0;
            matrix[2][3] = 0;

            matrix[3][0] = 0;
            matrix[3][1] = 1;
            matrix[3][2] = 0;
            matrix[3][3] = 0;
            

            mainColor[0] = 0.0;
            mainColor[1] = 1.0;
            mainColor[2] = 0.0;

            outlineColor[0] = 0.196;
            outlineColor[1] = 0.804;
            outlineColor[2] = 0.196;

            this->x = x;
            this->y = y;
        }

        void draw(){
            Tetromino::draw();
        }
};

class T_Tetromino : Tetromino{
    

    public:
        T_Tetromino() {}
        
        T_Tetromino(float x, float y){
            matrix[0][0] = 0;
            matrix[0][1] = 1;
            matrix[0][2] = 0;
            matrix[0][3] = 0;

            matrix[1][0] = 1;
            matrix[1][1] = 1;
            matrix[1][2] = 0;
            matrix[1][3] = 0;

            matrix[2][0] = 0;
            matrix[2][1] = 1;
            matrix[2][2] = 0;
            matrix[2][3] = 0;

            matrix[3][0] = 0;
            matrix[3][1] = 0;
            matrix[3][2] = 0;
            matrix[3][3] = 0;
            

            mainColor[0] = 1.0;
            mainColor[1] = 0.0;
            mainColor[2] = 1.0;

            outlineColor[0] = 0.545;
            outlineColor[1] = 0.0;
            outlineColor[2] = 0.545;

            this->x = x;
            this->y = y;
        }

        void draw(){
            Tetromino::draw();
        }
};