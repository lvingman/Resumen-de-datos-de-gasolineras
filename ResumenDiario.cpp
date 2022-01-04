#include <iostream>
using namespace std;
#include "ResumenDiario.h"

int ResumenDiario::getIDEstacion()
{
    return _idEstacion;
}

void ResumenDiario::setIDEstacion(int idEstacion)
{
    _idEstacion = idEstacion;
}

int ResumenDiario::getIDTipoCombustible()
{
    return _idTipoCombustible;
}

void ResumenDiario::setIDTipoCombustible(int idTipoCombustible)
{
    _idTipoCombustible = idTipoCombustible;
}

Fecha ResumenDiario::getFecha()
{
    return _fecha;
}

void ResumenDiario::setFecha(Fecha fecha)
{
    _fecha = fecha;
}

int ResumenDiario::getLitrosIniciales()
{
    return _litrosIniciales;
}

void ResumenDiario::setLitrosIniciales(int litrosIniciales)
{
    _litrosIniciales = litrosIniciales;
}

int ResumenDiario::getLitrosFinales()
{
    return _litrosFinales;
}

void ResumenDiario::setLitrosFinales(int litrosFinales)
{
    _litrosFinales = litrosFinales;
}


float ResumenDiario::getPrecioPorLitro()
{
    return _precioPorLitro;
}

void ResumenDiario::setPrecioPorLitro(float precioPorLitro)
{
    _precioPorLitro = precioPorLitro;
}

void ResumenDiario::mostrar()
{
    cout << _idEstacion << "," << _idTipoCombustible << "," << _fecha.getDia() << "," << _fecha.getMes() << "," << _fecha.getAnio() << "," << _litrosIniciales << "," << _litrosFinales << "," << _precioPorLitro << endl;
}

bool ResumenDiario::grabarEnDisco()
{
    FILE* p;
    p = fopen("resumendiario.dat", "ab");
    if (p == NULL) {
        return false;
    }

    if (fwrite(this, sizeof(ResumenDiario), 1, p)) {
        fclose(p);
        return true;
    }
    else {
        fclose(p);
        return false;
    }
}

bool ResumenDiario::leerDeDisco(int pos)
{
    FILE* p;
    p = fopen("resumendiario.dat", "rb");

    if (p == NULL) {
        return false;
    }

    fseek(p, sizeof(ResumenDiario) * pos, 0);

    if (fread(this, sizeof(ResumenDiario), 1, p))
    {
        fclose(p);
        return true;
    }
    else {
        fclose(p);
        return false;
    }
}

