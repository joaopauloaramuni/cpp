#include <GL/glut.h>
#include <stdlib.h>

GLfloat win;

void Desenha (void)
{   
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0,1.0,1.0);
     glBegin(GL_TRIANGLES);
         glVertex2f(-40.0f,-40.0f);
         glVertex2f(0.0f,40.f);
         glVertex2f(40.0f,-40.0f);
     glEnd();
     glColor3f(1.0,0.0,0.0);
     glutWireCube(40.0);
}

void especificarParametrosVisualizacao(void) {
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(-65,65,-65,65,-400,400);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     gluLookAt(60,60,100,0,0,0,0,1,0);
}

void Inicializa (void)
{
     glClearColor(0.0f,0.0f,0.0f,1.0f);
}

int main(void)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(400,400);
    glutCreateWindow("Teste 3D");
    glutDisplayFunc(Desenha);
    especificarParametrosVisualizacao();
    Inicializa();
    glutMainLoop();
}
