#include"clase_3_9.h"
#include"fecha.h"

int main()
{
    tFecha fecha={12,10,1994};
    int vec[5]={3,5,7,896,1};
    int vec2[10]={10,11,7,7,3,101,3,5,2,1};
    int ce=5;
    //eliminar_Elemento_Vector(vec,&ce);
    //printf("La cantidad de elemento es: %d\n",ce);
    size_t peso=sizeof(vec);
    printf("\nEl peso es: %d\n",(int)peso);
    int cee=10;
    //eliminar_Primera_Aparicion(vec2,&cee,5);
   // mostrarVector(vec2,cee);
    ordenar_Elemento(vec2,cee);
    eliminar_Todas_Las_apariciones(vec2,&cee,7);
    mostrarVector(vec2,cee);
    //insertar_Fecha(&fecha);
    //mostrar_fecha_Siguiente(&fecha);
    mostrar_Fecha(&fecha);
    //sumar_Dias(&fecha,600);
    restar_Dias(&fecha,12);
    mostrar_Fecha(&fecha);

    return 0;
}
