#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "drawHouses.h"

GLsizei largura, altura;
GLfloat angle, fAspect;
GLfloat rotX, rotY, rotX_ini, rotY_ini;
GLfloat obsX, obsY, obsZ, obsX_ini, obsY_ini, obsZ_ini;
GLsizei  moveX = 0, moveY = 0, moveZ = 100;
int x_ini,y_ini,bot, win = 40, panAxleX = 0, panAxleY = 0, panAxleZ = 0;
int panObjectX = 0, panObjectY = 0, panObjectZ = 0;
bool chave, valor = true;
GLfloat RedCeu = 0.3, GreenCeu = 0.7, BlueCeu = 1, Eixo = 200, EixoY = 0, EixoZ = 30;
GLfloat vermelhoLua = 1, verdeLua = 1, azulLua = 0;

GLUquadricObj *quadratic;

drawHouses *OneBuilding;

GLfloat luzDifusa[4]={1,1,1,1};// "cor"

GLfloat luzEspecular[4]={1,1,1,1}; // "brilho"

GLfloat posicaoLuz[2][4]={
    { 60, 27, 21.5, 1},
    {-30, 27, 21.5, 1}
};

GLfloat DirecaoDaLuz[3] = {0, -1, 0};

void DefineIluminacao (void)
{
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1,1,1,1.0};
	GLint especMaterial = 90;

	// Define a reflet�ncia do material
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentra��o do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    glLightfv(GL_LIGHT2, GL_AMBIENT, luzAmbiente);

    for(int i = 0; i < 2; i++){

        glLightfv(GL_LIGHT0+i, GL_DIFFUSE, luzDifusa);
        glLightfv(GL_LIGHT0+i, GL_SPECULAR, luzEspecular);
        glLightfv(GL_LIGHT0+i, GL_POSITION, posicaoLuz[i]);
        glLightfv(GL_LIGHT0+i,GL_SPOT_DIRECTION,DirecaoDaLuz);
        glLightf(GL_LIGHT0+i,GL_SPOT_CUTOFF,30.0);
        glLightf(GL_LIGHT0+i,GL_SPOT_EXPONENT,91.0);

    }
}


void Animation(int value){glPopMatrix();


    if(chave == false){

        if(valor == false){

            RedCeu = 0.0;
            GreenCeu = 0.0;
            BlueCeu =  0.10;
            vermelhoLua =  0.658824;
            verdeLua = 0.658824;
            azulLua = 0.658824;

            Eixo = 200.0;
            EixoY = 0.0;

        }else
        {

            RedCeu = 0.3;
            GreenCeu = 0.7;
            BlueCeu =  1.0;
            vermelhoLua =  1.0;
            verdeLua = 1.0;
            azulLua = 0.0;

            Eixo = 200.0;
            EixoY = 0.0;

        }

        chave = true;


    }else{

            if(!(Eixo <= -170.0)){

                if(Eixo > -5.0 && Eixo <= 50.0){

                    Eixo -= 0.25;
                    EixoY -= 0.015;


                }
                else if(Eixo <= -5.0){

                    Eixo -= 0.5;
                    EixoY -= 0.2;

                }else{

                    Eixo -= 0.5;
                    EixoY += 0.2;

                }

            }
            else
            {

                valor = !valor;

                chave = false;

            }

    }

        glutPostRedisplay();
        glutTimerFunc(41,Animation,1);

}


void Desenha(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    DefineIluminacao();

    glClearColor(RedCeu, GreenCeu, BlueCeu, 1.0f);

	quadratic = gluNewQuadric();

    glPushMatrix();

        glPushMatrix();
            glTranslatef(Eixo, EixoY, EixoZ);
            glColor3f(vermelhoLua, verdeLua, azulLua);
            OneBuilding->drawSun();
        glPopMatrix();

        glPushMatrix();
            glScalef(1.2, 1.0, 1.0);
            glTranslatef(11.6, 0, 0);
            OneBuilding -> drawFloor();
        glPopMatrix();

        glPushMatrix();
            OneBuilding -> drawTree();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(73, 0, 0);
            OneBuilding -> drawTree();
        glPopMatrix();

        glPushMatrix();
         glColor3f(0.5, 0.5, 0.5);
         glScalef(1.0, 1.2, 1.0);
         OneBuilding -> draw();
        glPopMatrix();

        glPushMatrix();
         glTranslatef(30, 0, 0);
         glColor3f(0.8, 0.3, 0.5);
         OneBuilding -> draw();
        glPopMatrix();

        glPushMatrix();
         glTranslatef(76, 0, 0);
         glScalef(0.8, 1.0, 1.0);
         glColor3f(0.0, 0.0, 1.0);
         OneBuilding -> draw();
        glPopMatrix();

        glPushMatrix();
            glScalef(1.2, 1.0, 1.0);
            glTranslatef(11.6, 0, 0);
            OneBuilding -> drawStreet();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(60, 15, 13.6);
            OneBuilding -> drawPoste();
            glPushMatrix();
                glTranslatef(0, 12, 1.0);
                glScalef(0.5, 0.5, 2);
                glColor3f(0.35, 0.35, 0.35);
                gluCylinder(quadratic, 1.0, 1, 3, 30, 30);
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-30, 15, 13.6);
            OneBuilding -> drawPoste();
            glPushMatrix();
                glTranslatef(0, 12, 1.0);
                glScalef(0.5, 0.5, 2);
                glColor3f(0.35, 0.35, 0.35);
                gluCylinder(quadratic, 1.0, 1, 3, 30, 30);
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();

}


void PosicionaObservador(void)
{
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	// Posiciona e orienta o observador
	glTranslatef(-obsX,-obsY,-obsZ);
	glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);
}


void EspecificaParametrosVisualizacao(void)
{

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(win,fAspect,0.5,5000);

    PosicionaObservador();
}


void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Para previnir uma divis�o por zero
    if ( h == 0 )
        h = 1;

        largura = w;
        altura = h;

    // Especifica as dimens�es da viewport
    glViewport(0, 0, w, h);

    fAspect = (GLfloat)w/(GLfloat)h;

    EspecificaParametrosVisualizacao();
}


void GerenciaMouse(int button, int state, int x, int y)
{
	if(state==GLUT_DOWN)
	{
		// Salva os par�metros atuais
		x_ini = x;
		y_ini = y;
		obsX_ini = obsX;
		obsY_ini = obsY;
		obsZ_ini = obsZ;
		rotX_ini = rotX;
		rotY_ini = rotY;
		bot = button;
	}
	else bot = -1;
}


#define SENS_ROT	20.0
#define SENS_OBS	20.0
#define SENS_TRANSL	20.0
void GerenciaMovim(int x, int y)
{
	// Bot�o esquerdo ?
	if(bot==GLUT_LEFT_BUTTON)
	{
		// Calcula diferen�as
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica �ngulos
		rotY = rotY_ini - deltax/SENS_ROT;
		rotX = rotX_ini - deltay/SENS_ROT;
	}
	// Bot�o direito ?
	else if(bot==GLUT_RIGHT_BUTTON)
	{
		// Calcula diferen�a
		int deltaz = y_ini - y;
		// E modifica dist�ncia do observador
		obsZ = obsZ_ini + deltaz/SENS_OBS;
	}
	// Bot�o do meio ?
	else if(bot==GLUT_MIDDLE_BUTTON)
	{
		// Calcula diferen�as
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica posi��es
		obsX = obsX_ini + deltax/SENS_TRANSL;
		obsY = obsY_ini - deltay/SENS_TRANSL;
	}
	PosicionaObservador();
	glutPostRedisplay();
}


void TeclaEspecial(int key, int x, int y){

    if(key == GLUT_KEY_HOME){

            chave = true;

            glutTimerFunc(41,Animation, 1);

    }

}


void Teclado (unsigned char key, int x, int y)
{
    if (key == 27)//Tecla Esc
        exit(0);

    if(key == 102)//Tecla F
        glutFullScreen();

    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}


void Inicializa (void)
{

    glClearColor(RedCeu, GreenCeu, BlueCeu, 1.0f);
    glLineWidth(2.0);

    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);

	glEnable(GL_LIGHT1);

	glEnable(GL_LIGHT2);

    glEnable(GL_DEPTH_TEST);

    glShadeModel(GL_SMOOTH);

	angle=45;

	rotX = 0;
	rotY = 0;
	obsX = obsY = 0;
	obsZ = 150;

    OneBuilding = new drawHouses();

}


int main(void)
{

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(300,100);

    glutInitWindowSize(1280, 720);

    glutCreateWindow("Desenho de uma Maquete");

    Inicializa();

    glutDisplayFunc(Desenha);

    glutReshapeFunc(AlteraTamanhoJanela);

    glutKeyboardFunc(Teclado);

    glutSpecialFunc(TeclaEspecial);

	glutMouseFunc(GerenciaMouse);

	glutMotionFunc(GerenciaMovim);

    glutMainLoop();

    return 0;
}
