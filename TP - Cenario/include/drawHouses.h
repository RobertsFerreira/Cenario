#ifndef DRAWHOUSES_H
#define DRAWHOUSES_H


class drawHouses
{
    public:
        drawHouses();
        virtual ~drawHouses();
        void draw();
        void drawFloor();
        void drawTree();
        void drawStreet();
        void drawSun();

    protected:

    private:
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
        OBJ predio;
        OBJ janela;
        OBJ porta;
        OBJ vidro;
        OBJ vidroPorta;
        void drawBuilding(OBJ *objeto);
        void drawLineContour(OBJ *objeto);
        void drawWindow();
};

#endif // DRAWHOUSES_H
