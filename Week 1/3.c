#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	int a[101]={0},temp=2;
	for (int i = 1; i <= 100; ++i)		//Making an array filled with numbers from 1 to 100 (a[1]=1,a[2]=2.....)
	{
	    a[i]=i;
	}
	for (int i = 2; i <= 10; ++i)
	{
	if(a[i]!=0){				//Assigning 0 to the multiples of numbers that are not already zero(i.e prime numbers)
	    while(temp*i<=100){
		a[temp*i]=0;
		temp++;
	    }
	}
	temp=2;
	}
	for (int i = 1; i <= 100; ++i)		//Printing the prime numbers(numbers that are not 0)
	{
	if(a[i]!=0)
	    printf("%d ",a[i]);
	}
	return 0;
}
