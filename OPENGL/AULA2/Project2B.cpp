#include <GL/glut.h>
//2 VIEWPORTS

void DesenhaQuadro(void) //MUDOU O NOME DA FUNCAO QUE SERA EXECUTADA DUAS VEZES
{
//GLCLEAR VAI PARA A DESENHA (do contrario elimina o primeiro desenho quando faz o segundo)
//A VIEWPORT VAI PARA A DESENHA E E EXECUTADA DUAS VEZES     
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
     //FLUSH VAI PARA A FUNCAO DESENHA
}

void Desenha (void)
{
     glClear(GL_COLOR_BUFFER_BIT);//LIMPA A JANELA APENAS UMA VEZ 
     glViewport(0,200,200,200);   //MUDOU A VIEW PORT 200X0 E 200 X 200 (METADE DO TAMANHO)
     DesenhaQuadro();             //DESENHA O QUADRO SELECIONADO PELA ORTHO2D
     glViewport(100,0,400,400);   //MUDOU A VIEW PORT 200X0 E 400 X 400 (TAMANHO ORIGINAL)
     DesenhaQuadro();             //DESENHA NOVAMENTE O QUADRO SELECIONADO PELA ORTHO2D
     glFlush();
}     

void Inicializa (void)
{
       glClearColor(0.0,0.0,0.0,1.0);
       gluOrtho2D(-10.0,10.0,-10.0,10.0);
         
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
