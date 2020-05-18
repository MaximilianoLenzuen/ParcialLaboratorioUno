#include "Clientes.h"
#include "Mascotas.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int contadorMascotas;
}eMascotaCliente;

void mostrarClientesMascotas(eCliente cliente[],int tamCliente,eMascotas mascota[], int tamMascota,int estado);
void mostrarMascota(eCliente cliente[],int tamCliente,eMascotas mascota[], int tamMascota,int estado);
int altaMascota(eMascotas mascota[],int tamMascota,eCliente cliente[],int tamCliente, int estado,int contador);
int bajaClienteCascada(eMascotas mascota[],int tamMascota,eCliente cliente[],int tamCliente, int estado);
void listarMascotasMayores(eMascotas mascota[],int tamMascota,eCliente cliente[],int tamCliente, int estado);
void initMascotaCliente(eMascotaCliente mascotaCliente[], eCliente cliente[],int tamCliente);
void contadorMascotasPorCliente(eMascotaCliente mascotaCliente[],eCliente cliente[],int tamCliente,eMascotas mascota[],int tamMascota);
void listarClientesMasUnaMascota(eMascotaCliente mascotaCliente[],eCliente cliente[],int tamCliente,eMascotas mascota[],int tamMascota);
void ordenarClientesPorCantidadMascotas(eMascotaCliente mascotaCliente[],eCliente cliente[],int tamCliente,eMascotas mascota[],int tamMascota);
void ordenarClientesPorCantidadMascotasYNombres(eMascotaCliente mascotaCliente[],eCliente cliente[],int tamCliente,eMascotas mascota[],int tamMascota);





