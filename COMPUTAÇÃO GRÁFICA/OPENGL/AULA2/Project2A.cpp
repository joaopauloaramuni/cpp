#include <GL/glut.h>
//JANELA DE SELECAO E JANELA DE APRESENTACAO

void Desenha(void)
{
     glClear(GL_COLOR_BUFFER_BIT);
     
     glViewport(0,0,800,800);   //CANTO INFERIOR ESQUERDO DA AEREA SELECIONADA EM 0,0
                                // = CANTO INFERIOR ESQUERDO DA TELA;
                                //LARGURA E ALTURA DA SELECAO = 800 X 800 (DOBRO DO TAMANHO)
     
     glColor3f(1.0,1.0,1.0);
     glBegin(GL_QUADS);
         glVertex2f(-0.8,0.8);
         glVertex2f(0.8,0.8);
         glVertex2f(0.8,-0.8);
         glVertex2f(-0.8,-0.8);
     glEnd();
     
     glColor3f(1.0,0.0,0.0);
     glBegin(GL_TRIANGLES);
         glVertex2f(-0.6,-0.6);
         glVertex2f(0.0,0.6);
         glVertex2f(0.6,-0.6);
     glEnd();
     
     glColor3f(0.0,1.0,0.0);
     glBegin(GL_POLYGON);
         glVertex2f(-0.6,-0.4);
         glVertex2f(0.0,-0.3);
         glVertex2f(0.6,-0.4);
         glVertex2f(0.6,-0.6);
         glVertex2f(-0.6,-0.6);
     glEnd();
     
     glColor3f(0.0,0.0,1.0);
     glLineWidth(2.0);  
     glBegin(GL_LINES);
         glVertex2f(-1.0,1.0);
         glVertex2f(1.0,-1.0);
     glEnd();
     glFlush();
}

void Inicializa (void)
{
       glClearColor(0.0,0.0,0.0,1.0);
       gluOrtho2D(-10.0,10.0,-10.0,10.0); //REDEFINE SELECAO PARA 20 X 20 (REDUZ 10 VEZES)
         
}

int main(void)
{
    glutInitWindowSize(400,400);
    glutInitWindowPosition(0,0);
    glutCreateWindow("teste");
    Inicializa();
    glutDisplayFunc(Desenha);
    glutMainLoop();
}
