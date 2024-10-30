#include <GL/glut.h>
#include <math.h>


void display() {
    glClear(GL_COLOR_BUFFER_BIT); 
    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Espiral");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
