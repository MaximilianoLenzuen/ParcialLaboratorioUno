#include "Clientes.h"
#define OCUPADO 1
#define LIBRE 0

void HardcodeClientes(eCliente cliente[],int tam){
    int i;
    int idCliente[5]={50,51,52,53,54};
    char nombre[5][30]={{"Charo"},{"Maxi"},{"Lorena"},{"Lautaro"},{"Casco"}};
    char apellido[5][30]={{"Estevez"},{"Lenzuen"},{"Fernandez"},{"Walsh"},{"Garancini"}};
    char localidad[5][20]={{"Echeverria"},{"Longchamps"},{"Devoto"},{"Glew"},{"Guernica"}};
    char telefono[5][30]={{"1526459985"},{"42330556"},{"1526458888"},{"124597853"},{"1564979785"}};
    int edad[5]={18,52,23,30,29};
    char sexo[5]={'F','M','F','M','M'};
    int estado[5]={1,1,1,1,1};

    for(i=0;i<5;i++)
    {
        cliente[i].idCliente=idCliente[i];
        strcpy(cliente[i].nombre,nombre[i]);
        strcpy(cliente[i].apellido,apellido[i]);
        strcpy(cliente[i].localidad,localidad[i]);
        strcpy(cliente[i].telefono,telefono[i]);
        cliente[i].edad=edad[i];
        cliente[i].sexo=sexo[i];
        cliente[i].estado=estado[i];
    }
}

void initCliente(eCliente cliente[], int tam,int estado){
    int i;
    for(i=0;i<tam;i++){
        cliente[i].estado = estado;
    }

}

void mostrarCliente(eCliente cliente[], int tam, int estado){
    int i;
    printf("\n******Listado de clientes******");
    printf("\nID*********Nombre*******Apellido********Localidad*******Telefono*******Edad********Sexo");
    for(i=0;i<tam;i++)
        {
            if(cliente[i].estado == estado){
                printf("\n%2d%15s%15s%17s%15s%11d%11c" ,cliente[i].idCliente
                                                                                                              ,cliente[i].nombre
                                                                                                              ,cliente[i].apellido
                                                                                                              ,cliente[i].localidad
                                                                                                              ,cliente[i].telefono
                                                                                                              ,cliente[i].edad
                                                                                                              ,cliente[i].sexo);
            }
        }
}

int buscarIndiceCliente(eCliente cliente[],int tam, int estado){

    int indice= -1;
    int i;
    for(i=0; i < tam; i++){
    if(cliente[i].estado==estado){
        indice=i;
        break;

    }
}
}

int altaCliente(eCliente cliente[], int tam,int estado,int contador){

    int guardarIndice;
    int i;
    guardarIndice = buscarIndiceCliente(cliente, tam, LIBRE);

    if(guardarIndice != -1){
        cliente[guardarIndice].idCliente=55+contador;
        getString("\nIngrese el nombre del cliente:",cliente[guardarIndice].nombre);
        getString("\nIngrese el apellido del cliente:",cliente[guardarIndice].apellido);
        getString("\nIngrese la localidad del cliente: ",cliente[guardarIndice].localidad);
        getString("\nIngrese el numero de teléfono",&cliente[guardarIndice].telefono);
        cliente[guardarIndice].edad=getInt("Ingrese la edad del cliente:","Ingrese una edad valida!",0,150);
        printf("\nIngrese el sexo del cliente: ");
        fflush(stdin);
        scanf("%c",&cliente[guardarIndice].sexo);
        while(cliente[guardarIndice].sexo !='m'&& cliente[guardarIndice].sexo!='f'){
            printf("\nIngrese un sexo correcto: ");
            fflush(stdin);
            scanf("%c",&cliente[guardarIndice].sexo);
            cliente[guardarIndice].estado=estado;
        return 1;
    }
    return 0;
    }
    }

int modificarCliente(eCliente cliente[], int tam,int estado){
    int i;
    int idModificar;
    printf("\nIngrese el id del cliente a modificar: ");
    scanf("%d",&idModificar);

    for(i=0; i < tam; i++){
        if(cliente[i].idCliente==idModificar && cliente[i].estado == estado){
            getString("\nIngrese el nombre del cliente:",cliente[i].nombre);
            getString("\nIngrese el apellido del cliente:",cliente[i].apellido);
            getString("\nIngrese la localidad del cliente: ",cliente[i].localidad);
            getString("\nIngrese el numero de teléfono",&cliente[i].telefono);
            cliente[i].edad=getInt("Ingrese la edad del cliente:","Ingrese una edad valida!",0,150);
            printf("\nIngrese el sexo del cliente: ");
            fflush(stdin);
            scanf("%c",&cliente[i].sexo);
            while(cliente[i].sexo !='m'&& cliente[i].sexo!='f'){
                printf("\nIngrese un sexo correcto: ");
                fflush(stdin);
                scanf("%c",&cliente[i].sexo);
            cliente[i].estado=estado;
        }
    }
}
}


