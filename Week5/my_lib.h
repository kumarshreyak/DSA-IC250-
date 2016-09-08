#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
}*front1,*rear1,*front2,*rear2,*temp,*front11,*top1;



int frontelement();
void enq1(int data);
void enq2(int data);
void deq1();
void deq2();
int empty();
void create();
void swapnames();


int topelement();
void pushs(int data);
int pops();
void display();
int emptys();
int stack_count();
void creates();