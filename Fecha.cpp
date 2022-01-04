#include <iostream>
using namespace std;
#include "Fecha.h"

Fecha::Fecha()
{
    //ctor
}

int Fecha::getDia() { return _dia; }
void Fecha::setDia(int dia) { _dia = dia; }
int Fecha::getMes() { return _mes; }
void Fecha::setMes(int mes) { _mes = mes; }
int Fecha::getAnio() { return _anio; }
void Fecha::setAnio(int anio) { _anio = anio; }
void Fecha::mostrar(){
    cout << _dia << "/" << _mes << "/" << _anio << endl;
}
