#include "drawHouses.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>


void drawHouses::drawSun(){

    glutSolidSphere(5, 30, 30);

}


void drawHouses::drawBuilding(OBJ *objeto){


    for(int face = 0; face < objeto->TotalDeFaces; face++){

        glBegin(GL_POLYGON);

        for(int vert = 0; vert < objeto->faces[face].total; vert++){

                glVertex3f(objeto->vertices[objeto->faces[face].ind[vert]].x,
                           objeto->vertices[objeto->faces[face].ind[vert]].y,
                           objeto->vertices[objeto->faces[face].ind[vert]].z);

        }

        glEnd();

    }


}


void drawHouses::drawLineContour(OBJ *objeto){

    for(int face = 0; face < objeto->TotalDeFaces; face++){

        glColor3f(0, 0, 0);

        glBegin(GL_LINE_LOOP);

        for(int vert = 0; vert < objeto->faces[face].total; vert++){

                glVertex3f(objeto->vertices[objeto->faces[face].ind[vert]].x,
                           objeto->vertices[objeto->faces[face].ind[vert]].y,
                           objeto->vertices[objeto->faces[face].ind[vert]].z);

        }

        glEnd();

    }

}


void drawHouses::drawWindow(){

//Lado Esquerdo do Prédio---------------------------------------

    glPushMatrix();
        glRotatef(90, 0, 1, 0);
        glPushMatrix();
            glTranslatef(5, 25, 10.02);
            drawLineContour(&janela);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.74902, 0.847059, 0.847059);
            glTranslatef(5, 25, 10.02);
            drawBuilding(&vidro);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glRotatef(90, 0, 1, 0);
        glPushMatrix();
            glTranslatef(-5, 25, 10.02);
            drawLineContour(&janela);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.74902, 0.847059, 0.847059);
            glTranslatef(-5, 25, 10.02);
            drawBuilding(&vidro);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glRotatef(90, 0, 1, 0);
        glPushMatrix();
            glTranslatef(5, 15, 10.02);
            drawLineContour(&janela);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.74902, 0.847059, 0.847059);
            glTranslatef(5, 15, 10.02);
            drawBuilding(&vidro);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glRotatef(90, 0, 1, 0);
        glPushMatrix();
            glTranslatef(-5, 15, 10.02);
            drawLineContour(&janela);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.74902, 0.847059, 0.847059);
            glTranslatef(-5, 15, 10.02);
            drawBuilding(&vidro);
        glPopMatrix();
    glPopMatrix();

//Lado Direito do Prédio---------------------------------------

    glPushMatrix();
        glRotatef(-90, 0, 1, 0);
        glPushMatrix();
            glTranslatef(5, 25, 10.02);
            drawLineContour(&janela);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.74902, 0.847059, 0.847059);
            glTranslatef(5, 25, 10.02);
            drawBuilding(&vidro);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glRotatef(-90, 0, 1, 0);
        glPushMatrix();
            glTranslatef(-5, 25, 10.02);
            drawLineContour(&janela);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.74902, 0.847059, 0.847059);
            glTranslatef(-5, 25, 10.02);
            drawBuilding(&vidro);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glRotatef(-90, 0, 1, 0);
        glPushMatrix();
            glTranslatef(5, 15, 10.02);
            drawLineContour(&janela);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.74902, 0.847059, 0.847059);
            glTranslatef(5, 15, 10.02);
            drawBuilding(&vidro);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glRotatef(-90, 0, 1, 0);
        glPushMatrix();
            glTranslatef(-5, 15, 10.02);
            drawLineContour(&janela);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.74902, 0.847059, 0.847059);
            glTranslatef(-5, 15, 10.02);
            drawBuilding(&vidro);
        glPopMatrix();
    glPopMatrix();

}


void drawHouses::drawStreet()
{

	 glPushMatrix();
        glColor3f(0.4, 0.4, 0.4);
        glPushMatrix();
            glBegin(GL_QUAD_STRIP);

            glVertex3f(-60, -2, 15);
            glVertex3f(-60, -2, 45);

            glVertex3f(  0, -2, 15);
            glVertex3f(  0, -2, 45);

            glVertex3f( 60, -2, 15);
            glVertex3f( 60, -2, 45);
            glEnd();
        glPopMatrix();
    glPopMatrix();

//-------------------------------------------

    glPushMatrix();
        glBegin(GL_QUADS);
            glColor3f(1, 1, 0);

            glVertex3f(-57, -1.95, 29.5);
            glVertex3f(-57, -1.95, 30.5);
            glVertex3f(-54, -1.95, 30.5);
            glVertex3f(-54, -1.95, 29.5);

            glVertex3f(-49, -1.95, 29.5);
            glVertex3f(-49, -1.95, 30.5);
            glVertex3f(-46, -1.95, 30.5);
            glVertex3f(-46, -1.95, 29.5);

            glVertex3f(-41, -1.95, 29.5);
            glVertex3f(-41, -1.95, 30.5);
            glVertex3f(-38, -1.95, 30.5);
            glVertex3f(-38, -1.95, 29.5);

            glVertex3f(-33, -1.95, 29.5);
            glVertex3f(-33, -1.95, 30.5);
            glVertex3f(-30, -1.95, 30.5);
            glVertex3f(-30, -1.95, 29.5);

            glVertex3f(-25, -1.95, 29.5);
            glVertex3f(-25, -1.95, 30.5);
            glVertex3f(-22, -1.95, 30.5);
            glVertex3f(-22, -1.95, 29.5);

            glVertex3f(-17, -1.95, 29.5);
            glVertex3f(-17, -1.95, 30.5);
            glVertex3f(-14, -1.95, 30.5);
            glVertex3f(-14, -1.95, 29.5);

            glVertex3f(-9, -1.95, 29.5);
            glVertex3f(-9, -1.95, 30.5);
            glVertex3f(-6, -1.95, 30.5);
            glVertex3f(-6, -1.95, 29.5);

            glVertex3f(-1, -1.95, 29.5);
            glVertex3f(-1, -1.95, 30.5);
            glVertex3f( 2, -1.95, 30.5);
            glVertex3f( 2, -1.95, 29.5);

            glVertex3f( 7, -1.95, 29.5);
            glVertex3f( 7, -1.95, 30.5);
            glVertex3f(10, -1.95, 30.5);
            glVertex3f(10, -1.95, 29.5);

            glVertex3f(15, -1.95, 29.5);
            glVertex3f(15, -1.95, 30.5);
            glVertex3f(18, -1.95, 30.5);
            glVertex3f(18, -1.95, 29.5);

            glVertex3f(23, -1.95, 29.5);
            glVertex3f(23, -1.95, 30.5);
            glVertex3f(26, -1.95, 30.5);
            glVertex3f(26, -1.95, 29.5);

            glVertex3f(31, -1.95, 29.5);
            glVertex3f(31, -1.95, 30.5);
            glVertex3f(34, -1.95, 30.5);
            glVertex3f(34, -1.95, 29.5);

            glVertex3f(39, -1.95, 29.5);
            glVertex3f(39, -1.95, 30.5);
            glVertex3f(42, -1.95, 30.5);
            glVertex3f(42, -1.95, 29.5);

            glVertex3f(47, -1.95, 29.5);
            glVertex3f(47, -1.95, 30.5);
            glVertex3f(50, -1.95, 30.5);
            glVertex3f(50, -1.95, 29.5);

            glVertex3f(55, -1.95, 29.5);
            glVertex3f(55, -1.95, 30.5);
            glVertex3f(58, -1.95, 30.5);
            glVertex3f(58, -1.95, 29.5);
        glEnd();
    glPopMatrix();



}


void drawHouses::drawFloor()
{

    glNormal3f(1,1,1);

	 glPushMatrix();
        glBegin(GL_QUADS);
            glColor3f(0.2, 0.2, 0.2); //Desenha passeio
            glVertex3f(-60, -2, 10);
            glVertex3f(-60, -2, 15);
            glVertex3f( 60, -2, 15);
            glVertex3f( 60, -2, 10);

            glVertex3f(-60, -2, 10);
            glVertex3f(-60,  0, 10);
            glVertex3f( 60,  0, 10);
            glVertex3f( 60, -2, 10);

            glVertex3f(-60, -2, 10);
            glVertex3f(-60, -2, 15);
            glVertex3f(-60,  0, 15);
            glVertex3f(-60,  0, 10);

            glVertex3f(-60, -2, 15);
            glVertex3f( 60, -2, 15);
            glVertex3f( 60,  0, 15);
            glVertex3f(-60,  0, 15);

            glVertex3f( 60, -2, 10);
            glVertex3f( 60,  0, 10);
            glVertex3f( 60,  0, 15);
            glVertex3f( 60, -2, 15);

            glVertex3f(-60,  0, 10);
            glVertex3f(-60,  0, 15);
            glVertex3f( 60,  0, 15);
            glVertex3f( 60,  0, 10);
        glEnd();
    glPopMatrix();

//----------------------------------------------

    glPushMatrix();
        glBegin(GL_QUADS);
            glColor3f(0.36, 0.25, 0.20); //Desenha terreno do prédio
            glVertex3f(-60, -2,-15);
            glVertex3f(-60, -2, 10);
            glVertex3f( 60, -2, 10);
            glVertex3f( 60, -2,-15);

            glVertex3f(-60, -2,-15);
            glVertex3f(-60,  0,-15);
            glVertex3f( 60,  0,-15);
            glVertex3f( 60, -2,-15);

            glVertex3f(-60, -2,-15);
            glVertex3f(-60, -2, 10);
            glVertex3f(-60,  0, 10);
            glVertex3f(-60,  0,-15);

            glVertex3f(-60, -2, 10);
            glVertex3f( 60, -2, 10);
            glVertex3f( 60,  0, 10);
            glVertex3f(-60,  0, 10);

            glVertex3f( 60, -2,-15);
            glVertex3f( 60,  0,-15);
            glVertex3f( 60,  0, 10);
            glVertex3f( 60, -2, 10);

            glPushMatrix();
                glColor3f(0.184314, 0.309804, 0.184314);
                glVertex3f(-60,  0,-15);
                glVertex3f(-60,  0, 10);
                glVertex3f( 60,  0, 10);
                glVertex3f( 60,  0,-15);
            glPopMatrix();
        glEnd();
     glPopMatrix();

//------------------------------------------------------------

	/*glBegin(GL_LINE_LOOP); //linhas de contorno

	 glPushMatrix();

            glColor3f(0, 0, 0);
            glVertex3f(-60, -2, 10);
            glVertex3f(-60, -2, 15);
            glVertex3f( 60, -2, 15);
            glVertex3f( 60, -2, 10);

            glVertex3f(-60, -2, 10);
            glVertex3f(-60,  0, 10);
            glVertex3f( 60,  0, 10);
            glVertex3f( 60, -2, 10);

            glVertex3f(-60, -2, 15);
            glVertex3f(-60,  0, 15);

            glVertex3f(-60, -2, 15);
            glVertex3f( 60, -2, 15);
            glVertex3f( 60,  0, 15);
            glVertex3f(-60,  0, 15);

            glVertex3f( 60, -2, 10);
            glVertex3f( 60,  0, 10);
            glVertex3f( 60,  0, 15);
            glVertex3f( 60, -2, 15);

            glVertex3f(-60,  0, 10);
            glVertex3f(-60,  0, 15);
            glVertex3f( 60,  0, 15);
            glVertex3f( 60,  0, 10);

        glPopMatrix();

//----------------------------------------------


        glPushMatrix();

            glColor3f(0, 0, 0);
            glVertex3f(-60, -2,-15);
            glVertex3f(-60, -2, 10);
            glVertex3f( 60, -2, 10);
            glVertex3f( 60, -2,-15);

            glVertex3f(-60, -2,-15);
            glVertex3f(-60,  0,-15);
            glVertex3f( 60,  0,-15);
            glVertex3f( 60, -2,-15);

            glVertex3f(-60, -2,-15);
            glVertex3f(-60, -2, 10);
            glVertex3f(-60,  0, 10);

            glVertex3f(-60, -2, 10);
            glVertex3f( 60, -2, 10);
            glVertex3f( 60,  0, 10);
            glVertex3f(-60,  0, 10);

            glVertex3f( 60, -2,-15);
            glVertex3f( 60,  0,-15);
            glVertex3f( 60,  0, 10);
            glVertex3f( 60, -2, 10);

            glVertex3f(-60,  0,-15);
            glVertex3f(-60,  0, 10);
            glVertex3f( 60,  0, 10);
            glVertex3f( 60,  0,-15);

        glPopMatrix();

	glEnd();
*/
}


void drawHouses::drawTree(){

    glPushMatrix();
        glScalef(0.5, 0.5, 0.5);
        glTranslatef(-43, 6, 0);
        glPushMatrix();
            glColor3f(0.184314, 0.309804, 0.184314);
            glRotatef(-90, 1, 0, 0);
            glutSolidCone(10, 30, 50, 50);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, 4, 0);
            glColor3f(0.184314, 0.309804, 0.184314);
            glRotatef(-90, 1, 0, 0);
            glutSolidCone(10, 30, 50, 50);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, 8, 0);
            glColor3f(0.184314, 0.309804, 0.184314);
            glRotatef(-90, 1, 0, 0);
            glutSolidCone(10, 30, 50, 50);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, 15, 0);
            glColor3f(0.184314, 0.309804, 0.184314);
            glRotatef(-90, 1, 0, 0);
            glutSolidCone(10, 20, 50, 50);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, -8, 0);
            glRotatef(-90, 1, 0, 0);
            glColor3f(0.36, 0.25, 0.20);
            glutSolidCone(5, 30, 50, 50);
        glPopMatrix();
    glPopMatrix();

}


void drawHouses::drawPoste(){

    glPushMatrix();
        glScalef(0.2, 3.0, 0.25);
        glColor3f(0.35, 0.35, 0.35);
        glutSolidCube(10);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, 12.5, 7.9);
        glScalef(1.5, 1.5, 1.5);
        glColor3f(0.74902, 0.847059, 0.847059);
        drawBuilding(&portaLampada);
    glPopMatrix();

}


drawHouses::drawHouses()
{

    predio.vertices = new VERT[8];

    predio.vertices[0].x = -10;  //0 canto
    predio.vertices[0].y =   0;  //0 inferior esquerdo
    predio.vertices[0].z = -10;  //0 de trás.

    predio.vertices[1].x =  10;  //1 canto
    predio.vertices[1].y =  0;   //1 inferior direito
    predio.vertices[1].z = -10;  // de trás.

    predio.vertices[2].x = 10;   //2 canto
    predio.vertices[2].y = 0;    //2 inferior direito
    predio.vertices[2].z = 10;   //2 da frente.

    predio.vertices[3].x = -10;  //3 canto
    predio.vertices[3].y =  0;   //3 inferior esquerdo
    predio.vertices[3].z =  10;  //3 da frente.

    predio.vertices[4].x = -10;  //4 canto
    predio.vertices[4].y =  30;  //4 superior esquerdo
    predio.vertices[4].z = -10;  //4 de trás.

    predio.vertices[5].x =  10;  //5 canto
    predio.vertices[5].y =  30;  //5 superior direito
    predio.vertices[5].z = -10;  //5 de trás.

    predio.vertices[6].x =  10;  //6 canto
    predio.vertices[6].y =  30;  //6 superior direito
    predio.vertices[6].z =  10;  //6 da frente.

    predio.vertices[7].x = -10;  //7 canto
    predio.vertices[7].y =  30;  //7 superior esquerdo
    predio.vertices[7].z =  10;  //7 da frente.

    predio.faces = new FACE[6];

    predio.faces[0].total = 4;
    predio.faces[0].ind[0] = 0;   //Base
    predio.faces[0].ind[1] = 3;   //Base
    predio.faces[0].ind[2] = 2;   //Base
    predio.faces[0].ind[3] = 1;   //Base

    predio.faces[1].total = 4;
    predio.faces[1].ind[0] = 0;   //Parte Traseira
    predio.faces[1].ind[1] = 4;   //Parte Traseira
    predio.faces[1].ind[2] = 5;   //Parte Traseira
    predio.faces[1].ind[3] = 1;   //Parte Traseira

    predio.faces[2].total = 4;
    predio.faces[2].ind[0] = 0;   //Lado Esquerdo
    predio.faces[2].ind[1] = 3;   //Lado Esquerdo
    predio.faces[2].ind[2] = 7;   //Lado Esquerdo
    predio.faces[2].ind[3] = 4;   //Lado Esquerdo

    predio.faces[3].total = 4;
    predio.faces[3].ind[0] = 3;   //Lado Frontal
    predio.faces[3].ind[1] = 2;   //Lado Frontal
    predio.faces[3].ind[2] = 6;   //Lado Frontal
    predio.faces[3].ind[3] = 7;   //Lado Frontal

    predio.faces[4].total = 4;
    predio.faces[4].ind[0] = 2;   //Lado Direito
    predio.faces[4].ind[1] = 1;   //Lado Direito
    predio.faces[4].ind[2] = 5;   //Lado Direito
    predio.faces[4].ind[3] = 6;   //Lado Direito

    predio.faces[5].total = 4;
    predio.faces[5].ind[0] = 4;   //Topo
    predio.faces[5].ind[1] = 7;   //Topo
    predio.faces[5].ind[2] = 6;   //Topo
    predio.faces[5].ind[3] = 5;   //Topo

    predio.TotalDeFaces = 6;

//---------------------------------------------------------

    janela.vertices = new VERT[4]; //Janela
    janela.vertices[0].x = -2;
    janela.vertices[0].y =  0;
    janela.vertices[0].z =  0;

    janela.vertices[1].x =  2;
    janela.vertices[1].y =  0;
    janela.vertices[1].z =  0;

    janela.vertices[2].x =  2;
    janela.vertices[2].y =  3;
    janela.vertices[2].z =  0;

    janela.vertices[3].x =  -2;
    janela.vertices[3].y =   3;
    janela.vertices[3].z =   0;

    janela.faces = new FACE[1];
    janela.faces[0].total = 4;
    janela.faces[0].ind[0] = 0;
    janela.faces[0].ind[1] = 3;
    janela.faces[0].ind[2] = 2;
    janela.faces[0].ind[3] = 1;
    janela.TotalDeFaces = 1;


//---------------------------------------------------------

    porta.vertices = new VERT[4]; //Porta
    porta.vertices[0].x = -2;
    porta.vertices[0].y =  0;
    porta.vertices[0].z =  0;

    porta.vertices[1].x =  0;
    porta.vertices[1].y =  0;
    porta.vertices[1].z =  0;

    porta.vertices[2].x =  0;
    porta.vertices[2].y =  3;
    porta.vertices[2].z =  0;

    porta.vertices[3].x =  -2;
    porta.vertices[3].y =   3;
    porta.vertices[3].z =   0;

    porta.faces = new FACE[1];
    porta.faces[0].total = 4;
    porta.faces[0].ind[0] = 0;
    porta.faces[0].ind[1] = 3;
    porta.faces[0].ind[2] = 2;
    porta.faces[0].ind[3] = 1;
    porta.TotalDeFaces = 1;

//---------------------------------------------------------

    vidro.vertices = new VERT[4]; //Vidro
    vidro.vertices[0].x = -2;
    vidro.vertices[0].y =  0;
    vidro.vertices[0].z =  0;

    vidro.vertices[1].x =  2;
    vidro.vertices[1].y =  0;
    vidro.vertices[1].z =  0;

    vidro.vertices[2].x =  2;
    vidro.vertices[2].y =  3;
    vidro.vertices[2].z =  0;

    vidro.vertices[3].x =  -2;
    vidro.vertices[3].y =   3;
    vidro.vertices[3].z =   0;

    vidro.faces = new FACE[1];
    vidro.faces[0].total = 4;
    vidro.faces[0].ind[0] = 0;
    vidro.faces[0].ind[1] = 3;
    vidro.faces[0].ind[2] = 2;
    vidro.faces[0].ind[3] = 1;
    vidro.TotalDeFaces = 1;

//---------------------------------------------------------

    vidroPorta.vertices = new VERT[4]; //Vidro da porta
    vidroPorta.vertices[0].x = -2;
    vidroPorta.vertices[0].y =  0;
    vidroPorta.vertices[0].z =  0;

    vidroPorta.vertices[1].x =  0;
    vidroPorta.vertices[1].y =  0;
    vidroPorta.vertices[1].z =  0;

    vidroPorta.vertices[2].x =  0;
    vidroPorta.vertices[2].y =  3;
    vidroPorta.vertices[2].z =  0;

    vidroPorta.vertices[3].x =  -2;
    vidroPorta.vertices[3].y =   3;
    vidroPorta.vertices[3].z =   0;

    vidroPorta.faces = new FACE[1];
    vidroPorta.faces[0].total = 4;
    vidroPorta.faces[0].ind[0] = 0;
    vidroPorta.faces[0].ind[1] = 3;
    vidroPorta.faces[0].ind[2] = 2;
    vidroPorta.faces[0].ind[3] = 1;
    vidroPorta.TotalDeFaces = 1;

//---------------------------------------------------------

    portaLampada.vertices = new VERT[5]; //Porta Lampada

    portaLampada.vertices[0].x = -1;
    portaLampada.vertices[0].y =  0;
    portaLampada.vertices[0].z = -1;

    portaLampada.vertices[1].x =  1;
    portaLampada.vertices[1].y =  0;
    portaLampada.vertices[1].z = -1;

    portaLampada.vertices[2].x =  1;
    portaLampada.vertices[2].y =  0;
    portaLampada.vertices[2].z =  1;

    portaLampada.vertices[3].x = -1;
    portaLampada.vertices[3].y =  0;
    portaLampada.vertices[3].z =  1;

    portaLampada.vertices[4].x =  0;
    portaLampada.vertices[4].y = -2;
    portaLampada.vertices[4].z =  0;

    portaLampada.faces = new FACE[5];

    portaLampada.faces[0].total = 4;
    portaLampada.faces[0].ind[0] = 0;
    portaLampada.faces[0].ind[1] = 3;
    portaLampada.faces[0].ind[2] = 2;
    portaLampada.faces[0].ind[3] = 1;

    portaLampada.faces[1].total = 3;
    portaLampada.faces[1].ind[0] =  0;
    portaLampada.faces[1].ind[1] =  1;
    portaLampada.faces[1].ind[2] =  4;

    portaLampada.faces[2].total = 3;
    portaLampada.faces[2].ind[0] =  3;
    portaLampada.faces[2].ind[1] =  0;
    portaLampada.faces[2].ind[2] =  4;

    portaLampada.faces[3].total = 3;
    portaLampada.faces[3].ind[0] =  1;
    portaLampada.faces[3].ind[1] =  2;
    portaLampada.faces[3].ind[2] =  4;

    portaLampada.faces[4].total = 3;
    portaLampada.faces[4].ind[0] =  2;
    portaLampada.faces[4].ind[1] =  3;
    portaLampada.faces[4].ind[2] =  4;

    portaLampada.TotalDeFaces = 5;

};


drawHouses::~drawHouses()
{
    //dtor
}


void drawHouses::draw(){

    drawBuilding(&predio);

    drawLineContour(&predio);

    glPushMatrix();
        glTranslatef(5, 25, 10.02);
        drawLineContour(&janela);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.74902, 0.847059, 0.847059);
        glTranslatef(5, 25, 10.02);
        drawBuilding(&vidro);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-5, 25, 10.02);
        drawLineContour(&janela);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.74902, 0.847059, 0.847059);
        glTranslatef(-5, 25, 10.02);
        drawBuilding(&vidro);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(5, 15, 10.02);
        drawLineContour(&janela);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.74902, 0.847059, 0.847059);
        glTranslatef(5, 15, 10.02);
        drawBuilding(&vidro);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-5, 15, 10.02);
        drawLineContour(&janela);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.74902, 0.847059, 0.847059);
        glTranslatef(-5, 15, 10.02);
        drawBuilding(&vidro);
    glPopMatrix();

    drawWindow();

    glPushMatrix();
        glTranslatef(0, 0, 10.02);
        drawLineContour(&porta);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.74902, 0.847059, 0.847059);
        glTranslatef(0, 0, 10.02);
        drawBuilding(&vidroPorta);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(2, 0, 10.02);
        drawLineContour(&porta);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.74902, 0.847059, 0.847059);
        glTranslatef(2, 0, 10.02);
        drawBuilding(&vidroPorta);
    glPopMatrix();

}
