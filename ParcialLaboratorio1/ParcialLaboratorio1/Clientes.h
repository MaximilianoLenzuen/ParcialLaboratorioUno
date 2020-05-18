#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int idCliente;
    char nombre[30];
    char apellido[30];
    char localidad[30];
    char telefono[30];
    int edad;
    char sexo;
    int estado;
}eCliente;



void HardcodeClientes(eCliente[],int);
void mostrarCliente(eCliente cliente[], int tam, int estado);
int buscarIndiceCliente(eCliente cliente[],int tam, int estado);
int altaCliente(eCliente cliente[], int tam,int estado,int contador);
int modificarCliente(eCliente cliente[], int tam,int estado);
void mostrarPromedioSexoClientes(eCliente cliente[], int tam,int estado);

