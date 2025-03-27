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
    List* lista = (List*)malloc(sizeof(List));
    assert(lista != NULL);
    lista->head = NULL;
    lista->tail = NULL;
    lista-> current = NULL;
     return lista;
}

void * firstList(List * list) {
    if (list->head == NULL) return NULL;
    list->current = list->head;
    return list->head->data;
}

void * nextList(List * list) {
    if (list->head == NULL || list->current == NULL || list->current->next == NULL) return NULL;
    list->current = list->current->next;
    return list->current->data;
}

void * lastList(List * list) {
    while (list->current->next != NULL)
    {
        list->current = list->current->next;
    }
    return list->current->data;
}

void * prevList(List * list) {
    if (list->current != NULL) list->current = list->current->prev;
    if (list->current != NULL) return list->current->data;
    return NULL;
}

void pushFront(List * list, void * data) {
    Node* newNodo = createNode(data);
    if (list->head == NULL)
    {
        list->current = newNodo;
        list->tail = newNodo;
    }
    else
    {
        list->head->prev = newNodo;
        newNodo->next = list->head;
    }
    list->head = newNodo;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    Node* izq = list->current;
    Node* der = list->current->next;
    Node* nuevo = createNode(data);
    if (der == NULL)
    {
        nuevo->next = NULL;
        list->tail = nuevo;
    }
    else
    {
        nuevo->next = der;
        der->prev = nuevo;
    }
    nuevo->prev = izq;
    izq->next = nuevo;
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
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}