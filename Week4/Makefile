######################################################
#This Makefile is created to help IC250 students
#Created By:
#Aditya Nigam
#SCEE
#IIT Mandi
#Please modify according to your need 
######################################################

inc =  -lm 

all: my_func.o my_assignment.o my_stack1.o my_stack2.o qfromstk.o
	gcc -w -o my_exe my_func.o my_assignment.o  my_stack1.o my_stack2.o qfromstk.o -Wno-deprecated -I ${inc} 

my_assignment.o: my_assignment.c
	gcc -c my_assignment.c -Wno-deprecated -I ${inc}

my_func.o: my_lib.h my_func.c
	gcc -c my_func.c -Wno-deprecated -I ${inc}
my_stack1.o: my_lib.h my_stack1.c
	gcc -c my_stack1.c -Wno-deprecated -I ${inc}
my_stack2.o: my_lib.h my_stack2.c
	gcc -c my_stack2.c -Wno-deprecated -I ${inc}
qfromstk .o: my_lib.h qfromstk.c
	gcc -c my_qfromstk.c -Wno-deprecated -I ${inc}	

clean:
	rm -f *.o
