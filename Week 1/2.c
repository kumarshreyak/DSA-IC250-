#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    FILE * fp;
    int temp=0,marks[5]={0},sum=0;
    char rno[6],buff[10000],find[6],name1[30],name2[30],grade[5];
    printf("Enter the roll number\n");
    scanf("%s",rno);
    fp = fopen("master.txt","r");
    if(fp == NULL){
        printf("hi\n");
    }
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while((read = getline(&line,&len,fp))!=-1){
        for(int i=0;i<6;i++){
            find[i]=line[i];
        }
        if(strcmp(find,rno)==0)
            break;
    }
    line+=7;
    while(*line!=' '){      //Reading First name
        name1[temp]=*line;
        temp++;
        line++;
    }
    line++;
    temp=0;
    while(*line!=' '){      //Reading Second Name
        name2[temp]=*line;
        temp++;
        line++;
    }
    line++;
    temp=0;
    while(*line!=' '){
        marks[0]*=10;       //Marks of IC250
        marks[0]+=(*line-'0');
        line++;
    }
    line++;
                //Grade of IC250
    grade[0]=*line;
    temp++;
    line+=2;

    while(*line!=' '){      //Marks of CS250
        marks[1]*=10;
        marks[1]+=(*line-'0');
        line++;
    }
    line++;
                //Grade of CS250
    grade[1]=*line;
    temp++;
    line+=2;

    while(*line!=' '){      //Marks of EE225
        marks[2]*=10;
        marks[2]+=(*line-'0');
        line++;
    }
    line++;
                //Grade of EE225
    grade[2]=*line;
    temp++;
    line+=2;

    while(*line!=' '){      //Marks of ME251
        marks[3]*=10;
        marks[3]+=(*line-'0');
        line++;
    }
    line++;
                //Grade of ME251
    grade[3]=*line;
    temp++;
    line+=2;

    while(*line!=' '){      //Marks of CE250
        marks[4]*=10;
        marks[4]+=(*line-'0');
        line++;
    }
    line++;
                //Grade of CE250
    grade[4]=*line;
    temp++;
    fclose(fp);
    printf("\t\tIndian Institute of Technology Mandi\n");								//Printing the result in the required format
    printf("\t\tAcademic Session : (Aug-Dec) 2016\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Name of the Student : %s %s\n",name1,name2);
    printf("Roll Number : %s\n",rno );
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Sr. No  |  Subject Code  |  Maximum  |  Marks Obtained | Grade\n");
    printf("[1]   IC250   100   %d   %c\n",marks[0],grade[0]);
    printf("[2]   CS250   100   %d   %c\n",marks[1],grade[1]);
    printf("[3]   EE255   100   %d   %c\n",marks[2],grade[2]);
    printf("[4]   ME251   100   %d   %c\n",marks[3],grade[3]);
    printf("[5]   CE250   100   %d   %c\n",marks[4],grade[4]);
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    sum=marks[0]+marks[1]+marks[2]+marks[3]+marks[4];
    printf("\t\tTotal 450   Total %d\n\n",sum );
    sum=((double)sum/450.0)*100;
    if(sum>=60){
        printf("\t\tPercentage %d  Student passed with First division\n",sum);
    }else if(sum<60&&sum>=45){
        printf("\t\tPercentage %d Student passed with Second division\n",sum);
    }else if(sum<45&&sum>=30){
        printf("\t\tPercentage %d Student passed with Third division\n",sum);
    }else{
        printf("\t\tFailed !!\n",);
    }
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    return 0;
}
