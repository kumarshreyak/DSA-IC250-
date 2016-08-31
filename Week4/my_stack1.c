/*
 * C Program to Implement a Stack using Linked List
 */
#include "my_lib.h"

int count1 = 0;

/* Create empty stack */
void create1()
{
    stack1 = NULL;
}

/* Count1 stack elements */
int qstacksize1()
{
    return count1;
}

/* Push data into stack */
void push1(int data)
{
    if (stack1 == NULL)
    {
        stack1 =(struct node *)malloc(1*sizeof(struct node));
        stack1->ptr = NULL;
        stack1->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = stack1;
        temp->info = data;
        stack1 = temp;
    }
    count1++;
}

/* Display stack elements */
void display1()
{
    top1 = stack1;

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
void pop1()
{
    top1 = stack1;

    if (top1 == NULL)
    {
        printf("\n Error : Trying to pop from empty stack");
        return;
    }
    else
        top1 = top1->ptr;
    //printf("Popped value : %d\n", stack1->info);
    free(stack1);
    stack1 = top1;
    count1--;
}

/* Return stack1 element */
int topelement1()
{
    return(stack1->info);
}

/* Check if stack is empty or not */
int empty1()
{
    if (stack1 == NULL)
        return 1;
    else
        return 0;
}

/* Destroy entire stack */
void destroy1()
{
    top1 = stack1;

    while (top1 != NULL)
    {
        top1 = stack1->ptr;
        free(stack1);
        stack1 = top1;
        top1 = top1->ptr;
    }
    free(top1);
    stack1 = NULL;

    printf("\n All stack elements destroyed");
    count1 = 0;
}
