#include <stdio.h>
#include <math.h>

int main(){
    int n;
    double x,sum=0,k;
    printf("Enter the value of x :\n");			//Accepting Values
    scanf("%lf",&x);
    printf("Enter the number of terms n :\n");
    scanf("%d",&n);
    k=(x-1)/x;						//Generating the sequence through a loop
    for (int i = 1; i <= n; ++i)
    {
        sum+=pow(k,i)/i;
    }
    printf("%lf\n",sum);				//Printing the sum
    return 0;
}
