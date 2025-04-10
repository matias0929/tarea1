#ifndef TICKET_H
#define TICKET_H

typedef enum {
    PRIORIDAD_BAJA,
    PRIORIDAD_MEDIA,
    PRIORIDAD_ALTA
} Prioridad;

typedef struct {
    int id;
    char descripcion[256];
    Prioridad prioridad;
    int horaRegistro;
} Ticket;

#endif
