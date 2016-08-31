#include "my_lib.h"

void ensq(int data){
    //printf("Added %d to stack1\n",data);
    push1(data);
    return;
}
int desq(){
    //printf("stack 2 %d\n",empty2());
    int tempe;
   // printf("%d %d\n",empty1(),empty2());
    if(empty1()&&empty2()){
        printf("BOTH STACKS ARE EMPTY\n");
        return 0;
    }
    //printf("%d\n",empty2());
    if(empty2()){
        while(!empty1()){
            tempe=topelement1();
            pop1();
            push2(tempe);
            //printf("Pushed %d to stack2\n",tempe);
        }
    }
    tempe=topelement2();
    pop2();
    return tempe;
}
int squeuesize()
{
    return qstacksize1()+qstacksize2();
}