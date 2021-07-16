#ifndef SOLVING_QUEUE_H
#define SOLVING_QUEUE_H

#include <stdbool.h>
#include <stdlib.h>
#define d_type int

typedef struct node Node;
typedef struct queue Queue;
struct queue {
    Node *sta;
    int size;
};
struct node {
    d_type data;
    Node *next, *prev;
};

Queue *new_queue() {
    Queue *q = (Queue *) malloc(sizeof (Queue));
    q->sta = NULL;

    return q;
}

bool is_queue_empty(Queue *q) {
    if (q->size == 0) return true;
    else return false;
}

void push(Queue *q, d_type data) {
    Node *new_node = (Node *) malloc(sizeof (Node));
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->data = data;

    // if q is empty
    if (is_queue_empty(q)) {

        q->sta = new_node;
        new_node->prev = NULL; // First node..

    } else {
        Node *sta = q->sta;
        while (sta->next != NULL) {
            sta = sta->next;
        }
        sta->next = new_node;
        new_node->prev = sta;
    }
    q->size += 1;
}

Node *pop(Queue *q) {
    if (is_queue_empty(q)) { // empty..
        return NULL;
    } else {
        Node *ret = q->sta;

        if (q->sta->next == NULL) { // delete root...
            q->sta = NULL;
        } else {
            q->sta = q->sta->next;
        }

        q->size -= 1;
        return ret;
    }
}

int get_size(Queue *q) {
    return q->size;
}

d_type pop_value(Queue *q) {
    // @Assert: queue is not empty

    Node *tmp = pop(q);
    return tmp->data;
}

#endif //SOLVING_QUEUE_H
