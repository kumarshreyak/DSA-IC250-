######################################################
#This Makefile is created to help IC250 students
#Created By:
#Aditya Nigam
#SCEE
#IIT Mandi
#Please modify according to your need
######################################################

inc =  -lm

all: my_func.o qstack.o
	gcc -w -o my_exe my_func.o qstack.o -Wno-deprecated -I ${inc}

my_func.o: my_lib.h my_func.c
	gcc -c my_func.c -Wno-deprecated -I ${inc}

qstack .o: my_lib.h qstack.c
	gcc -c qstack.c -Wno-deprecated -I ${inc}

clean:
	rm -f *.o

