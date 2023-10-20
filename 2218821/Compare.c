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


int compareBigInt(struct BigInt *num1, struct BigInt *num2)
{
    int len1 = getLength(num1);
    int len2 = getLength(num2);

    if (len1 < len2)
        return -1;
    else if (len1 > len2)
        return 1;

    struct node *node1 = num1->head;
    struct node *node2 = num2->head;

    while (node1 != NULL && node2 != NULL)
    {
        if (node1->data < node2->data)
            return -1;
        else if (node1->data > node2->data)
            return 1;

        node1 = node1->next;
        node2 = node2->next;
    }

    return 0;
}
