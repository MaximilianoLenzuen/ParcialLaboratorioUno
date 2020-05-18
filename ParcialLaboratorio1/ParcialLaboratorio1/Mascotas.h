#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int idMascota;
    int idDuenio;
    char nombre[30];
    char tipo[30];
    char raza[30];
    int edad;
    float peso;
    char sexo;
    int estado;
}eMascotas;

void HardcodeMascotas(eMascotas[],int);
int buscarIndiceMascota(eMascotas mascota[],int tam, int estado);
void initMascota(eMascotas mascota[], int tam,int estado);
int bajaMascota(eMascotas mascota[], int tam,int estado);
int modificarMascota(eMascotas mascota[], int tam,int estado);
void ordenarMascotas(eMascotas mascota[],int tam);
void listarMascotasPorTipo(eMascotas mascota[],int tam,int estado);
void listarPromedioEdadMascotas(eMascotas mascota[],int tam,int estado);
