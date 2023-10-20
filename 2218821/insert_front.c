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

struct BigInt *insert_front(struct BigInt *output, int val)
{
    struct node *new = create_node(val);
    if (output->head == NULL)
    {
        output->head = output->tail = new;
    }
    else
    {
        new->next = output->head;
        output->head->prev = new;
        output->head = new;
    }

    return output;
}
