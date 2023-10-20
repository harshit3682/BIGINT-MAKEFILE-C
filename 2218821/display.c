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

void display(struct BigInt *num)
{
    struct node *temp = num->head;
    printf("\nOutput: ");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    
}
