#include <stdio.h>
#include <stdlib.h>
#include "Mascotas_Clientes.h"
#include "adds.h"
#define C 10
#define M 20
#define OCUPADO 1
#define LIBRE 0

int main()
{
        //Declaracion de variables
        int opcion;
        int contadorCargaMascotas=0;
        int contadorCargaClientes=0;

        eCliente cliente[C];
        eMascotas mascota[M];
        eMascotaCliente mascotaCliente[C];


        //Inicializacion de vectores y Hardcodeo de datos brindados
        initCliente(cliente,C,LIBRE);
        initMascota(mascota,M,LIBRE);

        HardcodeClientes(cliente,C);
        HardcodeMascotas(mascota,M);

        //Menu de opciones



        do{
        printf("\n\n\n1-Mostrar listado de clientes\n2-Mostrar Listado de mascotas \n3-Mostrar listado de clientes con sus mascotas:\n4-Alta mascota:\n5-Dar de baja a mascota:\n6-Mofificar mascota: \n7-Alta de clientes/duenios:\n8-Borrado de duenio en cascada:\n9-Mostrar por tipo de mascota:\n10-Modificar cliente o duenio\n11-Listar clientes con mas de una mascota\n12-Listar mascotas mayores de 3 anios\n13-Listar mascotas por un tipo particular\n14-Ordenar a los dueños por cantidad de mascotas y mostrar\n15-Ordenar a los dueños por cantidades de mascotas y por orden alfabetico\n16-Mostrar el promedio de edad entre las mascotas\n17-Mostrar promedio de edad entre las mascotas, por tipo\n18-El promedio que tengo entre varones y mujeres de mis clientes\n19-Salir");
    	opcion=getInt("\nIngrese una opcion:","Ingrese una opcion valida",0,19);

    	switch(opcion){

    	case 1:
    	    system("cls");
            mostrarCliente(cliente, C, OCUPADO);
            break;

        case 2:
            system("cls");
            mostrarMascota(cliente,C,mascota,M,OCUPADO);
            break;

        case 3:
            system("cls");
            mostrarClientesMascotas(cliente,C,mascota,M,OCUPADO);
            break;
        case 4:
            system("cls");
            mostrarCliente(cliente, C, OCUPADO);
            validarOperacion("El alta fue un exito","Hubo un problema para hacer el alta",altaMascota(mascota,M,cliente,C,OCUPADO,contadorCargaMascotas));
            contadorCargaMascotas++;
            break;
        case 5:
            system("cls");
            mostrarMascota(cliente,C,mascota,M,OCUPADO);
            validarOperacion("La baja fue realizada correctamente","Hubo un error y no se pudo realizar",bajaMascota(mascota,M,LIBRE));
            break;
        case 6:
            system("cls");
             mostrarMascota(cliente,C,mascota,M,OCUPADO);
             modificarMascota(mascota,M,OCUPADO);
             break;
        case 7:
            system("cls");
            validarOperacion("El alta fue correcta","No se pudo ingresar",altaCliente(cliente,C,OCUPADO,contadorCargaClientes));
            contadorCargaClientes++;
            break;
        case 8:
             system("cls");
             mostrarCliente(cliente,C,OCUPADO);
             validarOperacion("La baja fue correcta","No se pudo realizar la baja!",bajaClienteCascada(mascota,M,cliente,C,LIBRE));
             break;
        case 9:
             system("cls");
             ordenarMascotas(mascota,M);
             mostrarMascota(cliente,C,mascota,M,OCUPADO);
             break;
        case 10:
             system("cls");
             mostrarCliente(cliente,C,OCUPADO);
             validarOperacion("La modificacion fue realizada con exito!","La modificacion no se pudo completar",modificarCliente(cliente,C,OCUPADO));
             break;
        case 11:
            system("cls");
            initMascotaCliente(mascotaCliente,cliente,C);
            listarClientesMasUnaMascota(mascotaCliente,cliente,C,mascota,M);
            break;


            break;
        case 12:
             system("cls");
             listarMascotasMayores(mascota,M,cliente,C,OCUPADO);
             break;
        case 13:
             system("cls");
             listarMascotasPorTipo(mascota,M,OCUPADO);
             break;
        case 14:
            system("cls");
            initMascotaCliente(mascotaCliente,cliente,C);
            ordenarClientesPorCantidadMascotas(mascotaCliente,cliente,C,mascota,M);
            mostrarCliente(cliente,C,OCUPADO);
            break;
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
            printf("Gracias por utilizar el menu!!");

    	}
        }while(opcion!=19);
}

