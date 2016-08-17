#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int th[256],choice;
    long double di[256],nratio[256];
    FILE *fp;
    FILE * gnuplotPipe = popen ("gnuplot -persistent","w");

    fp=fopen("result.dat","r");
    char * commandsForGnuPlot1[]={"set term x11 1","set title \"Graph\"","plot \"result.dat\" using 1:2 with lines"};
    char * commandsForGnuPlot2[]={"set term x11 1","set title \"Graph\"","plot \"result.dat\" using 1:3 with lines"};
    char * commandsForGnuPlot3[]={"set term x11 1","set title \"Graph\"","plot \"result.dat\" using 2:3 with lines"};
    printf("Select Graph\n1.th Vs d'\n2.th Vs Np\n3.d' Vs Np\n");
    scanf("%d",&choice);
    switch(choice){
    	case 1:
    		for (int i = 0; i < 3; ++i)
			{
				fprintf(gnuplotPipe,"%s \n",commandsForGnuPlot1[i]);
			}
			break;
		case 2:
    		for (int i = 0; i < 3; ++i)
			{
				fprintf(gnuplotPipe,"%s \n",commandsForGnuPlot2[i]);
			}
			break;
		case 3:
    		for (int i = 0; i < 3; ++i)
			{
				fprintf(gnuplotPipe,"%s \n",commandsForGnuPlot3[i]);
			}
			break;		
    }
    
    fclose(fp);
    pclose(gnuplotPipe);
    fflush(gnuplotPipe);
    return 0;
}
