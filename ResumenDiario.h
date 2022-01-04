#pragma once
#include "Fecha.h"

class ResumenDiario
{
    private:
        int _idEstacion;
        int _idTipoCombustible;
        Fecha _fecha;
        int _litrosIniciales;
        int _litrosFinales;
        float _precioPorLitro;

    public:
        int getIDEstacion();
        void setIDEstacion(int idEstacion);

        int getIDTipoCombustible();
        void setIDTipoCombustible(int idTipoCombustible);

        Fecha getFecha();
        void setFecha(Fecha fecha);

        int getLitrosIniciales();
        void setLitrosIniciales(int litrosIniciales);

        int getLitrosFinales();
        void setLitrosFinales(int litrosFinales);

        float getPrecioPorLitro();
        void setPrecioPorLitro(float precioPorLitro);

        void mostrar();
        bool grabarEnDisco();
        bool leerDeDisco(int pos);
};

