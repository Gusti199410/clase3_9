#include"clase_3_9.h"


void cargarVector(int*vec, int ce)
{
    for(int i=0;i<ce;i++)
    {
        scanf("%d",vec);
        vec++;
    }
}
void mostrarVector(int*vec,int ce)
{
    for(int i=0;i<ce;i++)
    {
        printf("\nElemento %d: %d",i+1,*vec);
        vec++;
    }
}
bool eliminar_Elemento_Vector(int *vec,int *ce, int pos)
{
    int *vecI=vec+(pos-1);
    int *fin=vec+*(ce);
    while(vecI<fin)
    {
        *vecI=*(vecI+1);
        vecI++;
    }
    *(ce)-=1;
    return true;
}

bool eliminar_Primera_Aparicion(int *vec,int *ce,int elem)
{
    int *vecI=vec;
    int *fin=vec+*(ce);
    while(vecI<fin)
    {
        if(*vecI==elem)
        {
            int *mover=vecI;
            while(mover<fin-1)
            {
                *mover=*(mover+1);
                mover++;
            }
            *ce-=1;
            return true;

        }
        vecI++;
    }
    return false;
}
bool ordenar_Elemento(int *vec, int ce)
{
    int *aux=vec;
    int *fin=aux+ce;
    int auxx;
    for(int *i=aux;i<fin;i++)
    {
        for(int *j=aux;j<fin-1;j++)
        {
            if(*j>*(j+1))
            {
                auxx=*j;
                *(j)=*(j+1);
                *(j+1)=auxx;
            }
        }
    }
    return true;
}
bool eliminar_Todas_Las_apariciones(int *vec,int *ce, int elemento)
{
    int *inicio=vec;
    int *fin=inicio+*(ce);
    while(inicio<fin)
    {
        if(*inicio==elemento)
        {
            int *eliminar=inicio;
            while(eliminar<fin-1)
            {
                *eliminar=*(eliminar+1);
                eliminar++;
            }
            *(ce)-=1;
        }else
        {
            inicio++;
        }
    }
    return true;
}
