#include "Mascotas.h"


void HardcodeMascotas(eMascotas mascota[],int tam){
    int i;
    int idMascota[11]={20,21,22,23,24,25,26,27,28,29,30};
    int idDuenio[11]={50,50,51,51,51,52,52,53,54,54,54};
    char nombre[11][30]={{"Romeo"},{"Tusca"},{"Ragnar"},{"Aquiles"},{"Lambda"},{"Waldorf"},{"Salamanca"},{"Rita"},{"Mia"},{"lambdamia"},{"Heavy"}};
    char tipo[11][30]={{"Gato"},{"Gato"},{"Perro"},{"Perro"},{"Gato"},{"Perro"},{"Raro"},{"Perro"},{"Gato"},{"Gato"},{"Perro"}};
    char raza[11][30]={{"Siames"},{"Callejero"},{"Callejero"},{"Rootwailer"},{"Callejero"},{"Pitbull"},{"Exotico"},{"Labrador"},{"Siames"},{"Siames"},{"Bulldog"}};
    int edad[11]={4,2,9,1,3,9,3,4,6,6,2};
    float peso[11]={9.01,5.98,4.30,7.00,9.65,5.12,1.87,7.85,3.6,4.96,6.2};
    char sexo[11]={'F','F','M','M','M','M','F','M','M','M','M'};
    int estado[11]={1,1,1,1,1,1,1,1,1,1,1};

    for(i=0;i<11;i++)
    {
        mascota[i].idMascota=idMascota[i];
        mascota[i].idDuenio=idDuenio[i];
        strcpy(mascota[i].nombre,nombre[i]);
        strcpy(mascota[i].tipo,tipo[i]);
        strcpy(mascota[i].raza,raza[i]);
        mascota[i].edad=edad[i];
        mascota[i].peso=peso[i];
        mascota[i].sexo=sexo[i];
        mascota[i].estado=estado[i];
    }
}

void initMascota(eMascotas mascota[], int tam,int estado){
    int i;
    for(i=0;i<tam;i++){
        mascota[i].estado = estado;
    }

}

int buscarIndiceMascota(eMascotas mascota[],int tam, int estado){

    int indice= -1;
    int i;
    for(i=0; i < tam; i++){
    if(mascota[i].estado==estado){
        indice=i;
        return indice;
    }

}
return indice;
}

int bajaMascota(eMascotas mascota[], int tam,int estado){

int i;
int idBajar;
printf("\nIngrese el id de la mascota a dar de baja: ");
scanf("%d",&idBajar);
for(i=0; i < tam; i++){
            if(mascota[i].idMascota == idBajar ){
                mascota[i].estado= estado;
                return 1;
            }
}
return 0;
}

int modificarMascota(eMascotas mascota[], int tam,int estado){
    int i;
    int idModificar;
    printf("\nIngrese el id de la mascota a modificar: ");
    scanf("%d",&idModificar);

    for(i=0; i < tam; i++){
            if(mascota[i].idMascota == idModificar && mascota[i].estado == estado )
                {
                getString("\nIngrese el nombre de la mascota:",mascota[i].nombre);
                getString("\nIngrese el tipo de la mascota:",mascota[i].tipo);
                while( strcmp(mascota[i].tipo, "perro")!=0 &&  strcmp(mascota[i].tipo, "gato")!=0 &&  strcmp(mascota[i].tipo, "raro")!=0)
                {
                        getString("\nIngrese el tipo correcto [Perro, Gato, Raro] :",mascota[i].tipo);
                }
                getString("\nIngrese la raza de la mascota:",mascota[i].raza);
                mascota[i].edad=getInt("Ingrese la edad de la mascota:","ingrese una edad valida!!",0,100);
                printf("\nIngrese peso la mascota: ");
                scanf("%f",&mascota[i].peso);
                printf("\nIngrese el sexo de la mascota: ");
                fflush(stdin);
                scanf("%c",&mascota[i].sexo);
                while(mascota[i].sexo !='m'&& mascota[i].sexo!='f')
                {
                    printf("\nIngrese un sexo correcto: ");
                    fflush(stdin);
                    scanf("%c",&mascota[i].sexo);
                }
        return 1;


                }

                }


    return 0;
    }

void ordenarMascotas(eMascotas mascota[],int tam){
    int i;
    int j;
    eMascotas aux;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(mascota[i].tipo,mascota[j].tipo)>0)
            {
                aux=mascota[i];
                mascota[i]=mascota[j];
                mascota[j]=aux;
            }
        }
    }
    }

void listarMascotasPorTipo(eMascotas mascota[],int tam,int estado){
    int i;
    char opcion[10];
    getString("\nIngrese el tipo de la mascota a mostrar(Perro,Gato,Raro):",&opcion);
                while( strcmp(opcion, "perro")!=0 &&  strcmp(opcion, "gato")!=0 &&  strcmp(opcion, "raro")!=0)
                {
                        getString("\nIngrese el tipo correcto [Perro, Gato, Raro] :",&opcion);
                }
    printf("\nID*********NOMBRE************TIPO**********RAZA************EDAD********PESO*********SEXO");
    for(i=0;i<tam;i++){

        if(strcmpi(opcion, mascota[i].tipo)==0 && mascota[i].estado == estado){
            printf("\n%d%15s%16s%15s%15d%13.2f%10c ",mascota[i].idMascota
                                                    ,mascota[i].nombre
                                                    ,mascota[i].tipo
                                                    ,mascota[i].raza
                                                    ,mascota[i].edad
                                                    ,mascota[i].peso
                                                    ,mascota[i].sexo);
        }
    }

}
