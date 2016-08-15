/*input
1
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    // clock_t begin=clock();
    /*CODE HERE */
    FILE *fp;
    int choice,row,column,temp=0,countA=0,countB=0;
    long double meanA=0,meanB=0,stddevA,stddevB,di,countr;
    long long len;
    char *buff;
   /* printf("Enter the image number for which you wish to do thresholding :\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:*/
            row=198,column=200;
            int data[row*column],count[256]={0};
            printf("Reading the input data...\n\n");
            clock_t begin=clock();
            fp=fopen("1.txt","r");
            while(fscanf(fp,"%d",(data+temp))!=EOF)
            {
                temp++;
            }
            fclose(fp);
            clock_t end=clock();
            double time_spent =(double)(end-begin)/1000.0;
            printf("Data read in %lfms\n",time_spent);
            data[temp]=0;
            for (int i = 0; i < temp; ++i)
            {
                count[data[i]]++;
            }
        fp=fopen("result.txt","w");
            printf("Performing iterative thresholding...\n\n");
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
                    stddevA+=pow(j-meanA,2)/(double)countA;
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
                    stddevB+=pow(j-meanB,2)/(double)countB;
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
            printf("result.txt is genrated\n");
           // break;



    //}
    /*CODE ENDS */
    // clock_t end=clock();
    // double time_spent =(double)(end-begin);// Time spent in ms
    return 0;
}
