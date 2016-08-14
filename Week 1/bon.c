#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    FILE * fp;
    size_t lens=0;
    int tempf=0,temp=0,tempd=0;
    char str1[10000]="",str2[10000]="",data[100][20],word[20];
    fp = fopen("bonus.txt","r");
    if(fp == NULL){							//Protocol on failure to open file
        exit(EXIT_FAILURE);
    }
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while((read = getline(&line,&len,fp))!=-1){				//Reading the file line by line
        strcpy(str2,line);
        strcat(str1,str2);						//concatenating each line into a single string
    }
    lens = strlen(str1);
    str1[lens-1]=' ';							//adding a whitespace to the end of string
    while(tempf<lens){							//loop runs until the end of string has been reached
        if(str1[tempf]==' '||str1[tempf]=='\n'){			//each word is copied into a different string array
            tempf++;
            temp=0;
            strcpy(data[tempd],word);
            memset(word,0,20);
            tempd++;
        }
        word[temp]=str1[tempf];						
        temp++,tempf++;
    }
    for (int i = 0; i < tempd/2; ++i)					//comparing the words in the front to the ones in the back until an inequality is found
    {
        if(strcmp(data[i],data[tempd-i-1])!=0){
            printf("Paragraph is not palindrome\n");			//Not Palindrome if an inequality is found
            return 0;
        }
    }
    printf("Paragraph is palindrome\n");				//Palindrome if all conditions are met
    return 0;
}
