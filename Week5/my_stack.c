/*
 * C Program to Implement a Stack using Linked List
 */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
}*top,*top1,*temp;



int count = 0;

/* Create empty stack */
void creates()
{
    top = NULL;
}

/* Count stack elements */
int stack_count()
{
    return count;
}

/* Push data into stack */
void pushs(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}

/* Display stack elements */
void display()
{
    top1 = top;

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
int pops()
{
    int tempr;
    top1 = top;

    if (top1 == NULL)
    {
        printf("\n Error : Trying to pop from empty stack");
        return -1;
    }
    else
        top1 = top1->ptr;
    tempr=top->info;
    //printf("\n Popped value : %d", top->info);
    free(top);
    top = top1;
    count--;
    return tempr;
}

/* Return top element */
int topelement()
{
    return(top->info);
}

/* Check if stack is empty or not */
int emptys()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

// /* Destroy entire stack */
// void destroy()
// {
//     top1 = top;

//     while (top1 != NULL)
//     {
//         top1 = top->ptr;
//         free(top);
//         top = top1;
//         top1 = top1->ptr;
//     }
//     free(top1);
//     top = NULL;

//     printf("\n All stack elements destroyed");
//     count = 0;
// }