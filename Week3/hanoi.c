/*input
2
3
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

struct stack
{
    int capacity;
    int indexOfTop;
    int *ptr;
};

//int count=0;

//int topelement(struct stack *top);
void push(struct stack *top,int data);
int pop(struct stack *top);
int empty(struct stack *top);
void display(struct stack *top);
void destroy(struct stack *top);
//void stack_count();
struct stack* create(int n);

void recursion(int n, int source,int dest,int aux){
    if(n==1){
        printf("Move the plate from %d to %d\n",source,dest);
    }else{
        recursion(n-1,source,aux,dest);
        printf("Move the plate from %d to %d\n",source,dest);
        recursion(n-1,aux,dest,source);
    }
}

void moveDisks(struct stack *src,
            struct stack *dest, char s, char d)
{
    int pole1Top = pop(src);
    int pole2Top = pop(dest);
    //printf("%d %d\n",pole1Top,pole2Top);
    // When pole 1 is empty
    if (pole1Top == -1)
    {
        push(src, pole2Top);
        printf("Move the plate from %c to %c\n",d,s);
    }

    // When pole2 pole is empty
    else if (pole2Top == -1)
    {
        push(dest, pole1Top);
        printf("Move the plate from %c to %c\n",s,d);
    }

    // When top disk of pole1 > top disk of pole2
    else if (pole1Top > pole2Top)
    {
        push(src, pole1Top);
        push(src, pole2Top);
        printf("Move the plate from %c to %c\n",d,s);
    }

    // When top disk of pole1 < top disk of pole2
    else
    {
        push(dest, pole2Top);
        push(dest, pole1Top);
        printf("Move the plate from %c to %c\n",s,d);
    }
}

void iterative(int n){
    long long steps = pow(2,n)-1;
    char s='1',a='2',d='3',temp;
    struct stack *source,*aux,*dest;
    int topelem=0;
    source=create(n);
    aux=create(n);
    dest=create(n);
        //printf("%d %d\n",source->indexOfTop,source->capacity);
    //Making the tower of hanoi in the source peg

    for (int i = n; i >= 1; --i)
    {
        push(source,i);
    }
    //printf("hi\n");
    //Iterative Algorithm
    if(n%2==0){
        temp=d;
        d=a;
        a=temp;
    }

    for (int i = 1; i <= steps; ++i)
    {
        if(i%3==1){
            moveDisks(source,dest,s,d);
        }else if(i%3==2){
            moveDisks(source,aux,s,a);
        }else if(i%3==0){
            moveDisks(aux,dest,a,d);
        }
    }

}

int main()
{
    int choice,n;
    printf("1.Recursion\n2.Iterative\n");
    scanf("%d",&choice);
    scanf("%d",&n);
    if(choice==1){
        recursion(n,1,3,2);
    }else{
        iterative(n);
    }
    return 0;
}

/* Create empty stack */
struct stack* create(int n)
{
    struct stack *top;
    top=(struct stack*)malloc(sizeof(struct stack*));
    top->indexOfTop=-1;
    top->capacity=n;
    top->ptr=(int*)malloc(n*sizeof(int));
    return top;

}

// /* Count stack elements */
// void stack_count()
// {
//     printf("\n No. of elements in stack : %d", count);
// }

/* Push data into stack */
void push(struct stack *top,int data)
{
    //printf("%d %d\n",top->indexOfTop,top->capacity);
    if(top->indexOfTop!=top->capacity){
        top->indexOfTop+=1;
        top -> ptr[top->indexOfTop]=data;
    }
    //count++;
}

/* Display stack elements */
// void display(struct stack &top)
// {
//     top1 = top;

//     if (top1->indexOfTop == -1)
//     {
//         printf("Stack is empty");
//         return;
//     }

//     while (top1->ptr != NULL)
//     {
//         printf("%d ", top1->indexOfTop);
//         top1 = top1->ptr;
//     }
//  }

/* Pop Operation on stack */
int pop(struct stack *top)
{
    if(top->indexOfTop==-1)
        return -1;
    else
        return top -> ptr[top -> indexOfTop--];
}

/* Return top element */
// int topelement(struct stack *top)
// {

// }

/* Check if stack is empty or not */
int empty(struct stack *top)
{
    if (top->indexOfTop == -1)
        return 1;
    else
        return 0;
}

/* Destroy entire stack */
// void destroy(struct stack &top)
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

//     //printf("\n All stack elements destroyed");
//     //count = 0;
// }
