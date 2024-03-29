#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#define round(a) (int)(a+0.5)


//to run the program, first uncomment the main function at last.
int tracing = 0;
void logA(float x,float y)
{
	FILE *fptr;
	fptr = fopen("DDAlog.txt","a");
	if(fptr==NULL)
	{
		printf("Error in file");
	}
	fprintf(fptr,"\n%4.0f %4.0f",x,y);
	fclose(fptr);

}
void trace()
{
	FILE *fptr;
	tracing=1;
	fptr = fopen("DDAlog.txt","w");
	if(fptr==NULL)
	{
		printf("Error in file");
	}
	fprintf(fptr,"\n\t\t\t---LOG FILE OF DDA---");
	fprintf(fptr,"\n\n  X   Y  \n");
	fclose(fptr);

}
void dda(int xA, int yA, int xB, int yB,int ch)
{
	int dx,dy,steps,i,cnt;
	float x,y,xinc,yinc;

//Line Styles.
	int a[] = {1,1,1,1,1,1,1,1,1,1};
	switch(ch)
	{
		case 2:
			for(i=1;i<10;i+=2)
				a[i]=0;
			break;
		case 3:
			//for(i=3;i<10;i+=4)
				a[0]=0;
				a[5]=0;
			break;
		case 4:
			a[4]=0;
			a[5]=0;
			a[8]=0;
			a[9]=0;
			break;
	}
//main algorithm
	dx = xB-xA;
	dy = yB-yA;

	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);

	x=xA;
	y=yA;

	xinc = (float)dx/steps;
	yinc = (float)dy/steps;

	putpixel(x,getmaxy()-y,3);
	cnt=0;
	for(i=0;i<steps;i++)
	{
		if(tracing==1)
			logA(x,y);
		x+=xinc;
		y+=yinc;
		if(a[cnt])
			putpixel(round(x),round(getmaxy()-y),3);
		cnt++;
		if(cnt==10)
			cnt=0;
	}
}
void screen()
{
	int gdrive = DETECT,gmode;
	initgraph(&gdrive,&gmode,"C:\\TURBOC3\\BGI");
}
void ddat(int xA, int yA,int xB, int yB,int size)
{
	int th,i;
	for(i=0;i<size;i++)
	{
		th = i-size/2;
		if(abs(xA-xB) > abs(yA-yB))
			dda(xA,yA+th,xB,yB+th,1);
		else
			dda(xA+th,yA,xB+th,yB,1);
	}
}
/*
void main()
{
	int ch=3;
clrscr();
	screen();

	//last parameter is linestyle.
	dda(200,200,300,300,1);
	dda(300,300,400,200,1);
	dda(300,300,300,100,1);

	//last parameter is thickness.
	ddat(200,200,400,200,ch);
	ddat(400,200,300,100,ch);
	ddat(300,100,200,200,ch);
getch();
} */