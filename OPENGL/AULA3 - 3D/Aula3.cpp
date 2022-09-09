#include<GL/glut.h>

GLfloat angulo = 0;//DEFINE O DESLOCAMENTO TOAL EM X
GLfloat ang_esf = 360.0f;

void Desenha (void)
{
      //Inicializa os buffers cor e profundidade
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      //*****COMEÇA A 1 MATRIX
      glPushMatrix();
      glRotatef(angulo,0,1,0);

      glColor3f(1.0,1.0,1.0);
      glBegin(GL_TRIANGLES);
         glVertex2f(-40.0f,-40.0f);
         glVertex2f(0.0f,40.0f);
         glVertex2f(40.0f,-40.0f);
      glEnd();

     glColor3f(1.0,0.0,0.0);
     //solid para preencher o cubo vermelho
     glutSolidCube(40.0);

     //CUBO PREENCHIDO VERDE
     glTranslatef(20,0,-40);
     glColor3f(0,1,0);
     //solid para preencher o cubo vermelho
     glutSolidCube(40.0);

     //TERMINA A MATRIX 1
     glPopMatrix();
     
     //COMECA A MATRIX 2
     glPushMatrix();

     //Rotaciona somente a esfera
     glRotatef(ang_esf,0,1,0);

     //ESFERA PREECHIDA AZUL
     glTranslatef(-40,0,80);
     glColor3f(0,0,1);
     glutSolidSphere(15,50,50);

     //TERMINA A MATRIZ 2
     glPopMatrix();

     //Manda desenhar
     glFlush();
}


void especificaParametrosVisualizacao (void)
{
     glMatrixMode(GL_PROJECTION);

     glLoadIdentity();
     gluPerspective(70,1,10,400);
     glMatrixMode(GL_MODELVIEW);

     glLoadIdentity();
     gluLookAt(0,200,0,0,0,0,1,0,0); 
     glEnable(GL_DEPTH_TEST);
}

void Inicializa (void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	angulo = 0.0f;
	ang_esf = 360.0f;
}

void Anima (int)
{
     if (angulo > 360.0f)
          angulo = 0.0f;
     angulo += 10;

     if (ang_esf < 0.0f)
          ang_esf = 360.0f;
     ang_esf -= 10;

     glutPostRedisplay();
     glutTimerFunc(150,Anima,1);//CARREGA A FUNCAO ANIMA A CADA 150 CENTESIMOS DE SEGUNDO
}

int main (void)
{
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Teste_3D - Rafael Lott");
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutDisplayFunc(Desenha);
    especificaParametrosVisualizacao();
    Anima(1); //CARREGA A FUNCAO ANIMA
    Inicializa();
    glutMainLoop();
}
