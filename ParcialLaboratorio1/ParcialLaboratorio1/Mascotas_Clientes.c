#include "Mascotas_Clientes.h"
#define OCUPADO 1
#define LIBRE 0

void mostrarClientesMascotas(eCliente cliente[],int tamCliente,eMascotas mascota[], int tamMascota,int estado){

    int i;
    int j;
    printf("\n******Listado de clientes con sus mascotas******");
    printf("\n*********NOMBRE*******APELLIDO******LOCALIDAD******TELEFONO********EDAD******SEXO*****lISTA DE ANIMALES");
    for(i=0;i<tamCliente;i++)
        {
            if(cliente[i].estado == estado){
                printf("\n%15s%15s%15s%15s%10d%10c",cliente[i].nombre
                                                   ,cliente[i].apellido
                                                   ,cliente[i].localidad
                                                   ,cliente[i].telefono
                                                   ,cliente[i].edad
                                                   ,cliente[i].sexo);
            }


            for(j=0;j<tamMascota;j++){
                if(cliente[i].estado==estado && cliente[i].idCliente==mascota[j].idDuenio){
                    printf("%10s",mascota[j].tipo);
                }
            }
        }


}

void mostrarMascota(eCliente cliente[],int tamCliente,eMascotas mascota[], int tamMascota,int estado){
    int i;
    int j;
    printf("\n******Listado de mascotas******");
    printf("\nID*********NOMBRE************TIPO**********RAZA************EDAD********PESO*********SEXO*******DUENIO");
    for(i=0;i<tamMascota;i++)
        {
            if(mascota[i].estado == estado){

                printf("\n%d%15s%16s%15s%15d%13.2f%10c ",mascota[i].idMascota
                                                        ,mascota[i].nombre
                                                        ,mascota[i].tipo
                                                        ,mascota[i].raza
                                                        ,mascota[i].edad
                                                        ,mascota[i].peso
                                                        ,mascota[i].sexo);
            }
            for(j=0;j<tamCliente;j++){
                if(mascota[i].estado==estado && mascota[i].idDuenio==cliente[j].idCliente){
                    printf("%15s",cliente[j].apellido);
                }
            }
        }
}

int altaMascota(eMascotas mascota[],int tamMascota,eCliente cliente[],int tamCliente, int estado,int contador){

    int guardarIndice;
    int i;
    int j;
    int aux=0;
    guardarIndice = buscarIndiceMascota(mascota, tamMascota,LIBRE);

    if(guardarIndice != -1){
        mascota[guardarIndice].idMascota=31+contador;
        printf("\nIngrese el ID de algun nuevo duenio disponible: ");
        scanf("%d",&mascota[guardarIndice].idDuenio);
        while(aux!=1){
        for(j=0;j<tamCliente;j++){
            if(mascota[guardarIndice].idDuenio==cliente[j].idCliente){
                aux=1;
                break;
            }
        }
        }

        getString("\nIngrese el nombre de la mascota:",mascota[guardarIndice].nombre);
        getString("\nIngrese el tipo de la mascota:",mascota[guardarIndice].tipo);
        while( strcmp(mascota[guardarIndice].tipo, "perro")!=0 &&  strcmp(mascota[guardarIndice].tipo, "gato")!=0 &&  strcmp(mascota[guardarIndice].tipo, "raro")!=0){
            getString("\nIngrese el tipo correcto [Perro, Gato, Raro] :",mascota[guardarIndice].tipo);
        }
        getString("\nIngrese la raza de la mascota:",mascota[guardarIndice].raza);
        mascota[guardarIndice].edad=getInt("Ingrese la edad de la mascota:","ingrese una edad valida!!",0,100);
        printf("\nIngrese peso la mascota: ");
        scanf("%f",&mascota[guardarIndice].peso);
        mascota[guardarIndice].estado=estado;
        printf("\nIngrese el sexo de la mascota: ");
        fflush(stdin);
        scanf("%c",&mascota[guardarIndice].sexo);
        while(mascota[guardarIndice].sexo !='m'&& mascota[guardarIndice].sexo!='f'){
            printf("\nIngrese un sexo correcto: ");
            fflush(stdin);
            scanf("%c",&mascota[guardarIndice].sexo);
        }
        return 1;
    }
    return 0;

}

int bajaClienteCascada(eMascotas mascota[],int tamMascota,eCliente cliente[],int tamCliente, int estado){
    int i;
    int j;
    int idBajar;
    int aux=0;
    printf("\nIngrese el id del cliente/duenio a dar de baja: ");
    scanf("%d",&idBajar);
    for(i=0; i < tamCliente; i++){
                if(cliente[i].idCliente == idBajar){
                    cliente[i].estado= estado;
                    aux=1;
                    for(j=0; j < tamMascota; j++){
                        if(cliente[i].idCliente==mascota[j].idDuenio){
                            mascota[j].estado=estado;
                    }
                }
                }

    }
    return aux;
    }

void listarMascotasMayores(eMascotas mascota[],int tamMascota,eCliente cliente[],int tamCliente, int estado){
    int i;
    int j;
    printf("*****Listado de mascotas mayores de 3 años*****\n");
    for(i=0;i<tamMascota;i++){
        if(mascota[i].edad>3&&mascota[i].estado==estado){
                for(j=0;j<tamCliente;j++){
                    if(mascota[i].idDuenio==cliente[j].idCliente){
                        printf("\nMascota: %s y su duenio es: %s",mascota[i].nombre,cliente[j].nombre);
                    }
                }

        }
    }
}

void initMascotaCliente(eMascotaCliente mascotaCliente[], eCliente cliente[],int tamCliente){
    int i;
    for(i=0;i<tamCliente;i++){
        if(cliente[i].estado==OCUPADO){
        mascotaCliente[i].contadorMascotas=0;
        mascotaCliente[i].idCliente = cliente[i].idCliente;
    }
    }
    }

void contadorMascotasPorCliente(eMascotaCliente mascotaCliente[],eCliente cliente[],int tamCliente,eMascotas mascota[],int tamMascota){
    int i;
    int j;
    for(i=0;i<tamCliente;i++){
        for(j=0;j<tamMascota;j++){
            if(cliente[i].estado == OCUPADO && cliente[i].idCliente == mascota[j].idDuenio){
                mascotaCliente[i].contadorMascotas++;

            }

        }
    }
}

void listarClientesMasUnaMascota(eMascotaCliente mascotaCliente[],eCliente cliente[],int tamCliente,eMascotas mascota[],int tamMascota){
    int i;
    contadorMascotasPorCliente(mascotaCliente,cliente,tamCliente,mascota,tamMascota);
    printf("Los clientes con mas de una mascota son: ");
    for(i=0;i<tamCliente;i++){
        if(mascotaCliente[i].contadorMascotas > 1 && cliente[i].estado == OCUPADO){
            printf("\n - %s %s",cliente[i].nombre,cliente[i].apellido);
        }
    }


}

void ordenarClientesPorCantidadMascotas(eMascotaCliente mascotaCliente[],eCliente cliente[],int tamCliente,eMascotas mascota[],int tamMascota){

    int i;
    int j;
    eCliente aux;
    contadorMascotasPorCliente(mascotaCliente,cliente,tamCliente,mascota,tamMascota);
    for(i=0; i<tamCliente-1; i++)
    {
        for(j=i+1; j<tamCliente; j++)
        {
            if(mascotaCliente[i].contadorMascotas>mascotaCliente[j].contadorMascotas)
            {
                aux=cliente[i];
                cliente[i]=cliente[j];
                cliente[j]=aux;
            }

        }
    }

}
