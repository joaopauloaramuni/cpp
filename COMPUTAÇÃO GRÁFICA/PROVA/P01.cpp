#include<GL/glut.h>

GLfloat deslocaVerde = 60;
GLfloat deslocaVerm = 60;
GLfloat deslocaAzul = -60;

int controleVerde = 0;
int controleVerm = 0;
int controleAzul = 0;

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
     //DESENHA O CUBO VERDE
     glTranslatef(deslocaVerde,0,0); //O DESLOCAMENTO EM X VERDE
     glColor3f(0,1,0);
     glutSolidCube(20.0);
     //TERMINA A MATRIZ 2
     glPopMatrix();
     
     //COMECA A MATRIZ 2
     glPushMatrix();
     //DESENHA O CUBO VERMELHO
     glTranslatef(0,deslocaVerm,0); //O DESLOCAMENTO EM X VERMELHO
     glColor3f(1,0,0);
     glutSolidCube(20.0);
     //TERMINA A MATRIZ 2
     glPopMatrix();
     
     //COMECA A MATRIZ 3
     glPushMatrix();
     //DESENHA O CUBO AZUL 
     glTranslatef(0,0,deslocaAzul); //O DESLOCAMENTO EM X AZUL
     glColor3f(0,0,1);
     glutSolidCube(20.0);
     //TERMINA A MATRIZ 2
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
     gluLookAt(0,-10,100,0,0,0,0,1,0); 
     glEnable(GL_DEPTH_TEST);
}

//INICIALIZA
void Inicializa (void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
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
     //DESLOCA VERDE IDA E VOLTA
     if(deslocaVerde == -60){
     controleVerde = 0;            
     }else if(deslocaVerde == 60) {
     controleVerde = 1;      
     }
     
     if(deslocaVerde >= -60 && controleVerde == 0){
     deslocaVerde += 3;                
     }
     if(deslocaVerde <= 60 && controleVerde == 1){
     deslocaVerde -= 3;             
     }
     
     //DESLOCA VERMELHO IDA E VOLTA
     if(deslocaVerm == 60){
     controleVerm = 0;            
     }else if(deslocaVerm == -60) {
     controleVerm = 1;      
     }
     
     if(deslocaVerm <= 60 && controleVerm == 0){
     deslocaVerm -= 4;                
     }
     if(deslocaVerm >= -60 && controleVerm == 1){
     deslocaVerm += 4;             
     }
     
     //DESLOCA AZUL IDA E VOLTA
     if(deslocaAzul == -60){
     controleAzul = 0;            
     }else if(deslocaAzul == 60) {
     controleAzul = 1;      
     }
     
     if(deslocaAzul >= -60 && controleAzul == 0){
     deslocaAzul += 5;                
     }
     if(deslocaAzul <= 60 && controleAzul == 1){
     deslocaAzul -= 5;             
     }

     glutPostRedisplay();
     glutTimerFunc(150,Anima,1);//CARREGA A FUNCAO ANIMA A CADA 150 CENTESIMOS DE SEGUNDO
     
}

//MAIN
int main (void)
{
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Prova - 6DA - Joao Paulo Aramuni");
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutDisplayFunc(Desenha);
    especificaParametrosVisualizacao();
    Anima(1); //CARREGA A FUNCAO ANIMA
    Inicializa();
    glutMainLoop();
}
