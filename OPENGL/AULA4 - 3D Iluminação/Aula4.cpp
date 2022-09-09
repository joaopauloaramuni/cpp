#include<GL/glut.h>

GLfloat angulo = 0;//DEFINE O DESLOCAMENTO TOAL EM X
GLfloat ang_esf = 360.0f;
GLfloat ang_verde = 0;

//DEFINEILUMINACAO
void DefineIluminacao (void) {
     GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
     //cor da luz ambiente (RGB,Alpha)
     GLfloat luzEspecular[4]={1.0,1.0,1.0,1.0};
     GLfloat posicaoLuz[4]={0.0,50.0,150.0,1.00};
     //sera a posicao da luz zero: {x,y,z,w}
     //w=0 - dereciona e w<>0
     //Ativa o uso da luz ambiente (modelo de luz)
     glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

     //Define os parâmetros da luz de número 0
     glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
     glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
     glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);
}

//DESENHA
void Desenha (void)
{
     //Inicializa os buffers cor e profundidade
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     DefineIluminacao();

     //COMECA A MATRIZ 1
     glPushMatrix();
     //ROTACIONA O CUBO VERMELHO E TRIANGULO
     glRotatef(angulo,0,1,0);
     //DESENHA O TRIANGULO BRANCO
     glColor3f(1.0,1.0,1.0);
     glBegin(GL_TRIANGLES);
        glVertex2f(-40.0f,-40.0f);
        glVertex2f(0.0f,40.0f);
        glVertex2f(40.0f,-40.0f);
     glEnd();
     glColor3f(1.0,0.0,0.0);
     glutSolidCube(40.0);
     //TERMINA A MATRIZ 1
     glPopMatrix();

     //COMECA A MATRIZ 2
     glPushMatrix();
     //ROTACIONA O CUBO VERDE
     glRotatef(ang_verde,0,1,0);
     //DESENHA O CUBO VERDE
     glTranslatef(20,0,-40);
     glColor3f(0,1,0);
     glutSolidCube(40.0);
     //TERMINA A MATRIZ 2
     glPopMatrix();

     //COMECA A MATRIZ 3
     glPushMatrix();
     //ROTACIONA A ESFERA
     glRotatef(ang_esf,0,1,0);
     glTranslatef(-40,0,80);
     glColor3f(0,0,1);
     glutSolidSphere(15,50,50);
     //TERMINA A MATRIZ 3
     glPopMatrix();

     //Manda desenhar
     glFlush();
}

//ESPECIFICAPARAMETROSVISUALIZACAO
void especificaParametrosVisualizacao (void)
{
     glMatrixMode(GL_PROJECTION);

     glLoadIdentity();
     gluPerspective(70,1,10,400);
     glMatrixMode(GL_MODELVIEW);

     glLoadIdentity();
     gluLookAt(100,100,200,0,0,0,0,1,0); 
     glEnable(GL_DEPTH_TEST);
}

//INICIALIZA
void Inicializa (void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	angulo = 0.0f;
	ang_esf = 360.0f;
	ang_verde = 0;

	//Habilita a cor do material
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);
	//Habilita a luz de numero 0
	glEnable(GL_LIGHT0);
	//Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);
}

//ANIMA
void Anima (int)
{
     if (angulo > 360.0f)
          angulo = 0.0f;
     angulo += 10;

     if (ang_esf < 0.0f)
          ang_esf = 360.0f;
     ang_esf -= 10;

     if (ang_verde > 360.0f)
          ang_verde = 0.0f;
     ang_verde += 10;

     glutPostRedisplay();
     glutTimerFunc(150,Anima,1);//CARREGA A FUNCAO ANIMA A CADA 150 CENTESIMOS DE SEGUNDO
}

//MAIN
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
