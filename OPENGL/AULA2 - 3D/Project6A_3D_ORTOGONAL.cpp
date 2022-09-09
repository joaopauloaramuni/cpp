#include<GL/glut.h>

void Desenha (void)
{     
      //Inicializa os buffers cor e profundidade
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glTranslatef(0.0,0.0,0.0);
      glColor3f(1.0,1.0,1.0);
      glBegin(GL_TRIANGLES);
         glVertex2f(-40.0f,-40.0f);
         glVertex2f(0.0f,40.0f);
         glVertex2f(40.0f,-40.0f);
      glEnd();
     
     glTranslatef(0.0,0.0,0.0);
     glColor3f(1.0,0.0,0.0);
     //solid para preencher o cubo vermelho
     glutSolidCube(40.0);
     //DESENHA O CUBO DE -20 A 20 (EM X, Y, Z)
     //glutWireCube(40.0);
     
     //CUBO PREENCHIDO VERDE
     glTranslatef(20,0,-40);
     glColor3f(0,1,0);
     //solid para preencher o cubo vermelho
     glutSolidCube(40.0);
     
     //ESFERA PREECHIDA AZUL
     glTranslatef(-40,0,80);
     glColor3f(0,0,1);
     glutSolidSphere(15,50,50);
     
     //Dodecategrado
     glTranslatef(40,0,80);
     glColor3f(1,0,0);
     glutSolidDodecahedron();
     glFlush();
}

void especificaParametrosVisualizacao (void)
{
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();

     // ESPECIFICA A PROJECAO ORTOGONAL - ENTRE O ESPACO EM Z (ZMIN E ZMAX)
     //glOrtho (xMIN, xMAX, yMIN, YMAX, ZMIN, ZMAX)
     //glOrtho(-65,65,-65,65,-400,400);
     
     gluPerspective(80,1,20,300);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     //POSICAO DO OBSERVADOR (X,Y,Z), DO ALVO (X,Y,Z) E DIRECAO DO VETOR UP (PARA X, PARA Y, PARA Z)
     gluLookAt(0,0,100,0,0,0,0,1,0); 
     glEnable(GL_DEPTH_TEST);
}

void Inicializa (void)
{   
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int main (void)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(400,400);
    glutCreateWindow("Teste_3D - Rafael Lott");
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutDisplayFunc(Desenha);
    especificaParametrosVisualizacao();
    Inicializa();
    glutMainLoop();
}
