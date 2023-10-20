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

struct BigInt *Sub(struct BigInt *num1, struct BigInt *num2)
{
    int borrow = 0, s;
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
            if ((n1->data) + borrow >= (n2->data))
            {
                s = ((n1->data) + borrow - (n2->data));
                borrow = 0;
            }
            else
            {
                s = ((n1->data) + borrow + 10 - (n2->data));
                borrow = -1;
            }
            n1 = n1->prev;
            n2 = n2->prev;
        }
        else if (n1 != NULL && n2 == NULL)
        {
            if (n1->data >= 1)
            {
                s = ((n1->data) + borrow);
                borrow = 0;
            }
            else
            {
                if (borrow != 0)
                {
                    s = ((n1->data) + 10 + borrow);
                    borrow = -1;
                }
                else
                    s = n1->data;
            }
            n1 = n1->prev;
        }
        insert_front(output, s);
    }
}
