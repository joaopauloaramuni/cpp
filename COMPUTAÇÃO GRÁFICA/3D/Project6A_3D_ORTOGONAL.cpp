#include<GL/glut.h>

void Desenha (void)
{     
      glClear(GL_COLOR_BUFFER_BIT);
      glColor3f(1.0,1.0,1.0);
      glBegin(GL_TRIANGLES);
         glVertex2f(-40.0f,-40.0f);
         glVertex2f(0.0f,40.0f);
         glVertex2f(40.0f,-40.0f);
      glEnd();
     
     glColor3f(1.0,0.0,0.0);
     //DESENHA O CUBO DE -20 A 20 (EM X, Y, Z)
     glutWireCube(40.0);
     
     glFlush();
}

void especificaParametrosVisualizacao (void)
{
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();

     // ESPECIFICA A PROJECAO ORTOGONAL - ENTRE O ESPACO EM Z (ZMIN E ZMAX)
     //glOrtho (xMIN, xMAX, yMIN, YMAX, ZMIN, ZMAX)
     glOrtho(-65,65,-65,65,-400,400);
     
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     //POSICAO DO OBSERVADOR (X,Y,Z), DO ALVO (X,Y,Z) E DIRECAO DO VETOR UP (PARA X, PARA Y, PARA Z)
     gluLookAt(60,60,100,0,0,0,0,1,0); 
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
    glutCreateWindow("Teste_3D");
    glutDisplayFunc(Desenha);
    especificaParametrosVisualizacao();
    Inicializa();
    glutMainLoop();
}
