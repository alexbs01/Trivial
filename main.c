#include <stdio.h>
#include <string.h>
#include "listaPreguntas.h"

#define BUFFER_SIZE 1024

int main() {
    FILE *ficheroPreguntas;
    char nombreFicheroPreguntas[] = "preguntas.csv";
    char buffer[BUFFER_SIZE]; // En esta la variable se almacenará la linea del csv antes de que se divida en diferentes variables
    char *id, *categ, *preg, *op1, *op2, *op3, *op4, *opCorrec;

    tList listaPreguntas;
    tItemL lineaDePregunta;

    createEmptyList(&listaPreguntas); // Se crea una lista vacia para las preguntas

    ficheroPreguntas = fopen(nombreFicheroPreguntas, "r"); // Abre el fichero en modo lectura

    if(ficheroPreguntas == NULL) { // Si no lo puede abrir muestra el mensaje de error y se termina la ejecucion
        printf("\nNo se pudo abrir el fichero");
        return 1;
    }

    const char delimitador[] = ";";
    while(fgets(buffer, BUFFER_SIZE, ficheroPreguntas)) {

        id = strtok(buffer, delimitador);
        categ = strtok(NULL, delimitador);
        preg = strtok(NULL, delimitador);
        op1 = strtok(NULL, delimitador);
        op2 = strtok(NULL, delimitador);
        op3 = strtok(NULL, delimitador);
        op4 = strtok(NULL, delimitador);
        opCorrec = strtok(NULL, delimitador);

        /*printf("\nid: %s"
               "\ncateg: %s"
               "\nPregunta: %s"
               "\nopcion1: %s"
               "\nopcion2: %s"
               "\nopcion3: %s"
               "\nopcion4: %s"
               "\nopcionCorrec: %s", id, categ, preg, op1, op2, op3, op4, opCorrec);*/

        // Todos los valores de la linea, se insertan en una variable de tipo tItemL
        lineaDePregunta = parametrosAtItemL(id, categ, preg, op1, op2, op3, op4, opCorrec);
        insertItem(lineaDePregunta, &listaPreguntas); // Se inserta la variable tItemL en la lista de pregunas ordenada

    }
    imprimirLista(listaPreguntas); // Imprime la lista para ver todos sus elementos

    return 0;
}
