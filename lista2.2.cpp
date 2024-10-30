#include <GL/glut.h>
#include <iostream>

void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.1f);  
    glVertex2f(-0.1f, -0.1f); 
    glVertex2f(0.1f, -0.1f);  
    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix(); 
    drawTriangle();
    glPopMatrix(); 

  
    glPushMatrix(); 
    glTranslatef(-0.5f, 0.0f, 0.0f);  
    drawTriangle();
    glPopMatrix(); 

    glPushMatrix();
    glTranslatef(0.5f, 0.0f, 0.0f); 
    glScalef(0.5f, 0.5f, 1.0f);
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f); 
    drawTriangle();
    glPopMatrix(); 

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
    glutCreateWindow("Desenho de Triângulos com Transformações");
    init(); 
    glutDisplayFunc(display); 
    glutMainLoop();
    return 0;
}
