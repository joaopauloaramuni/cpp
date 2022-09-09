#include <GL/glut.h>
#include <stdlib.h>

GLfloat win;

void DesenhaQuadro(void)
{
     //DEFINE A MATRIZ A SER UTILIZADA
     glMatrixMode(GL_MODELVIEW); 
     //PARA CARREGAR A MATRIZ IDENTIDADE
     glLoadIdentity();
     //EMPILHA A MATRIZ PARA TRANSLATE SOBRE A IDENTIDADE 
     glPushMatrix(); 

     //Retangulo Base
     glTranslatef(0,-5,0);
     glColor3f(1,0,0);
     glBegin(GL_QUADS);
         glVertex2f(-1.0,1.6);
         glVertex2f(1.0,1.6);
         glVertex2f(1.0,-1.0);
         glVertex2f(-1.0,-1.0);
     glEnd();

     //Retangulo Corpo
     glTranslatef(0,2,0);
     glColor3f(0.0,0.0,1.0);
     glBegin(GL_QUADS);
         glVertex2f(-.6,2.0);
         glVertex2f(.6,2.0);
         glVertex2f(.6,-1.0);
         glVertex2f(-.6,-1.0);
     glEnd();

     //Retangulo Corpo
     glTranslatef(0,2,0);
     glColor3f(0,1,0);
     glBegin(GL_QUADS);
         glVertex2f(-.6,2.0);
         glVertex2f(.6,2.0);
         glVertex2f(.6,-1.0);
         glVertex2f(-.6,-1.0);
     glEnd();

     //RETIRA A ULTIMA MATRIZ (TRANSLATE) DA PILHA
     glPopMatrix(); 

     //EMPILHA A MATRIZ PARA ROTATE SOBRE A IDENTIDADE
     glPushMatrix();
}

void Desenha (void)
{
     glClear(GL_COLOR_BUFFER_BIT);
     glViewport(0,0,400,400);
     DesenhaQuadro();
     glFlush();
}

void TeclasEspeciais(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		if (win > 0)
			win -= 1.0f;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		if (win < 900)
			win += 1.0f;
	}

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glutPostRedisplay();
}

void Teclado (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

void Inicializa (void)
{
       glClearColor(1.0,1.0,1.0,1.0);
       glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       gluOrtho2D(-10.0,10.0,-10.0,10.0);
}

int main(void)
{
    glutInitWindowSize(400,400);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Guindastizinhoooo");
    Inicializa();
    glutDisplayFunc(Desenha);
	glutSpecialFunc(TeclasEspeciais);
	glutKeyboardFunc (Teclado);
    glutMainLoop();
}
