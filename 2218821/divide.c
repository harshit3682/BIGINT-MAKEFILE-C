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

struct BigInt *Divide(struct BigInt *num1, struct BigInt *num2)
{
    if (num2->head == NULL)
    {
        printf("Division by zero is not allowed.\n");
        exit(1);
    }

    // struct BigInt *quotient = (struct BigInt *)malloc(sizeof(struct BigInt));
    // struct BigInt *remainder = (struct BigInt *)malloc(sizeof(struct BigInt));
    // struct BigInt *tempDividend = (struct BigInt *)malloc(sizeof(struct BigInt));
    struct BigInt *quotient = initialize("0");
    struct BigInt *remainder = initialize("0");

    struct BigInt *tempDividend = initialize("0");
    if (quotient == NULL || remainder == NULL)
    {
        printf("Memory not allocated\n");
        exit(1);
    }

    quotient->head = NULL;
    remainder->head = NULL;
    remainder->head->next = NULL;


    tempDividend->head = NULL;
    tempDividend->tail = NULL; 

    struct node *tempNode = num1->head;
    while (tempNode != NULL)
    {
        insert_end(tempDividend, tempNode->data);
        tempNode = tempNode->next;
    }

    int leadingZero = 1;

    while (compareBigInt(tempDividend, num2) >= 0)
    {
        int quotientDigit = 0;

        while (compareBigInt(tempDividend, num2) >= 0)
        {
            tempDividend = Sub(tempDividend, num2); 
            quotientDigit++;
            leadingZero = 0; 
        }

        if (!leadingZero)
        {
            quotient = insert_end(quotient, quotientDigit);
        }

        while (tempDividend->head != NULL && tempDividend->head->data == 0)
        {
            struct node *temp = tempDividend->head;
            tempDividend->head = tempDividend->head->next;
            free(temp);
        }
    }

    if (leadingZero)
    {
        quotient = insert_end(quotient, 0);
    }

    tempNode = tempDividend->head;
    while (tempNode != NULL)
    {
        remainder = insert_end(remainder, tempNode->data);
        tempNode = tempNode->next;
    }

    freeBigInt(tempDividend);

    return quotient;
}
