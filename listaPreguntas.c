//
// Created by alexb on 28/04/2022.
//

#include "listaPreguntas.h"

void createEmptyList(tList *L) {
    *L = LNULL;
}

bool isEmptyList(tList L) {
    return (L == NULL);
}

bool createNode(tPosL *p) {
    *p = malloc(sizeof(struct tNode));
    return *p != NULL;
}

tItemL parametrosAtItemL(const char *id, const char *categ, const char *preg, const char *op1, const char *op2, const char *op3, const char *op4, const char *opCorrecta) {
    tItemL objetoLista;
    char *ptr;


    objetoLista.identificador = (int) strtol(id, &ptr, 10); // Para pasar de un id char a un id de tipo int
    switch(*categ) { // Selecciona la categoria correspondiente para cada pregunta
        case 'c': objetoLista.categoria = ciencia; break;
        case 'a': objetoLista.categoria = arte; break;
        case 'g': objetoLista.categoria = geografia; break;
        case 'h': objetoLista.categoria = historia; break;
        case 'd': objetoLista.categoria = deporte; break;
        case 'o': objetoLista.categoria = ocio; break;
        default: break;
    }

    // Como son strings, copia el valor de cada parametro en su posicion del struct correspondiente
    strcpy(objetoLista.pregunta, preg);
    strcpy(objetoLista.opcionA, op1);
    strcpy(objetoLista.opcionB, op2);
    strcpy(objetoLista.opcionC, op3);
    strcpy(objetoLista.opcionD, op4);
    strcpy(objetoLista.opcionCorrecta, opCorrecta);

    return objetoLista;
}


tPosL findPosition(tList L, tItemL d) {
    tPosL p;

    p = L;
    while ((p->next != LNULL) && (p->next->data.identificador < d.identificador)) { //Continue while data is ordered
        p = p->next;
    }
    return p;
}

bool insertItem(tItemL d, tList *L) {
    tPosL q, p;

    if (!createNode(&q)) {
        return false;
    } else {
        q->data = d;
        q->next = LNULL;

        if (isEmptyList(*L)) {
            *L = q;

        } else if (d.identificador < (*L)->data.identificador) { // Inserta como primer elemento

            q->next = *L;
            *L = q;
        } else { // Inserta en la posicion correcta si esta no es la primera
            p = findPosition(*L, d);
            q->next = p->next;
            p->next = q;
        }
        return true;
    }
}

void imprimirLista(tList L) {
    tPosL posicion;

    if(isEmptyList(L)) {
        printf("Esta lista está vacia\n");
    } else {
        for (posicion = L; posicion != LNULL; posicion = posicion->next) {
            printf("\nid: %d"
                   "\ncateg: %c"
                   "\nPregunta: %s"
                   "\nopcion1: %s"
                   "\nopcion2: %s"
                   "\nopcion3: %s"
                   "\nopcion4: %s"
                   "\nopcionCorrec: %s\n", posicion->data.identificador,
                   posicion->data.categoria, posicion->data.pregunta,
                   posicion->data.opcionA, posicion->data.opcionB, posicion->data.opcionC,
                   posicion->data.opcionD, posicion->data.opcionCorrecta);
        }
    }

}