
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"

void insertar_ticket(Nodo** lista, Ticket t) {
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->ticket = t;
    nuevo->siguiente = NULL;

    if (*lista == NULL || (*lista)->ticket.horaRegistro > t.horaRegistro) {
        nuevo->siguiente = *lista;
        *lista = nuevo;
    } else {
        Nodo* actual = *lista;
        while (actual->siguiente != NULL && actual->siguiente->ticket.horaRegistro <= t.horaRegistro) {
            actual = actual->siguiente;
        }
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
    }
}

int eliminar_ticket_por_id(Nodo** lista, int id) {
    Nodo *actual = *lista, *anterior = NULL;
    while (actual != NULL) {
        if (actual->ticket.id == id) {
            if (anterior == NULL) *lista = actual->siguiente;
            else anterior->siguiente = actual->siguiente;
            free(actual);
            return 1;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    return 0;
}

Ticket* buscar_ticket(Nodo* lista, int id) {
    while (lista != NULL) {
        if (lista->ticket.id == id) return &lista->ticket;
        lista = lista->siguiente;
    }
    return NULL;
}

Ticket procesar_ticket(Nodo** lista) {
    Ticket t = (*lista)->ticket;
    Nodo* temp = *lista;
    *lista = (*lista)->siguiente;
    free(temp);
    return t;
}

void mostrar_lista(Nodo* lista, const char* nombre) {
    printf("=== %s ===\n", nombre);
    while (lista != NULL) {
        printf("ID: %d | %s | Prioridad: %d | Hora: %d\n", lista->ticket.id, lista->ticket.descripcion,
               lista->ticket.prioridad, lista->ticket.horaRegistro);
        lista = lista->siguiente;
    }
}
