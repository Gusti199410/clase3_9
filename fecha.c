#include "fecha.h"
#include "clase_3_9.h"
#include <stdio.h>
#include <stdbool.h>

void mostrar_Fecha(tFecha *fec)
{
    printf("\nLa fecha: %02d/%02d/%04d", fec->dia, fec->mes, fec->anio);
}

bool insertar_Fecha(tFecha *fec)
{
    printf("INGRESE FECHA (dd/mm/aaaa): ");
    scanf("%d%d%d", &fec->dia, &fec->mes, &fec->anio);
    if (es_Fecha_Correcta(fec))
    {
        mostrar_Fecha(fec);
        return true;
    }

}
bool es_Fecha_Correcta(tFecha *fec)
{
    if(fec->anio > 1600)
    {
        if(fec->mes > 1 && fec->mes <= 12)
        {
            if(es_Dia_Validar(fec->dia,fec->mes))
            {
                return true;
            }
            else if(es_bisiesto(fec->anio) && fec->mes == 2 && fec->dia==29)
            {
                return true;
            }else
            {
                printf("Error al modificar ");
                return false;
            }
        }else
        {
        printf("Error en el mes");
        }
    }else
    {
        printf("Error en el anio");
        return false;
    }
}
bool es_Dia_Validar(int dia, int mes)
{
    int dm[13]={0,31,28,31,30,31,31,30,31,30,31,30,31};
    if(dia >= 1 && dia <= dm[mes])
    {
        return true;
    }
    return false;
}

bool es_bisiesto(int anio)
{
    return (anio % 4 == 0) && ((anio % 100 != 0) || (anio % 400 == 0));
}

bool mostrar_fecha_Siguiente(tFecha *fec)
{
    fec->dia+=1;
    if(!es_Dia_Validar(fec->dia,fec->mes))
    {
        if(es_bisiesto(fec->anio))
        {
            if(fec->mes == 2)
            {
                fec->dia=29;
                return true;
            }
        }
        fec->dia=1;
        fec->mes+=1;
        if(fec->mes==13)
        {
            fec->mes=1;
            fec->anio+=1;
        }
    }
    return true;
}
bool sumar_Dias(tFecha *fec,int cds)
{
    int total_Dias = fec->dia + cds;
    int dm[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    while(total_Dias > dm[fec->mes])
    {
        if(es_bisiesto(fec->anio))
        {
            dm[2]=29;
        }
        if(fec->mes == 13)
        {
            fec->mes=1;
            fec->anio+=1;
        }
        total_Dias-=dm[fec->mes];
        fec->mes+=1;
    }
    fec->dia=total_Dias;
    return true;
}

bool restar_Dias(tFecha *fec,int cdr)
{
   int total_Dias=cdr;
   int dm[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
   while(total_Dias>0)
   {
       if(es_bisiesto(fec->anio))
       {
           dm[2]=29;
       }
       if(fec->dia>total_Dias)
       {
           fec->dia-=total_Dias;
           total_Dias =0;
       }
       else
       {
           total_Dias-=fec->dia;
           fec->mes--;
           if(fec->mes==0)
           {
               fec->mes=12;
               fec->anio--;
           }
           fec->dia=dm[fec->mes];
       }

   }
   return true;
}
