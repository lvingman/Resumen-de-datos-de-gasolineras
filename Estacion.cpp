#include<iostream>
#include<cstdlib>
#include "Estacion.h"

using namespace std;

void Estacion::setIDEstacion(int numero){
    _IDEstacion = numero;
}
void Estacion::setLitros2018(int numero){
    _totalLitros2018 = numero;
}
void Estacion::setLitros2019(int numero){
    _totalLitros2019 = numero;
}
void Estacion::setLitros2020(int numero){
    _totalLitros2020 = numero;
}
void Estacion::setLitros2021(int numero){
    _totalLitros2021 = numero;
}

int Estacion::getIDEstacion(){
    return _IDEstacion;
}
int Estacion::getLitros2018(){
    return _totalLitros2018;
}
int Estacion::getLitros2019(){
    return _totalLitros2019;
}
int Estacion::getLitros2020(){
    return _totalLitros2020;
}
int Estacion::getLitros2021(){
    return _totalLitros2021;
}

bool Estacion::grabarEnDisco()
{
    FILE* p;
    p = fopen("estaciones.dat", "ab");
    if (p == NULL) {
        return false;
    }

    if (fwrite(this, sizeof(Estacion), 1, p)) {
        fclose(p);
        return true;
    }
    else {
        fclose(p);
        return false;
    }
}

bool Estacion::leerDeDisco(int pos)
{
    FILE* p;
    p = fopen("estaciones.dat", "rb");

    if (p == NULL) {
        return false;
    }

    fseek(p, sizeof(Estacion) * pos, 0);

    if (fread(this, sizeof(Estacion), 1, p))
    {
        fclose(p);
        return true;
    }
    else {
        fclose(p);
        return false;
    }
}
