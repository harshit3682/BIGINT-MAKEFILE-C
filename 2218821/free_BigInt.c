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

void freeBigInt(struct BigInt *num)
{
    struct node *current = num->head;
    while (current != NULL)
    {
        struct node *temp = current;
        current = current->next;
        free(temp);
    }
    free(num);
}
