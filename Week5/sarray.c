#include <stdio.h>
int main()
{
    int n,m,temp=0,temp1;
    printf("Enter the dimensions of the sparse array\n");
    scanf("%d %d",&n,&m);
    int a[n][m],sparse[n*m][3];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%d",&temp1);
            a[i][j]=temp1;

            if(temp1!=0){                 //sparse = {"ROW","COLUMN","VALUE"}
                sparse[temp][0]=i;
                sparse[temp][1]=j;
                sparse[temp][2]=temp1;

                temp++;

            }
           // printf("i=%d,j=%d val=%d\n",i,j,a[i][j]);
        }
    }
    //printf("temp = %d\n",temp);
    for (int i = 0; i < temp; ++i)
    {
       // printf(" x=%d y=%d value=%d ||",sparse[i][0],sparse[i][1],sparse[i][2]);
        temp1=sparse[i][0];                        //Transposing only the non zero elements
        sparse[i][0]=sparse[i][1];
        sparse[i][1]=temp1;
       // printf(" x=%d y=%d value=%d \n",sparse[i][0],sparse[i][1],sparse[i][2]);
        //a[sparse[i][1]][sparse[i][0]]=a[sparse[i][0]][sparse[i][1]];
        //a[sparse[i][1]][sparse[i][0]]=0;
        if(a[sparse[i][0]][sparse[i][1]]!=0)
            a[sparse[i][0]][sparse[i][1]]=sparse[i][2];
        else{
            a[sparse[i][1]][sparse[i][0]]=0;
            a[sparse[i][0]][sparse[i][1]]=sparse[i][2];
        }
    }
    printf("\nHere is the transposed array\n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {

            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}