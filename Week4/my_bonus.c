#include <stdio.h>
int ans;
int josephus(int n,int i){
    if(n==1){
        return 1;
    }else{
        ans=(josephus(n-1,i)+(i-1))%n+1;
        printf("ans=%d,n=%d,i=%d\n",ans,n,i);
        return ans;
    }

}

int main(){
    int n,i;
    scanf("%d %d",&n,&i);
    printf("Winner is %d !\n",josephus(n,i));
    return 0;
}
