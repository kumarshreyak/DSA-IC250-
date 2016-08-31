/*
 * C Program to Implement a Stack using Linked List
 */
#include "my_lib.h"

int count2 = 0;

/* Create empty stack */
void create2()
{
    stack2 = NULL;
}

/* Count2 stack elements */
int qstacksize2()
{
    return count2;
}

/* Push data into stack */
void push2(int data)
{
    if (stack2 == NULL)
    {
        stack2 =(struct node *)malloc(1*sizeof(struct node));
        stack2->ptr = NULL;
        stack2->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = stack2;
        temp->info = data;
        stack2 = temp;
    }
    count2++;
}

/* Display stack elements */
void display2()
{
    top1 = stack2;

    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }

    while (top1 != NULL)
    {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
    printf("\n");
 }

/* Pop Operation on stack */
void pop2()
{
    top1 = stack2;

    if (top1 == NULL)
    {
        printf("\n Error : Trying to pop from empty stack");
        return;
    }
    else
        top1 = top1->ptr;
    //printf("Popped value : %d\n", stack2->info);
    free(stack2);
    stack2 = top1;
    count2--;
}

/* Return stack2 element */
int topelement2()
{
    return(stack2->info);
}

/* Check if stack is empty or not */
int empty2()
{
    if (stack2 == NULL)
        return 1;
    else
        return 0;
}

/* Destroy entire stack */
void destroy2()
{
    top1 = stack2;

    while (top1 != NULL)
    {
        top1 = stack2->ptr;
        free(stack2);
        stack2 = top1;
        top1 = top1->ptr;
    }
    free(top1);
    stack2 = NULL;

    printf("\n All stack elements destroyed");
    count2 = 0;
}

