//
// Created by alexb on 04/05/2022.
//

#include "pilaDePreguntas.h"
#include <stdbool.h>

void createEmptyStack(tStack *S) {
    *S = SNULL;
}

bool createNodeS(tPosS *p) {
    *p = malloc(sizeof(struct tNodeS));
    return (*p != SNULL);
}

bool push(tItemL d, tStack *S) {
    tPosS aux;

    if (!(createNodeS(&aux))) {
        return false;
    } else {
        aux->data = d;
        aux->down = *S;
        *S = aux;
        return true;
    }
}

void pop(tStack *S) {
    tPosS aux;

    aux = *S;
    *S = (*S)->down;
    free(aux);
}

tItemS peek(tStack S) {
    return S->data;
}

bool isEmptyStack(tStack S) {
    return (S == SNULL);
}