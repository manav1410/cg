#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include "C:\USERS\HP\DESKTOP\CG\BRESN.C"
//Global variables.
	float frame_penx,frame_peny;
	int eraseFlag=0;
//arrays of display fileg.
	float df_op[50];
	float df_x[50];
	float df_y[50];
//variables for display file.
	int ptr=1;
	float df_penx=0,df_peny=0;
	float op,x,y;
//minimum function.
float mint(float a,float b)
{
	if(a<b)
		return a;
	else
		return b;
}
//maximum function
float maxt(float a,float b)
{
	if(a>b)
		return a;
	else
		return b;
}
void traceFile()
{
	FILE *fptr;
	int i;
	fptr=fopen("DISFILE.TXT","w");
	fprintf(fptr,"\nNO  Op   X   Y \n\n");
	for(i=0;i<=ptr+1;i++)
	{
		fprintf(fptr,"\n%2d %4f %4f %4f",i,df_op[i],df_x[i],df_y[i]);
	}
	fclose(fptr);
}
//round function
int round(float a)
{
	return (int)(a+0.5);
}
//putpoint function.
void putpoint(float op,float x,float y)
{
	if(ptr>50)
	{
		printf("\nDisplay file full");
		getch();
		exit(0);
	}
	df_op[ptr]=op;
	df_x[ptr]=x;
	df_y[ptr]=y;
}
//Display File Enter routine.
void disFileEnter(float op)
{
	putpoint(op,df_penx,df_peny);
}
//Move Absolute.
void move_abs(float x,float y)
{
	df_penx=x;
	df_peny=y;
	disFileEnter(1);
}
//Move Relative.
void move_rel(float dx,float dy)
{
	df_penx+=dx;
	df_peny+=dy;
	disFileEnter(1);
}
//Line Absolute.
void line_abs(float x,float y)
{
	df_penx=x;
	df_peny=y;
	disFileEnter(2);
}
//Line Relative.
void line_rel(float dx,float dy)
{
	df_penx+=dx;
	df_peny+=dy;
	disFileEnter(2);

}
//getpoint routine.
void getpoint(int n)
{
	op=df_op[n];
	x=df_x[n];
	y=df_y[n];
}
//domove routine
void domove()
{
	frame_penx=maxt(0,mint(639,x*639));
	frame_peny=maxt(0,mint(479,y*479));
}
//doline routine
void doline()
{
	float x1=frame_penx;
	float y1=frame_penx;
	frame_penx=maxt(0,mint(639,x*639));
	frame_peny=maxt(0,mint(479,y*479));
	bresn(round(x1),round(y1),round(frame_penx),round(frame_peny),1);
}
//new frame
void newFrame()
{
	eraseFlag=1;
}
//routine to erase the screen.
void erase()
{
	int i,j;
	for(i=0;i<640;i++)
		for(j=0;j<480;j++)
			putpixel(i,j,0);

}
//main routine which executes display file.
void interpret(int start,int count)
{
	int n;
	for(n=start;n<=count;n++)
	{
		getpoint(n);
		if(op==1)
			domove();
		else if(op==2)
			doline();
		else
		{
			printf("\nWrong OPcode.");
			exit(0);
		}
	}
}
//make picture current.
void makePicture()
{
//	if(eraseFlag==1)
//	{
//		erase();
//	}
	eraseFlag=0;
	if(ptr>1)
		interpret(1,ptr-1);
	ptr=1;
}
void initialize()
{
	ptr=1;
	df_penx=0;
	df_peny=0;
	frame_penx=0;
	frame_peny=0;
}
//main routine.
void main()
{
	screen();
	initialize();
	newFrame();
	move_abs(0.1,0.1);
	line_abs(0.4,0.5);
	line_abs(0.3,0.5);
//	bresn(100,200,300,400,1);
	makePicture();
	printf("Program is running");
	traceFile();
getch();
}


