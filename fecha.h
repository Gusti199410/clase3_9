#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include"clase_3_9.h"
typedef struct
{
    int dia;
    int mes;
    int anio;
}tFecha;
void mostrar_Fecha(tFecha *fec);
bool insertar_Fecha(tFecha *fec);
bool es_Dia_Validar(int dia, int mes);
bool es_bisiesto(int anio);
bool es_Fecha_Correcta(tFecha *fec);
bool mostrar_fecha_Siguiente(tFecha *fec);
bool sumar_Dias(tFecha *fec,int cds);
bool restar_Dias(tFecha *fec,int cdr);


#endif // FECHA_H_INCLUDED
