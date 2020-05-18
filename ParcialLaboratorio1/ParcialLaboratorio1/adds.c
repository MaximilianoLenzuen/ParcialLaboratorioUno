#include "adds.h"

void validarOperacion(char mensaje [],char mensajeError[], int devolucion){
        if(devolucion == 1){
            printf("%s",mensaje);
        }else{
            printf("%s",mensajeError);
        }
}

int getInt(char mensaje[],char mensajeError[],int piso, int techo){
    int entero;
    printf("%s",mensaje);
    scanf("%d",&entero);
    while (entero < piso || entero>techo ){
        printf("%s",mensajeError);
        scanf("%d",&entero);
    }
    return entero;
}

void getString(char mensaje[],char lugar[]){
    printf("%s",mensaje);
    fflush(stdin);
    gets(lugar);
}

char getChar(char mensaje[]){
    char caracter;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&caracter);
    return caracter;
}

