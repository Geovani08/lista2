#include <GL/glut.h>
#include <math.h>
#include <cstdlib>  
#include <ctime>   

GLfloat azul[] = {0.0f, 0.0f, 1.0f};    
GLfloat amarelo[] = {1.0f, 1.0f, 0.0f};
GLfloat verde[] = {0.0f, 1.0f, 0.0f};   
GLfloat roxo[] = {0.5f, 0.0f, 0.5f};    
GLfloat rosa[] = {1.0f, 0.0f, 0.5f};     
GLfloat laranja[] = {1.0f, 0.5f, 0.0f};  

void setCor(GLfloat color[3]) {
    glColor3f(color[0], color[1], color[2]);
}

GLfloat* getCorRandomica() {
    static bool isSeeded = false; 

    if (!isSeeded) {
        std::srand(static_cast<unsigned>(std::time(0))); 
        isSeeded = true;
    }

    switch(std::rand() % 6) {
        case 0: return azul; 
        case 1: return amarelo; 
        case 2: return verde; 
        case 3: return roxo; 
        case 4: return rosa; 
        case 5: return laranja; 
        default: return azul;
    }
}

void desenhaQuadrado(float x, float y, float tamanho) {
    setCor(getCorRandomica()); 
    glBegin(GL_QUADS); 
        glVertex2f(x, y);
        glVertex2f(x + tamanho, y);
        glVertex2f(x + tamanho, y + tamanho); 
        glVertex2f(x, y + tamanho); 
    glEnd(); 
}

void desenharGridQuadrados(){
    int numQuadrados = 6;

    for(int linha = 0; linha < numQuadrados; linha++) {
        for(int coluna = 0; coluna < numQuadrados; coluna++) {
            float posX = coluna * 100.0f; 
            float posY = linha * 100.0f;   
            desenhaQuadrado(posX, posY, 100.0f);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); 
    desenharGridQuadrados(); 
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Grid de quadrados");
    gluOrtho2D(0, 600, 0, 600); 
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
