/*
		README.md
		---------
	This program is for displaying graphics on screen with the help of
display file. Please follow the instructions given below before running the
program or else, you may face some errors.

INSTRUCTIONS..

1. The program comes with its module BRESN.C which has bresenham line
   drawing algo. copy that program into C:/TURBOC3/BIN/ folder.
2. Ignore the traceFile() routine, it is not necessary for the program.

DEVELOPED BY,
Manav Patel
Github : https://github.com/manaviyu

*/
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include"C:/TURBOC3/BIN/BRESN.C"
#define round(a) (int)(a+0.5)
#define dfSize 25
//global variables.
	float framex, framey, eraseFlag=0;
//buffers.
	float dfo[dfSize];
	float dfx[dfSize];
	float dfy[dfSize];
//ptr
	int ptr=1;
//pen coordinates.
	float dfpenx, dfpeny;
//usual coordinates.
	float op,x,y;

//Routine to trace the program in seprate text file. Ignore this routine.
void traceFile()
{
	FILE *fptr;
	int i;
	fptr=fopen("DISFILE.TXT","w");
	fprintf(fptr,"\nNO Op   X    Y \n\n");
	for(i=1;i<=ptr;i++)
	{
		fprintf(fptr,"\n%2d %2.0f  %2.1f  %2.1f",i,dfo[i],dfx[i],dfy[i]);
	}
	fclose(fptr);
}

//routine to insert instructions in buffers.
void putpoint(float cmd)
{
	if(ptr>dfSize)
	{
		printf("\nDisplay file full");
		exit(0);
	}
	dfo[ptr] = cmd;
	dfx[ptr] = dfpenx;
	dfy[ptr] = dfpeny;
	ptr++;
}
//routine to identify instruction and put in buffers.
void disFileEnter(float cmd)
{
	putpoint(cmd);
}
//routines to move the cursor for normalized screen.
void moveAbs(float tempx, float tempy)
{
	dfpenx = tempx;
	dfpeny = tempy;
	disFileEnter(1);
}
void moveRel(float dx, float dy)
{
	dfpenx += dx;
	dfpeny += dy;
	disFileEnter(1);
}

//routines to draw the line in normalized screen.
void lineAbs(float tempx, float tempy)
{
	dfpenx = tempx;
	dfpeny = tempy;
	disFileEnter(2);
}
void lineRel(float dx, float dy)
{
	dfpenx += dx;
	dfpeny += dy;
	disFileEnter(2);
}

//routine to fetch the data into variables.
void getpoint(int n)
{
	op = dfo[n];
	x  = dfx[n];
	y  = dfy[n];
}

//routine to move the cursor in actual screen.
void domove()
{
	framex = max(0,min(639,x*639));
	framey = max(0,min(479,y*479));
}
//routine to draw the line in actual screen.
void doline()
{
	float tempx, tempy;
	tempx = framex;
	tempy = framey;
	framex = max(0,min(639,x*639));
	framey = max(0,min(479,y*479));
	bresn(round(tempx),round(tempy),round(framex),round(framey),1);
}
//to take a new screen.
void newFrame()
{
	eraseFlag = 1;
}
//to fetch the instructions from buffer.
void interpret()
{
	int i;
	for(i=1;i<ptr;i++)
	{
		getpoint(i);
		if(op==1)
			domove();
		else if(op==2)
			doline();
		else
			printf("\nWrong OP code.");
	}
}
//to erase the screen.
void erase()
{
	int i,j;
	for(i=0;i<640;i++)
		for(j=0;j<480;j++)
			putpixel(i,j,0);
}

//to make the actual picture
void makePicture()
{
	if(eraseFlag)
		erase();
	eraseFlag=0;
	if(ptr>1)
		interpret(1,ptr);
	//ptr=1;
}
//to initialize variables.
void initialize()
{
	ptr=1;
	dfpenx=0;
	dfpeny=0;
	framex=0;
	framey=0;
}
//to draw the house.
void house()
{
	lineRel(0,0.2);
	lineRel(0.1,0.1);
	lineRel(0.1,-0.1);
	lineRel(0,-0.2);
	lineRel(-0.2,0);
}

void main()
{
	screen();
	initialize();
	newFrame();
	moveAbs(0.1,0.1);
	house();
	moveAbs(0.4,0.1);
	house();
	moveAbs(0.7,0.1);
	house();
	makePicture();
	printf("Display File Program..");
	traceFile();
getch();
}

