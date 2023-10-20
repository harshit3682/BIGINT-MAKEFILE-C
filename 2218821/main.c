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

void main()
{
    struct node *head = NULL;
    int ch;
     char str1[] = "123456789123456789123456789123456789123456789123456789";
     char str2[] = "456789123456789123456789123456789123456789123456789";
    
     struct BigInt *n1 = initialize(str1);
     struct BigInt *n2 = initialize(str2);
    
    printf("\nString 1 in reversed form: ");
    display(n1);
    printf("\n\nString 2 in reversed form: ");
    display(n2);
    
    printf("\n\nAddition is: ");
       struct BigInt*add=Sum(n1, n2);
       display(add);
     //  freeBigInt(Sum);
     printf("\n\nSubtraction is:");
      struct BigInt*sub=Sub(n1, n2);
      display(sub);
      //freeBigInt(Sub);
     
      printf("\n\nMultiplication is: ");
      struct BigInt*mul=Product(n1, n2);
      display(mul);
      //freeBigInt(mul);
            
      printf("\n\nDivision is: ");      
      struct BigInt*div=Divide(n1, n2);
      display(div);
      //freeBigInt(div);
     

 /*   do
    {
        printf("\n\n1.ADD\n2.SUBTRACT\n3.Multiply\n4.Quotient\n5.Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            struct BigInt *add = Sum(n1, n2);
            printf("\nSum is: ");
            display(add);
            freeBigInt(add);
            break;
        }

        case 2:
        {
            struct BigInt *sub = Sub(n1, n2);
            printf("\n\nSubtraction is: ");
            display(sub);
            freeBigInt(sub);
            break;
        }

        case 3:
        {
            struct BigInt *mul = Product(n1, n2);
            printf("\n\nProduct is: ");
            display(mul);
            freeBigInt(mul);
            break;
        }

        case 4:
        {
            struct BigInt *div = Divide(n1, n2);
            printf("\n\nQuotient is : ");
            display(div);
            //   freeBigInt(div);
            break;
        }

        case 5:
        {
            printf("Exitting....");
            freeBigInt(n1);
            freeBigInt(n2);

            // freeBigInt(quotient);
            // freeBigInt(remainder);

            exit(0);
        }
        }
    } while (ch != 5);*/
}
