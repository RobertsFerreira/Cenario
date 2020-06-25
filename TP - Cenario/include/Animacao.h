#ifndef ANIMACAO_H
#define ANIMACAO_H
#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>

class Animacao
{
    public:
        Animacao();
        virtual ~Animacao();
        void AnimationSol();

    protected:

    private:
    bool chave;
    GLfloat angulo;
    void AnimaSol();
};

#endif // ANIMACAO_H
