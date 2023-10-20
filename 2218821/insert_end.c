#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct BigInt
{
    struct node *head;
    struct node *tail;
};

struct BigInt *insert_end(struct BigInt *position, int val)
{
    struct node *new = create_node(val);
    if (position->head == NULL)
    {
        position->head = position->tail = new;
    }
    else
    {
        position->tail->next = new;
        new->prev = position->tail;
        position->tail = new;
    }

    return position;
}
