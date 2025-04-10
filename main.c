#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ticket.h"
#include "list.h"
#include "nodo.h"
#include "list.c"
Nodo *alta = NULL, *media = NULL, *baja = NULL;

int generar_hora() {
    return (int)time(NULL);
}

void registrar_ticket() {
    Ticket t;
    printf("Ingrese ID del ticket: ");
    scanf("%d", &t.id);
    getchar(); // limpiar buffer
    printf("Ingrese descripción: ");
    fgets(t.descripcion, 256, stdin);
    t.descripcion[strcspn(t.descripcion, "\n")] = 0;
    t.prioridad = PRIORIDAD_BAJA;
    t.horaRegistro = generar_hora();
    insertar_ticket(&baja, t);
    printf("Ticket registrado con prioridad BAJA.\n");
}

void asignar_prioridad() {
    int id, prioridad;
    printf("Ingrese ID del ticket: ");
    scanf("%d", &id);
    printf("Ingrese nueva prioridad (0 = Baja, 1 = Media, 2 = Alta): ");
    scanf("%d", &prioridad);

    Ticket* t = buscar_ticket(baja, id);
    if (t == NULL) t = buscar_ticket(media, id);
    if (t == NULL) t = buscar_ticket(alta, id);

    if (t != NULL) {
        Ticket copia = *t;
        eliminar_ticket_por_id(&baja, id);
        eliminar_ticket_por_id(&media, id);
        eliminar_ticket_por_id(&alta, id);
        copia.prioridad = prioridad;
        if (prioridad == PRIORIDAD_ALTA) insertar_ticket(&alta, copia);
        else if (prioridad == PRIORIDAD_MEDIA) insertar_ticket(&media, copia);
        else insertar_ticket(&baja, copia);
        printf("Prioridad actualizada.\n");
    } else {
        printf("Ticket no encontrado.\n");
    }
}

void mostrar_tickets() {
    mostrar_lista(alta, "Prioridad ALTA");
    mostrar_lista(media, "Prioridad MEDIA");
    mostrar_lista(baja, "Prioridad BAJA");
}

void procesar_siguiente() {
    Nodo** listas[] = {&alta, &media, &baja};
    for (int i = 0; i < 3; ++i) {
        if (*listas[i] != NULL) {
            Ticket t = procesar_ticket(listas[i]);
            printf("Procesando ticket ID: %d\nDescripción: %s\nPrioridad: %d\nHora: %d\n",
                   t.id, t.descripcion, t.prioridad, t.horaRegistro);
            return;
        }
    }
    printf("No hay tickets pendientes.\n");
}

void buscar_ticket_id() {
    int id;
    printf("Ingrese ID a buscar: ");
    scanf("%d", &id);

    Ticket* t = buscar_ticket(baja, id);
    if (t == NULL) t = buscar_ticket(media, id);
    if (t == NULL) t = buscar_ticket(alta, id);

    if (t != NULL) {
        printf("ID: %d\nDescripción: %s\nPrioridad: %d\nHora: %d\n",
               t->id, t->descripcion, t->prioridad, t->horaRegistro);
    } else {
        printf("Ticket no encontrado.\n");
    }
}

int main() {
    int opcion;
    do {
        
        printf("1 Registrar ticket\n");
        printf("2 Asignar prioridad\n");
        printf("3 Mostrar tickets\n");
        printf("4 Procesar siguiente ticket\n");
        printf("5 Buscar ticket por ID\n");
        printf("0 terminar programa\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: registrar_ticket(); break;
            case 2: asignar_prioridad(); break;
            case 3: mostrar_tickets(); break;
            case 4: procesar_siguiente(); break;
            case 5: buscar_ticket_id(); break;
            case 0: printf("FIN\n"); break;
            default: printf("error usar opcion valida\n");
        }
    } while (opcion != 0);
    return 0;
}
