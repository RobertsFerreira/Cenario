#include "Animacao.h"
#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>

Animacao::Animacao()
{

    chave = NULL;

    angulo = 0;

}

Animacao::~Animacao()
{
    //dtor
}


void Animacao::AnimaSol(){

        if(angulo >= 360.0 )
            angulo = 0.0f;
        else
            angulo += 15;

        glutPostRedisplay();
        glutTimerFunc(41,AnimaSol, 1);

}

void Animacao::AnimationSol(){

    if(chave == true)
        AnimaSol;

}
