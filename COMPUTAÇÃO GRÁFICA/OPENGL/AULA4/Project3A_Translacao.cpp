#include <GL/glut.h>
#include <stdlib.h>

void Desenho(void)
{

}

void Desenha (void)
{
     glClear(GL_COLOR_BUFFER_BIT);
     glViewport(0,0,400,400);
     Desenho();
     glFlush();
}

void Teclado (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

void Inicializa (void)
{
       glClearColor(0.0,0.0,0.0,1.0);
       glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       gluOrtho2D(-10.0,10.0,-10.0,10.0);
}

int main(void)
{
    glutInitWindowSize(400,400);
    glutInitWindowPosition(0,0);
    glutCreateWindow("teste");
    Inicializa();
    glutDisplayFunc(Desenha);
	glutKeyboardFunc(Teclado);
    glutMainLoop();
}
