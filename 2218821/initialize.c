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


struct BigInt *initialize(char *str)
{
    int l = strlen(str);
    struct BigInt *bigint = (struct BigInt *)malloc(sizeof(struct BigInt));
    if (bigint == NULL)
    {
        printf("\nMemory not allocated!");
        exit(1);
    }
    bigint->head = NULL;
    for (int i = 0; i < l; i++)
    {
        int digit = str[i] - '0';
        struct node *newNode = create_node(digit);
        if (bigint->head == NULL)
        {
            bigint->head = bigint->tail = newNode;
        }
        else
        {
            bigint->tail->next = newNode;
            newNode->prev = bigint->tail;
            bigint->tail = newNode;
        }
    }
    return bigint;
}
