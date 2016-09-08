#include "my_lib.h"
int tempr,data1;
void push(int data){
    enq2(data);
    while(empty()!=1){
        tempr=frontelement();
        deq1();
        enq2(tempr);
    }
    swapnames();
}
int pop(){
    if(empty()!=1){
        tempr=frontelement();
        deq1();
        return tempr;
    }else{
        return -1;
    }

}
int main(int argc, char const *argv[])
{
    int a,tymp;
    create();
    while(1){
        printf("\n0.Exit\n1.Push\n2.Pop\n3.Frontelement\n");
        scanf("%d",&a);
        switch(a){
            case 0:
                return 0;
                break;
            case 1:
                printf("Enter data:\n");
                scanf("%d",&data1);
                push(data1);
                break;
            case 2:
                tymp=pop();
                if(tymp==-1){
                    printf("Stack empty\n");
                }else{
                    printf("Popped Value = %d\n",tymp);
                }

                break;
            case 3:
                printf("Front element = %d\n",frontelement());
                break;
        }
    }
    return 0;
}