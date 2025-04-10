#ifndef NODO_H
#define NODO_H

#include "ticket.h"

typedef struct Nodo {
    Ticket ticket;
    struct Nodo* siguiente;
} Nodo;

#endif
