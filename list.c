#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List *list =(List*)malloc(sizeof(List));
    list -> head = NULL;
    list -> tail = NULL;
    list -> current = NULL;

    return list;
}
    


void * firstList(List * list) {
    if (!list -> head) return NULL;
    list -> current = list -> head;
    return list -> current ->data;
}

void * nextList(List * list) {
    if (list->current == NULL)return NULL;
    if(list -> current->next==NULL) return NULL;
    list -> current = list -> current->next;
    
    return list -> current ->data;
}

void * lastList(List * list) {
    if (!list || !list->tail) return NULL;
    list->current = list->tail;
    return list->tail->data;
}

void * prevList(List * list) {
    if (!list || !list->current || !list->current->prev) return NULL;
    list->current = list->current->prev;
    return list->current->data;
}

void pushFront(List * list, void * data) {
    if (!list) return;
    Node * new = createNode(data);
    new->next = list->head;
    if (list->head) list->head->prev = new;
    list->head = new;
    if (!list->tail) list->tail = new;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    if (!list || !list->current) return;
    Node * new = createNode(data);
    new->next = list->current->next;
    new->prev = list->current;
    if (list->current->next) list->current->next->prev = new;
    list->current->next = new;
    if (list->current == list->tail) list->tail = new;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    if (!list || !list->current) return NULL;
    Node * temp = list->current;
    void * data = temp->data;
    
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    if (temp == list->head) list->head = temp->next;
    if (temp == list->tail) list->tail = temp->prev;
    
    list->current = temp->next ? temp->next : temp->prev;
    free(temp);
    return data;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}
