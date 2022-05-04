//
// Created by alexb on 04/05/2022.
//

#ifndef TRIVIAL_PILADEPREGUNTAS_H
#define TRIVIAL_PILADEPREGUNTAS_H

#include "listaPreguntas.h"
#include <stdio.h>
#include <stdbool.h>
#define SNULL NULL

typedef tItemL tItemS;

typedef struct tNodeS *tPosS;

struct tNodeS {
    tItemL data;
    tPosS down;
};

typedef tPosS tStack;

void createEmptyStack(tStack *S); // Crea una pila vacia
bool createNodeS(tPosS *p); // Crea un nodo para la pila
bool push(tItemL d, tStack *S); // Inserte una elemento en la pila arriba de todo
void pop(tStack *S); // Quita el ultimo elemento de la pila
tItemS peek(tStack S); // Muestra devuelve el contenido del ultimo elemento de la pila
bool isEmptyStack(tStack S); // Comprueba si la pila esta vacia o no

#endif //TRIVIAL_PILADEPREGUNTAS_H
