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

struct BigInt *Product(struct BigInt *num1, struct BigInt *num2)
{
    struct BigInt *output = (struct BigInt *)malloc(sizeof(struct BigInt));
    if (output == NULL)
    {
        printf("Memory not allocated\n");
        exit(1);
    }
    output->head = NULL;
    output->tail = NULL;

    struct node *n1 = num1->tail;
    struct node *n2 = num2->tail;

    struct node *zeroNode = create_node(0);
    output->head = output->tail = zeroNode;

    int position = 0;

    while (n2 != NULL)
    {
        int carry = 0;
        struct node *n1_copy = n1;
        struct BigInt *partialResult = (struct BigInt *)malloc(sizeof(struct BigInt));
        if (partialResult == NULL)
        {
            printf("Memory not allocated\n");
            exit(1);
        }
        partialResult->head = NULL;
        partialResult->tail = NULL;

        while (n1_copy != NULL)
        {
            int product = (n1_copy->data) * (n2->data) + carry;
            carry = product / 10;
            int digit = product % 10;
            insert_front(partialResult, digit);
            n1_copy = n1_copy->prev;
        }

        if (carry != 0)
            insert_front(partialResult, carry);

        for (int i = 0; i < position; i++)
        {
            insert_end(partialResult, 0);
        }

        output = Sum(output, partialResult);
        freeBigInt(partialResult);

        position++;
        n2 = n2->prev;
    }

    return output;
}
