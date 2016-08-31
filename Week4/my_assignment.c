#include "my_lib.h"


int main()
{
    int n,eye,temp,tempelem,count=0,choice;                 //eye=another name for "i"
    create1();
    create2();
    //create();
    printf("1.Normal queue \n2.Queue based on stacks\n");
    scanf("%d",&choice);
    printf("Please enter values of n and i : \n");
    scanf("%d %d",&n,&eye);
    temp=eye-1;
    printf("The removal sequence is as follows-\n");
    switch(choice){
        case 1:
            for (int i = 1; i <= n; ++i)
            {
                enq(i);
            }
            while(queuesize()>1){
                while((temp--) > 0){
                    tempelem=frontelement();
                    deq();
                    enq(tempelem);
                }
                printf("The person at position %d is removed\n",frontelement());
                deq();
                temp=eye-1;
            }
            printf("Hence the person at position %d survives. (WINNER)\n",frontelement());
            break;
        case 2:
            for (int i = 1; i <= n; ++i)
            {
                ensq(i);
            }

            while(squeuesize()>1){
                while((temp--) > 0){

                    tempelem=desq();
                    ensq(tempelem);
                    printf("Stack 1 : ");
                    display1();
                    printf("Stack 2 : ");
                    display2();
                }
                if(empty2()){
                    desq();
                    printf("The person at position %d is removed\n",topelement2());
                }else{
                    printf("The person at position %d is removed\n",topelement2());
                    desq();
                }
                temp=eye-1;
            }
            if(empty2())
                printf("Hence the person at position %d survives. (WINNER)\n",topelement1());
            else
                printf("Hence the person at position %d survives. (WINNER)\n",topelement2());
            break;
    }



    return 0;
}