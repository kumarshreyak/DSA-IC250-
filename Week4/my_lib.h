#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1,*stack1,*stack2,*top1,*temp;



int frontelement();
void enq(int data);
void ensq(int data);
void deq();
int desq();
void create();
int queuesize();
int topelement1();
void push1(int data);
void pop1();
int empty1();
void display1();
void destroy1();
int qstacksize1();
void create1();
void create2();
int topelement2();
void push2(int data);
void pop2();
int empty2();
void display2();
void destroy2();
int qstacksize2();
int squeuesize();