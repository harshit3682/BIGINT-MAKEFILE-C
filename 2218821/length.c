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

int getLength(struct BigInt *num)
{
    int length = 0;
    struct node *current = num->head;

    while (current != NULL)
    {
        length++;
        current = current->next;
    }

    return length;
}
