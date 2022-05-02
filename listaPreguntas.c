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
    enum categorias categoriaPregunta;

    objetoLista.identificador = (int) *id;
    switch(*categ) {
        case 'c': objetoLista.categoria = 'c'; break;
        case 'a': objetoLista.categoria = 'a'; break;
        case 'g': objetoLista.categoria = 'g'; break;
        case 'h': objetoLista.categoria = 'h'; break;
        case 'd': objetoLista.categoria = 'd'; break;
        case 'o': objetoLista.categoria = 'o'; break;
    }
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
    while ((p->next != LNULL) &&
           (p->next->data.identificador < d.identificador)) { //Continue while data is ordered
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

        } else if (d.identificador < (*L)->data.identificador) { // insert at the top of the list (first element)

            q->next = *L;
            *L = q;
        } else { //Find right position
            p = findPosition(*L, d);
            q->next = p->next;
            p->next = q;
        }
        return true;
    }
}