#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE *fp;
    int choice,row,column,temp1=0,temp2=0,countA=0,countB=0,temp=0;
    long double meanA=0,meanB=0,stddevA,stddevB,di,countr;
    long long len;
    char *buff;
    row=20000,column=20000;
    int *data[row],count[256]={0};
    for (int i = 0; i < row; ++i)								//Dynamically allocating an array
    {
        data[i] = (int *)malloc(sizeof(int)*column);
    }
    printf("Reading the input data...\n\n");
    printf("Enter file number\n");
    scanf("%d",&choice);
    clock_t begin=clock();
    switch(choice){
		case 1:
			fp=fopen("1.txt","r");
			break;
		case 2:
			fp=fopen("2.txt","r");
			break;
		case 3:
			fp=fopen("3.txt","r");
			break;
    }
    while(fscanf(fp,"%d",&temp)!=EOF)							//Reading from file
    {
       	data[temp1][temp2]=temp;
       	//printf("%d ",data[temp1][temp2]);
        temp2++;
        if(temp2==column-1){
            temp2=0;
            temp1++;
        }
        count[temp]++;
    }
   // printf("%d",count[0]);
    //printf("\n\n%d %d\n\n",temp1,temp2);
    fclose(fp);
    clock_t end = clock();
    double time_spent = (double)(end-begin)/1000.0;
    printf("Data read in %lfms\n",time_spent);
    /*for (int i = 0; i < temp1; ++i)
    {
        for (int j = 0; j < temp2; ++j)
        {
            count[data[i][j]]++;
        }
    }*/
	fp=fopen("result.dat","w");
	fprintf(fp,"%s %s %s\n","Th","D.I","nA:nB");
	printf("Enter your choice\n1.Histogram method\n2.Cumulative Histogram method\n");
	scanf("%d",&choice);
	if(choice==1){
		printf("Performing iterative thresholding using 1st method...\n\n");
		begin=clock();
		for (int i = 1; i < 256; ++i)
		{
		    countA=0,countB=0,meanA=0,meanB=0,stddevA=0,stddevB=0;
		    for (int j = 0; j < i; ++j)             //Counting elements less than threshold and their mean
		    {
		        countA+=count[j];
		        meanA+=count[j]*j;
		    }
		    meanA=(double)meanA/(double)countA;
		    for (int j = 0; j < i; ++j)             //Calculating std. deviation for first cluster
		    {
		        stddevA+=(double)(count[j]*pow(j-meanA,2))/(double)countA;
		    }
		    stddevA=sqrtl(stddevA);
		    for (int j = 255; j >= i; --j)      //Counting elements more than threshold and their mean
		    {
		        countB+=count[j];
		        meanB+=count[j]*j;
		    }
		    meanB=(double)meanB/(double)countB;
		    for (int j = 255; j >= i; --j)          //Calculating std. deviation for second cluster
		    {
		        stddevB+=(double)(count[j]*pow(j-meanB,2))/(double)countB;
		    }
		    stddevB=sqrtl(stddevB);
		    di=abs(meanA-meanB)/sqrtl(stddevA*stddevA+stddevB*stddevB);
		    countr=(double)countA/(double)countB;
		    fprintf(fp,"%d %Lf %Lf\n",i,di,countr);
		}
		fclose(fp);
		end=clock();
		time_spent =(double)(end-begin)/1000.0;
		printf("Thresholding done in %lfms\n",time_spent);
		printf("result.dat is genrated\n");
		
	}else{
		printf("Performing iterative thresholding using 2nd method...\n\n");
		countA=0,countB=0,meanA=0,meanB=0,stddevA=0,stddevB=0,count[256]=0;
		for (int i = 0; i < 256; ++i)
	    {
	        count[i+1]+=count[i];
	    }
		begin=clock();
		for (int i = 1; i < 256; ++i)
		{
		    countA=count[i-1],countB=count[256]-count[i-1],meanA=0,meanB=0,stddevA=0,stddevB=0;
		    for (int j = 1; j < i; ++j)             //Counting elements less than threshold and their mean
		    {
		        meanA+=(count[j]-count[j-1])*j;
		    }
		    meanA=(double)meanA/(double)countA;
		    for (int j = 1; j < i; ++j)             //Calculating std. deviation for first cluster
		    {
		        stddevA+=(double)((count[j]-count[j-1])*pow(j-meanA,2))/(double)countA;
		        //printf("%d ",j);
		    }
		    stddevA=sqrtl(stddevA);
		    for (int j = 255; j >= i; --j)      //Counting elements more than threshold and their mean
		    {
		        meanB+=(count[j]-count[j-1])*j;
		    }
		    meanB=(double)meanB/(double)countB;
		    for (int j = 255; j >= i; --j)          //Calculating std. deviation for second cluster
		    {
		        stddevB+=(double)((count[j]-count[j-1])*pow(j-meanB,2))/(double)countB;
		    }
		    stddevB=sqrtl(stddevB);
		    di=abs(meanA-meanB)/sqrtl(stddevA*stddevA+stddevB*stddevB);
		    countr=(double)countA/(double)countB;
		    fprintf(fp,"%d %Lf %Lf\n",i,di,countr);
		}
		fclose(fp);
		end=clock();
		time_spent =(double)(end-begin)/1000.0;
		printf("Thresholding done in %lfms\n",time_spent);
		printf("result.dat is genrated\n");

	
	}
    	return 0;
}
