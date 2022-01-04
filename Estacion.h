#ifndef ESTACION_H_INCLUDED
#define ESTACION_H_INCLUDED

class Estacion{
    private:
        int _IDEstacion;
        int _totalLitros2018 = 0;
        int _totalLitros2019 = 0;
        int _totalLitros2020 = 0;
        int _totalLitros2021 = 0;
    public:
        void setIDEstacion(int);
        void setLitros2018(int);
        void setLitros2019(int);
        void setLitros2020(int);
        void setLitros2021(int);

        int getIDEstacion();
        int getLitros2018();
        int getLitros2019();
        int getLitros2020();
        int getLitros2021();

        bool grabarEnDisco();
        bool leerDeDisco(int pos);
};

#endif // ESTACION_H_INCLUDED
