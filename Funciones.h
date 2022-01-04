#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "ResumenDiario.h"
#include "Estacion.h"
#include "rlutil.h"

void menuPrincipal();

void mostrarRecaudacion2020();
const char * getNombreTipoCombustible(int);
float getRecaudacionCombustible(ResumenDiario);

int getLitrosVendidos(ResumenDiario);
void anioConMasLitrosVendidos();

void estacionesDieselNafta();

void grabarEstaciones();
void mostrarEstaciones();

#endif // FUNCIONES_H_INCLUDED
