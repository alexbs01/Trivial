//
// Created by alexb on 28/04/2022.
//

#ifndef TRIVIAL_LISTAPREGUNTAS_H
#define TRIVIAL_LISTAPREGUNTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define LNULL NULL

typedef struct pregunta {
    int identificador;
    enum categorias {
            ciencia = 'c',
            arte = 'a',
            geografia = 'g',
            historia = 'h',
            deporte = 'd',
            ocio = 'o'} categoria;
    char pregunta[BUFFER_SIZE];
    char opcionA[BUFFER_SIZE];
    char opcionB[BUFFER_SIZE];
    char opcionC[BUFFER_SIZE];
    char opcionD[BUFFER_SIZE];
    char opcionCorrecta[BUFFER_SIZE];

} tItemL;

typedef struct tNodeL *tPosL;

struct tNodeL {
    tItemL data;
    tPosL next;
};

typedef tPosL tList;

void createEmptyList(tList *L); // Crea una lista vacia
bool isEmptyList(tList L);  // Comprueba si la lista esta vacia
bool createNode(tPosL *p);  // Crea un nodo y si lo crea devuelve un true

// Recibe todos los parametros de la linea y lo inserta todo en una variable de tipo tItemL
tItemL parametrosAtItemL(const char *id, const  char *categ, const char *preg, const  char *op1, const char *op2, const char *op3, const char *op4, const char *opCorrecta);
tPosL findPosition(tList L, tItemL d); // Busca la posicion de un item de la lista
bool insertItem(tItemL d, tList *L); // Inserta un item en la lista
void imprimirLista(tList L);    // Muestra todos los elementos de la lista
void mostrarElementoAleatorio(int numeroMaximo, tList L);

#endif //TRIVIAL_LISTAPREGUNTAS_H
