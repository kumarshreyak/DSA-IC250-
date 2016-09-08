#include "my_lib.h"
int main()
{
    int n,countc1=0,countc2=0;
    char tempc;
    printf("Enter the length of the expression\n");
    scanf("%d",&n);
    char a[n];
        countc2=0,countc1=0;
        printf("Enter the expression\n");
        scanf("%s",a);
        // if(a=="."){
        //     return 0;
        // }
        // for (int i = 0; i < n; ++i)
        // {
        //     scanf("%c",&a[i]);
        // }
        for (int i = n-1; i >= 0; --i)
        {
            pushs(a[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            tempc = pops();
            if(tempc=='('){
                countc1++;
            }
            //printf("countc1=%d countc2=%d\n",countc1,countc2);
            if(tempc==')'&&countc1<=countc2){
                countc2+=100000;
            }else if(tempc==')'){
                countc2++;
            }
        }
        if(countc1-countc2==0){
            printf("Brackets balanced\n");
        }else{
            printf("Not balanced\n");
        }

    return 0;
}