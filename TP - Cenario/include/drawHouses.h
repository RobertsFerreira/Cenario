#ifndef DRAWHOUSES_H
#define DRAWHOUSES_H

class drawHouses
{
    public:
        drawHouses();
        virtual ~drawHouses();
        void draw();
        void drawFloor(int value);
        void drawTree();
        void drawStreet();
        void drawSun();
        void drawPoste();
        void drawLampad();
        void drawStar();

    protected:

    private:
        struct Star{
            float x, y, z;
        };
        struct Constellation{
            Star *estrela;
        };
        struct VERT{
            float x, y, z;
        };
        struct FACE{
            int total;
            int ind[4];
        };
        struct OBJ{
            VERT *vertices;
            FACE *faces;
            int TotalDeFaces;
        };
        Constellation constelacao;
        OBJ predio;
        OBJ janela;
        OBJ porta;
        OBJ vidro;
        OBJ vidroPorta;
        OBJ portaLampada;
        void drawBuilding(OBJ *objeto);
        void drawLineContour(OBJ *objeto);
        void drawWindow();
};

#endif // DRAWHOUSES_H
