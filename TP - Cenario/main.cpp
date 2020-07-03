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
bool chave, valor = true, desativaLuz = false, dia = true;
GLfloat RedCeu = 0.3, GreenCeu = 0.7, BlueCeu = 1, Eixo = 200, EixoY = 0, EixoZ = 30;
GLfloat vermelhoLua = 1, verdeLua = 1, azulLua = 0;

GLUquadricObj *quadratic;

drawHouses *OneBuilding;

GLfloat luzDifusa[2][4]={
    {1.0,1.0,1.0,1.0},
    {1.0,1.0,1.0,1.0}
};// "cor"

GLfloat luzEspecular[2][4]={
    {1.0, 1.0, 1.0, 1.0},
    {1.0, 1.0, 1.0, 1.0}
}; // "brilho"

GLfloat DirecaoDaLuz[3] = {0, -1, 0};

GLfloat especularidade[2][4]={
    {0.5, 0.5, 0.5, 1.0},
    {0.0, 0.0, 0.0, 1.0}
};


void DefineIluminacao (void)
{

    GLfloat posicaoLuz[3][4]={
        { 45, 27, 21.5, 1.0},
        {-30, 27, 21.5, 1.0},
        {Eixo, EixoY, EixoZ, 0.0}
    };

	GLfloat luzAmbiente[4]={0.4, 0.4, 0.4, 1.0};

	// Capacidade de brilho do material
    GLint especMaterial = 2;

    // Define a concentração do brilho
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    glLightfv(GL_LIGHT3, GL_AMBIENT, luzAmbiente);

    for(int i = 0; i < 3; i++){

        if(i != 2){

            glLightfv(GL_LIGHT0+i, GL_DIFFUSE, luzDifusa[i]);
            glLightfv(GL_LIGHT0+i, GL_SPECULAR, luzEspecular[i]);
            glLightfv(GL_LIGHT0+i, GL_POSITION, posicaoLuz[i]);
            glLightfv(GL_LIGHT0+i, GL_SPOT_DIRECTION,DirecaoDaLuz);
            glLightf (GL_LIGHT0+i,  GL_SPOT_CUTOFF,50.0);
            glLightf (GL_LIGHT0+i,GL_SPOT_EXPONENT,5.0);

        }else{

            glLightfv(GL_LIGHT0+i, GL_DIFFUSE, luzDifusa[i]);
            glLightfv(GL_LIGHT0+i, GL_SPECULAR, luzEspecular[i]);
            glLightfv(GL_LIGHT0+i, GL_POSITION, posicaoLuz[i]);

        }

    }
}


void Animation(int value){


    if(chave == false){

        if(valor == false){

            RedCeu = 0.0;
            GreenCeu = 0.0;
            BlueCeu =  0.10;
            vermelhoLua =  0.658824;
            verdeLua = 0.658824;
            azulLua = 0.658824;

            // Define a refletância do material
            glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade[0]);

            glDisable(GL_LIGHT2);
            glEnable(GL_LIGHT0);
            glEnable(GL_LIGHT1);

            dia = false;

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

            // Define a refletância do material
            glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade[1]);

            glEnable(GL_LIGHT2);
            glDisable(GL_LIGHT0);
            glDisable(GL_LIGHT1);

            dia = true;

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

        glutTimerFunc(41,Animation,1);

    }

    glutPostRedisplay();

}


void Desenha(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glClearColor(RedCeu, GreenCeu, BlueCeu, 1.0f);

	quadratic = gluNewQuadric();

    glPushMatrix();

        if(desativaLuz == false){

            if(dia == true){


                glDisable(GL_LIGHT2);

                desativaLuz = true;

            }

        }

        glPushMatrix();
            glTranslatef(Eixo, EixoY, EixoZ);
            glColor3f(vermelhoLua, verdeLua, azulLua);
            OneBuilding->drawSun();
        glPopMatrix();

        if(desativaLuz == true){

            if(dia == true){


                glEnable(GL_LIGHT2);

                desativaLuz = false;

            }

        }

        DefineIluminacao();

        glPushMatrix();
            glScalef(1.2, 1.0, 1.0);
            glTranslatef(11.6, 0, 0);
            OneBuilding -> drawFloor();
        glPopMatrix();

        glPushMatrix();
            OneBuilding -> drawTree();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(78, 0, 0);
            OneBuilding -> drawTree();
        glPopMatrix();

//---------Chão do outro Lado da Rua-----------------

    glPushMatrix();
        glRotatef(180, 0, 1, 0);
        glTranslatef(-27.8, 0, -60);
        glPushMatrix();
            glScalef(1.2, 1.0, 1.0);
            glTranslatef(11.6, 0, 0);
            OneBuilding -> drawFloor();
        glPopMatrix();

        glPushMatrix();
            OneBuilding -> drawTree();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(78, 0, 0);
            OneBuilding -> drawTree();
        glPopMatrix();
    glPopMatrix();

//---------------------------------------------------

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
            glPushMatrix();
                glScalef(1.2, 1.0, 1.0);
                glTranslatef(11.6, 0, 0);
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(45, 15, 13.6);
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
    // Para previnir uma divisão por zero
    if ( h == 0 )
        h = 1;

        largura = w;
        altura = h;

    // Especifica as dimensões da viewport
    glViewport(0, 0, w, h);

    fAspect = (GLfloat)w/(GLfloat)h;

    EspecificaParametrosVisualizacao();
}


void GerenciaMouse(int button, int state, int x, int y)
{
	if(state==GLUT_DOWN)
	{
		// Salva os parâmetros atuais
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
	// Botão esquerdo ?
	if(bot==GLUT_LEFT_BUTTON)
	{
		// Calcula diferenças
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica ângulos
		rotY = rotY_ini - deltax/SENS_ROT;
		rotX = rotX_ini - deltay/SENS_ROT;
	}
	// Botão direito ?
	else if(bot==GLUT_RIGHT_BUTTON)
	{
		// Calcula diferença
		int deltaz = y_ini - y;
		// E modifica distância do observador
		obsZ = obsZ_ini + deltaz/SENS_OBS;
	}
	// Botão do meio ?
	else if(bot==GLUT_MIDDLE_BUTTON)
	{
		// Calcula diferenças
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica posições
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

	glEnable(GL_LIGHT2);

	glEnable(GL_LIGHT3);

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
