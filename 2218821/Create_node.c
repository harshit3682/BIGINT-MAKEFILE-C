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


struct node *create_node(int digit)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = digit;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

