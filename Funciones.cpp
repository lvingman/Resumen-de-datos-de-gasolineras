#include<iostream>
#include<cstdlib>
#include "Funciones.h"


using namespace std;

///MENU PRINCIPAL

void menuPrincipal(){
    int key1 = 1;
    while (key1 == 1){
        int opc;
        cout << "BIENVENIDO" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "OPCION 1: MOSTRAR LA RECAUDACION DEL ANIO 2020" << endl;
        cout << "OPCION 2: MOSTRAR EL ANIO CON LA MAYOR CANTIDAD DE LITROS VENDIDOS" << endl;
        cout << "OPCION 3: MOSTRAR LAS ESTACIONES DE SERVICIO QUE VENDIERON MAS DIESEL QUE NAFTA SUPER, PERO QUE NUNCA VENDIERON GASOIL" << endl;
        cout << "OPCION 4: LISTAR ESTACIONES" << endl;
        cout << "OPCION 0: SALIR DEL PROGRAMA" << endl;
        cout << "   Ingrese su comando: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1:
                mostrarRecaudacion2020();
                break;
            case 2:
                anioConMasLitrosVendidos();
                break;
            case 3:
                estacionesDieselNafta();
                break;
            case 4:
                mostrarEstaciones();
                break;
            case 0:
                cout << "Muchas gracias por su tiempo" << endl;
                key1 = 0;
                break;
        }
        system("pause");
        system("cls");
    }
}



const char * getNombreTipoCombustible(int idCombustible){
    switch(idCombustible){
        case 1:
            return "Nafta Super";
            break;
        case 2:
            return "Nafta Comun";
            break;
        case 3:
            return "Diesel";
            break;
        case 4:
            return "Gasoil";
            break;
        case 5:
            return "GNC";
            break;
        default:
            cout << "VALOR INVALIDO" << endl;
            break;
    }
}

float getRecaudacionCombustible(ResumenDiario reg){
    int litrosVendidos = (reg.getLitrosIniciales() - reg.getLitrosFinales());
    float recaudacionTotal = litrosVendidos * reg.getPrecioPorLitro();
    return recaudacionTotal;
}

int getLitrosVendidos(ResumenDiario reg){
    int litrosVendidos = (reg.getLitrosIniciales() - reg.getLitrosFinales());
    return litrosVendidos;
}

///RECAUDACION 2020

void mostrarRecaudacion2020(){
    int pos = 0;
    int contador = 0;
    ResumenDiario reg;

    while(reg.leerDeDisco(pos)){
        if ((reg.getFecha()).getAnio() == 2020){
            contador++;
        }
        pos++;
    }

    ResumenDiario *reg2020 = nullptr;
    reg2020 = new ResumenDiario[contador];
    pos = 0;
    contador = 0;

    while(reg.leerDeDisco(pos)){
        if ((reg.getFecha()).getAnio() == 2020){
            reg2020[contador] = reg;
            contador++;
        }
        pos++;
    }

    int cont = 1;

    for (int i=0;i<12;i++){
        float naftaSuper, naftaComun, gnc, diesel, gasoil = naftaSuper = naftaComun = gnc = diesel = 0;
        rlutil::locate(1, cont);

        cout << "GANANCIAS DE ";
        switch (i){
            case 0:
                cout << "ENERO";
                break;
            case 1:
                cout << "FEBRERO";
                break;
            case 2:
                cout << "MARZO";
                break;
            case 3:
                cout << "ABRIL";
                break;
            case 4:
                cout << "MAYO";
                break;
            case 5:
                cout << "JUNIO";
                break;
            case 6:
                cout << "JULIO";
                break;
            case 7:
                cout << "AGOSTO";
                break;
            case 8:
                cout << "SEPTIEMBRE";
                break;
            case 9:
                cout << "OCTUBRE";
                break;
            case 10:
                cout << "NOVIEMBRE";
                break;
            case 11:
                cout << "DICIEMBRE";
                break;
            default:
                cout << "VALOR NO VALIDO";
                break;
        }
        cont++;
        rlutil::locate(1,cont);
        cout <<"--------------------------";
        cont++;

        rlutil::locate(1,cont);
        cout << "Nafta Super";
        rlutil::locate(15,cont);
        cout << "Nafta Comun";
        rlutil::locate(30,cont);
        cout << "Diesel";
        rlutil::locate(45,cont);
        cout << "Gasoil";
        rlutil::locate(60,cont);
        cout << "GNC";
        cont++;


        for (int j=0;j<contador;j++){
            if ((reg2020[j].getFecha()).getMes() == (i + 1)){
                switch(reg2020[j].getIDTipoCombustible()){
                    case 1:
                        naftaSuper += getRecaudacionCombustible(reg2020[j]);
                        break;
                    case 2:
                        naftaComun += getRecaudacionCombustible(reg2020[j]);
                        break;
                    case 3:
                        diesel += getRecaudacionCombustible(reg2020[j]);
                        break;
                    case 4:
                        gasoil += getRecaudacionCombustible(reg2020[j]);
                        break;
                    case 5:
                        gnc += getRecaudacionCombustible(reg2020[j]);
                }
            }
        }
        rlutil::locate(1,cont);
        cout << naftaSuper;
        rlutil::locate(15,cont);
        cout << naftaComun;
        rlutil::locate(30,cont);
        cout << diesel;
        rlutil::locate(45,cont);
        cout << gasoil;
        rlutil::locate(60,cont);
        cout << gnc;
        cont++;
        cont++;
        cont++;
    }
    cout << endl << endl;
}

///AÑO CON LA MAYOR CANTIDAD DE LITROS VENDIDOS

void anioConMasLitrosVendidos(){
    int anioMasAntiguo, anioMasModerno;
    ResumenDiario reg;
    int pos = 0;
    while(reg.leerDeDisco(pos)){
        if (pos == 0){
            anioMasAntiguo = (reg.getFecha()).getAnio();
            anioMasModerno = (reg.getFecha()).getAnio();
        }
        else{
            if(anioMasAntiguo > (reg.getFecha()).getAnio()){
                anioMasAntiguo = (reg.getFecha()).getAnio();
            }

            if(anioMasModerno < (reg.getFecha()).getAnio()){
                anioMasModerno = (reg.getFecha()).getAnio();
            }
        }
        pos++;
    }
    int anios = anioMasModerno - anioMasAntiguo;

    int *litrosVendidosTotal = nullptr;
    litrosVendidosTotal = new int[anios];


    ResumenDiario *todosLosRegistros = nullptr;
    todosLosRegistros = new ResumenDiario[pos];
    pos = 0;

    while(reg.leerDeDisco(pos)){
        todosLosRegistros[pos] = reg;
        pos++;
    }


    for (int i=anioMasAntiguo;i<=anioMasModerno;i++){
        for (int j=0;j<pos;j++){
            if ((todosLosRegistros[j].getFecha()).getAnio() == i){
                litrosVendidosTotal[i-anioMasAntiguo] = litrosVendidosTotal[i-anioMasAntiguo] + getLitrosVendidos(reg);
            }
        }
    }

    int anioConMasLitros;
    int mayorCantidadLitros;

    for (int i=0;i<anios;i++){
        if (i == 0){
            anioConMasLitros = i + anioMasAntiguo;
            mayorCantidadLitros = litrosVendidosTotal[i];
        }
        else{
            if (litrosVendidosTotal[i] > mayorCantidadLitros){
                anioConMasLitros = i + anioMasAntiguo;
                mayorCantidadLitros = litrosVendidosTotal[i];
            }
        }
    }

    cout << "EL ANIO CON LA MAYOR CANTIDAD DE LITROS VENDIDOS ES: " << anioConMasLitros << endl;
    cout << "LA CANTIDAD DE LITROS VENDIDA ES DE: " << mayorCantidadLitros << " LITROS" << endl;

}

///ESTACIONES DIESEL NAFTA

void estacionesDieselNafta(){
    ResumenDiario reg;
    int pos = 0;
    int DieselVendido[50] = {0};
    int NaftaVendido[50] = {0};
    int GasoilVendido[50] = {0};

    while(reg.leerDeDisco(pos)){
        switch(reg.getIDTipoCombustible()){
            case 1:
                NaftaVendido[reg.getIDEstacion() - 1] = NaftaVendido[reg.getIDEstacion() - 1] + getLitrosVendidos(reg);
                break;
            case 3:
                DieselVendido[reg.getIDEstacion() - 1] = DieselVendido[reg.getIDEstacion() - 1] + getLitrosVendidos(reg);
                break;
            case 4:
                GasoilVendido[reg.getIDEstacion() - 1] = GasoilVendido[reg.getIDEstacion() - 1] + getLitrosVendidos(reg);
                break;
            default:
                break;
        }
        pos++;
    }

    cout << "ESTACIONES DE SERVICIO QUE VENDIERON MAS DIESEL QUE NAFTA SUPER Y NUNCA VENDIERON GASOIL: " << endl;

    for (int i=0; i<50;i++){
        if ((DieselVendido[i] > NaftaVendido[i]) && (GasoilVendido[i] == 0)){
            cout << i+1 << ", ";
        }
    }

    cout << endl << endl;

}


///GRABAR ESTACIONES EN .DAT

void grabarEstaciones(){
    Estacion estaciones[50];
    ResumenDiario reg;
    int pos = 0;

    while(reg.leerDeDisco(pos)){
        switch((reg.getFecha()).getAnio()){
            case 2018:
                estaciones[reg.getIDEstacion() - 1].setLitros2018(estaciones[reg.getIDEstacion() - 1].getLitros2018() + getLitrosVendidos(reg));
                break;
            case 2019:
                estaciones[reg.getIDEstacion() - 1].setLitros2019(estaciones[reg.getIDEstacion() - 1].getLitros2019() + getLitrosVendidos(reg));
                break;
            case 2020:
                estaciones[reg.getIDEstacion() - 1].setLitros2020(estaciones[reg.getIDEstacion() - 1].getLitros2020() + getLitrosVendidos(reg));
                break;
            case 2021:
                estaciones[reg.getIDEstacion() - 1].setLitros2021(estaciones[reg.getIDEstacion() - 1].getLitros2021() + getLitrosVendidos(reg));
                break;
            default:
                break;
        }
        pos++;
    }

    for (int i=0;i<50;i++){
        estaciones[i].setIDEstacion(i+1);
        estaciones[i].grabarEnDisco();
    }
}

void mostrarEstaciones(){
    Estacion reg;
    int pos = 0;
    rlutil::locate(20,1);
    cout << "Cantidad de Litros Vendidos En:";
    rlutil::locate(1,2);
    cout << "ID de Estacion";
    rlutil::locate(20,2);
    cout << "2018";
    rlutil::locate(30,2);
    cout << "2019";
    rlutil::locate(40,2);
    cout << "2020";
    rlutil::locate(50,2);
    cout << "2021";
    rlutil::locate(1,3);
    cout << "------------------------------------------------------------------------";

    while (reg.leerDeDisco(pos)){
        rlutil::locate(1, 4+pos);
        cout << reg.getIDEstacion();
        rlutil::locate(20, 4+pos);
        cout << reg.getLitros2018();
        rlutil::locate(30, 4+pos);
        cout << reg.getLitros2019();
        rlutil::locate(40, 4+pos);
        cout << reg.getLitros2020();
        rlutil::locate(50, 4+pos);
        cout << reg.getLitros2021();
        pos++;
    }
    cout << endl << endl;
}
