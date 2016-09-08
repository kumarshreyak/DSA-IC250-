/*
 * C Program to Implement Queue Data Structure using Linked List
 */
#include "my_lib.h"


int count1 = 0,count2 = 0;


/* Create an empty queue */
void create()
{
    front1 = rear1 = NULL;
    front2 = rear2 = NULL;
}

/* Returns queue size */
int queuesize()
{
    return count1;
}

/* Enqueing the queue */
void enq1(int data)
{
    if (rear1 == NULL)
    {
        rear1 = (struct node *)malloc(1*sizeof(struct node));
        rear1->ptr = NULL;
        rear1->info = data;
        front1 = rear1;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear1->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;

        rear1 = temp;
    }
    count1++;
}

void enq2(int data)
{
    if (rear2 == NULL)
    {
        rear2 = (struct node *)malloc(1*sizeof(struct node));
        rear2->ptr = NULL;
        rear2->info = data;
        front2 = rear2;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear2->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;

        rear2 = temp;
    }
    count2++;
}
void swapnames(){
    temp=front1;
    front1=front2;
    front2=temp;
    temp=rear1;
    rear1=rear2;
    rear2=temp;
}

/* Displaying the queue elements */
// void display()
// {
//     front1 = front;

//     if ((front1 == NULL) && (rear == NULL))
//     {
//         printf("Queue is empty");
//         return;
//     }
//     while (front1 != rear)
//     {
//         printf("%d ", front1->info);
//         front1 = front1->ptr;
//     }
//     if (front1 == rear)
//         printf("%d", front1->info);
// }

/* Dequeing the queue */
void deq1()
{
    front11 = front1;

    if (front11 == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else
        if (front11->ptr != NULL)
        {
            front11 = front11->ptr;
            //printf("\n Dequed value : %d", front->info);
            free(front1);
            front1= front11;
        }
        else
        {
            //printf("\n Dequed value : %d", front->info);
            free(front1);
            front1 = NULL;
            rear1 = NULL;
        }
        count1--;
}

void deq2()
{
    front11 = front2;

    if (front11 == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else
        if (front11->ptr != NULL)
        {
            front11 = front11->ptr;
            //printf("\n Dequed value : %d", front->info);
            free(front2);
            front2= front11;
        }
        else
        {
            //printf("\n Dequed value : %d", front->info);
            free(front2);
            front2 = NULL;
            rear2 = NULL;
        }
        count2--;
}

/* Returns the front element of queue */
int frontelement()
{
    if ((front1 != NULL) && (rear1 != NULL))
        return(front1->info);
    else
        return -1;
}

/* Display if queue is empty or not */
int empty()
{
     if ((front1 == NULL) && (rear1 == NULL))
        return 1;
    else
        return 0;
}
