#include <GL/glut.h>
//Zoom

GLfloat win; // DECLARA A VARIAVEL QUE  CONTROLA A ORTHO 2D

void DesenhaQuadro(void)
{
     glColor3f(1.0,1.0,1.0);
     glBegin(GL_QUADS);
         glVertex2f(-8.0,8.0);
         glVertex2f(8.0,8.0);
         glVertex2f(8.0,-8.0);
         glVertex2f(-8.0,-8.0);
     glEnd();
     
     glColor3f(1.0,0.0,0.0);
     glBegin(GL_TRIANGLES);
         glVertex2f(-6.0,-6.0);
         glVertex2f(0.0,6.0);
         glVertex2f(6.0,-6.0);
     glEnd();
     
     glColor3f(0.0,1.0,0.0);
     glBegin(GL_POLYGON);
         glVertex2f(-6.0,-4.0);
         glVertex2f(0.0,-3.0);
         glVertex2f(6.0,-4.0);
         glVertex2f(6.0,-6.0);
         glVertex2f(-6.0,-6.0);
     glEnd();
     
     glColor3f(0.0,0.0,1.0);
     glLineWidth(2.0);  
     glBegin(GL_LINES);
         glVertex2f(-10.0,10.0);
         glVertex2f(10.0,-10.0);
     glEnd();
}

void Desenha (void)
{
     glClear(GL_COLOR_BUFFER_BIT);
     glViewport(0,0,400,400);   //MUDOU A VIEW PORT 0X0 E 400 X 400 (TAMANHO ORIGINAL)
     DesenhaQuadro();
                                //APENAS UM DESENHO
     glFlush();
}     


void TeclasEspeciais(int key, int x, int y) //FUNCAO QUE LE AS TECLAS E MUDA A ORTHO 2D
                                            //(JANELA DE SELECAO) PARA FAAZER O ZOOM
{
	if (key == GLUT_KEY_UP)//VERIFICA SE A TECLA PRESSIONADA FOI A UP
	{
		if (win > 0) //DEFINE O LIMITE MINIMO PARA A REDUCAO
			win -= 1.0f; // DIMINUI O TAMANHO DA JANELA DE SELECAO (ZOOM IN)
	}
	else if (key == GLUT_KEY_DOWN) //VERIFICA SE A TECLA PRESSIONADA FOI A DOWN
	{
		if (win < 900) //DEFINE O LIMITE MAXIMO PARA AMPLIACAO
			win += 1.0f; // AUMENTA O TAMANHO DA JANELA DE SELECAO (ZOOM OUT)
	}

    glMatrixMode(GL_PROJECTION); //DEFINE A MATRIZ A SER AJUSTADA (PROJECAO E NAO MODELO)
    glLoadIdentity();            //GRAVA A MATRIZ PADRAO
    gluOrtho2D (-win, win, -win, win);   //AJUSTA A MATRIZ
    glutPostRedisplay();   //REDESENHA
}

void Teclado (unsigned char key, int x, int y)    //FUNCAO QUE RODA QUANDO UMA TECLA QUALQUER E PRESSIONADA
{
	if (key == 27)     //TESTA QUAL A TECLA FOI PRESSIONADA
		exit(0);       //FECHA A JANELA
}

void Inicializa (void)
{
	   win = 10.0;//ATRIBUI O VALOR 10 PARA A VARIAVEL WIN
       glClearColor(0.0,0.0,0.0,1.0);
       glMatrixMode(GL_PROJECTION);//DEFINE A MATRIZ A SER AJUSTADA (PROJECAO E NAO MODELO)
       glLoadIdentity();//GRAVA A MATRIZ PADRAO
       gluOrtho2D(-win,win,-win,win); //AJUSTA A MATRIZ       
}

int main(void)
{
    glutInitWindowSize(400,400);
    glutInitWindowPosition(0,0);
    glutCreateWindow("teste");
    Inicializa();
    glutDisplayFunc(Desenha);
	glutSpecialFunc(TeclasEspeciais); // REGISTRA A FUNCAO CALLBACK PARA TRATAMENTO DAS TECLAS ESPECIAIS
	glutKeyboardFunc (Teclado); 	// REGISTRA A FUNCAO CALLBACK PARA TRATAMENTO DAS TECLAS ASCII
    glutMainLoop();
}
