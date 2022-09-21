#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ArchivoEjemplo "arhivo.dat"

typedef struct{
    int id;
    char nombre[20];
    char apellido[20];
    int edad;
    char sexo;
}stPersona;

typedef struct{
    stPersona dato;
    struct nodo* siguiente;
}nodo;

nodo* inicLista();
stPersona crearPersona ();
void mostrarPersona(stPersona p);
void cargarArchivo(char archivo[]);
void mostrarArchivo(char archivo[]);
nodo * crearNodo(stPersona dato);
nodo * agregarAlPrincipio(nodo * lista, nodo * nuevo);
nodo * agregarAlPrincipioPro( nodo * lista, nodo * nuevo);
void mostrarLista(nodo * lista);
nodo * agregarAlFinal(nodo * lista, nodo * nuevo);

int main()
{
    srand(time(NULL));
    printf("Hello world!\n");
    cargarArchivo(ArchivoEjemplo);
    mostrarArchivo(ArchivoEjemplo);
    return 0;
}

nodo* inicLista(){
    return NULL;
}

stPersona crearPersona (){
    stPersona p;
    static int id = 0;
    id++;

    p.id = id;
    strcpy(p.nombre, "Pepe");
    strcpy(p.apellido, "Argento");
    p.edad = rand () % (50-18+1) + 18;
    p.sexo= 'm';
    return p;
}


void mostrarPersona(stPersona p){

    printf("\nId..................:%i",p.id);
    printf("\nNombre..............:%s",p.nombre);
    printf("\nApellido............:%s",p.apellido);
    printf("\nEdad................:%i",p.edad);
    printf("\nSexo................:%c",p.sexo);
    printf("\n_______________________");

}

void cargarArchivo(char archivo[]){

    stPersona p;
    FILE * archi = fopen(archivo, "wb");

    if(archi){

        for(int i = 0; i < 10; i ++ ){

            p = crearPersona();
            fwrite(&p,sizeof(stPersona),1, archi);
        }
    }
    fclose(archi);
}

void mostrarArchivo(char archivo[]){

    stPersona p;
    FILE * archi = fopen(archivo, "rb");

    if(archi){

        while(fread(&p,sizeof(stPersona),1,archi) > 0){

            mostrarPersona(p);

        }
    }
    fclose(archi);
}

nodo * crearNodo(stPersona dato){

    nodo * nuevo = (nodo*) malloc(sizeof(nodo));

    nuevo->dato = dato;

    nuevo->siguiente = NULL;

    return nuevo;

}

nodo * agregarAlPrincipio(nodo * lista, nodo * nuevo){

    if(lista == NULL){

        lista = nuevo;
    }
    else{
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    return lista;
}

nodo * agregarAlPrincipioPro( nodo * lista, nodo * nuevo){

    nuevo->siguiente = lista;

    return nuevo;
}

void mostrarLista(nodo * lista){

    nodo * auxLista = lista;
    while(auxLista != NULL){

        mostrarPersona(auxLista->dato);
        auxLista = auxLista ->siguiente;
    }
}

nodo * agregarAlFinal(nodo * lista, nodo * nuevo){

    if(lista == NULL){

        lista = nuevo;
    }
    else{
        nodo * auxLista = buscarUltimo(lista);
        auxLista->siguiente = nuevo;
    }

    return lista;
}

nodo * buscarUltimo(nodo * lista){

    while(lista->siguiente !=NULL){

        lista = lista->siguiente;
    }

    return lista;
}


///1. Hacer un programa que lea de un archivo datos y los inserte en una lista.
