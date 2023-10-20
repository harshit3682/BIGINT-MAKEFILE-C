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

struct BigInt *Sum(struct BigInt *num1, struct BigInt *num2)
{
    int c = 0, s;
    struct BigInt *output = (struct BigInt *)malloc(sizeof(struct BigInt));
    if (output == NULL)
    {
        printf("Memory not allocated\n");
        exit(1);
    }
    output->head = NULL;
    struct node *n1 = num1->tail;
    struct node *n2 = num2->tail;

    while (n1 != NULL || n2 != NULL)
    {
        if (n1 != NULL && n2 != NULL)
        {
            s = ((n1->data) + (n2->data) + c) % 10;
            c = ((n1->data) + (n2->data) + c) / 10;
            n1 = n1->prev;
            n2 = n2->prev;
        }
        else if (n1 == NULL && n2 != NULL)
        {
            s = ((n2->data) + c) % 10;
            c = ((n2->data) + c) / 10;
            n2 = n2->prev;
        }
        else if (n1 != NULL && n2 == NULL)
        {
            s = ((n1->data) + c) % 10;
            c = ((n1->data) + c) / 10;
            n1 = n1->prev;
        }

        insert_front(output, s);
    }

    if (c != 0)
        insert_front(output, c);

    return output;
}
