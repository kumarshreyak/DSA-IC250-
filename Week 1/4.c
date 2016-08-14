#include <stdio.h>
int main(){
    int len1;
    printf("Enter the length of the string\n");			//Accepting the String 
    scanf("%d",&len1);
    char str[len1];
    printf("Enter the string\n");
    scanf("%s",str);
    for (int i = 0; i < len1/2; ++i)				//Comparing the String character by character until we reach the middle or an inequality is found
    {
        if(str[i]!=str[len1-i-1]){
            printf("String is not palindrome\n");		//When one of the conditions is not met
            return 0;
        }
    }
    printf("String is palindrome\n");				//When all the conditons are satisfied
    return 0;
}	
