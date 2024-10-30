#include <GL/glut.h>
#include <iostream>

float posX = 0.0f;
float posY = 0.0f;

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': 
            posY += 0.01f;
            break;
        case 's': 
            posY -= 0.01f;
            break;
        case 'a':
            posX -= 0.01f;
            break;
        case 'd': 
            posX += 0.01f;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void drawTriangle() {
    glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity(); 

    glBegin(GL_TRIANGLES);
    glVertex2f(posX, posY + 0.1f);
    glVertex2f(posX - 0.1f, posY - 0.1f); 
    glVertex2f(posX + 0.1f, posY - 0.1f); 
    glEnd();

    glutSwapBuffers(); 
}


void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glColor3f(1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
    glutInitWindowSize(800, 600); 
    glutCreateWindow("Movimento de Geometria"); 
    init(); 
    glutDisplayFunc(drawTriangle); 
    glutKeyboardFunc(keyboard);
    glutMainLoop(); 
    return 0;
}
