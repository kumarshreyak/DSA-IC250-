#include "my_lib.h"

void insertAtBottom(int item)
{
    if (emptys())
        pushs(item);
    else
    {

        int temp = pops();
        insertAtBottom(item);

        /* Once the item is inserted at the bottom, push all
           the items held in Function Call Stack */
        pushs(temp);
    }
}

void revstack(){
    int temp1;
    if(!emptys()){
        // return topelement();
        temp1=pops();
        revstack();
        insertAtBottom(temp1);
    }
}



int main(int argc, char const *argv[])
{
    int a,b;
    creates();
    while(1){
        printf("1.Push\n2.Pop\n3.Reverse\n4.Display\n");
        scanf("%d",&a);
        switch(a){
            case 1:
                printf("Enter Data\n");
                scanf("%d",&b);
                pushs(b);
                break;
            case 2:
                b=pops();
                printf("Popped value = %d\n",b);
                break;
            case 3:
                revstack();
                break;
            case 4:
                display();
                break;
        }
    }
    return 0;
}