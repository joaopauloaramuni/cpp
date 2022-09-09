#include <GL/glut.h>
#include <stdlib.h>

//ANIMACAO

GLfloat win;
GLfloat deslocaX = 0;//DEFINE O DESLOCAMENTO TOAL EM X

void DesenhaQuadro(void)
{

     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glPushMatrix();
     
     //COMECA A MATRIZ 1
     glPushMatrix();
     //ROTACIONA O CUBO VERDE
     glRotatef(ang_verde,0,1,0);
     //DESENHA O CUBO VERDE
     glTranslatef(20,0,-40);
     glColor3f(0,1,0);
     glutSolidCube(40.0);
     //TERMINA A MATRIZ 2
     glPopMatrix();
     


}

void Desenha (void)
{
     glClear(GL_COLOR_BUFFER_BIT);
     glViewport(0,0,400,400);
     DesenhaQuadro();
     //glFlush(); //TROCADA POR GLUTSWAPBUFFERS
     glutSwapBuffers();//PARA ALTERANR ENTRE OS DOIS BUFFERS
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
    gluOrtho2D (-win, win, -win, win);
    glutPostRedisplay();
}

void Teclado (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

void Inicializa (void)
{
       win = 10.0;
       glClearColor(0.0,0.0,0.0,1.0);
       glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       gluOrtho2D(-win,win,-win,win);       
}

void Anima (int)
{
     if (deslocaX > 20)
     {
     deslocaX = -10;
     }
     
     deslocaX += 1;
     glutPostRedisplay();
     glutTimerFunc(150,Anima,1);//CARREGA A FUNCAO ANIMA A CADA 150 CENTESIMOS DE SEGUNDO
}

int main(void)
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // DEFINE O USO DE DOIS BUFFERS
    glutInitWindowSize(400,400);
    glutInitWindowPosition(0,0);
    glutCreateWindow("teste");
    Inicializa();
    glutDisplayFunc(Desenha);
	glutSpecialFunc(TeclasEspeciais);
	glutKeyboardFunc (Teclado);
    Anima(1); //CARREGA A FUNCAO ANIMA
    glutMainLoop();
}
