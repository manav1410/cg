#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int m[][5] =   {{1,0,0,0,1},
		{1,1,0,1,1},
		{1,0,1,0,1},
		{1,0,0,0,1},
		{1,0,0,0,1}};
int a[][5] =   {{0,0,1,0,0},
		{0,1,0,1,0},
		{1,1,1,1,1},
		{1,0,0,0,1},
		{1,0,0,0,1}};
int n[][5] =   {{1,0,0,0,1},
		{1,1,0,0,1},
		{1,0,1,0,1},
		{1,0,0,1,1},
		{1,0,0,0,1}};
int v[][5] =   {{1,0,0,0,1},
		{1,0,0,0,1},
		{0,1,0,1,0},
		{0,0,1,0,0},
		{0,0,1,0,0}};
int bx=100,by=100;
void gen(int x[][5])
{
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(x[i][j])
				putpixel(bx+j,by+i,3);
	bx+=10;
}
void main()
{
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"C://TURBOC3//BGI");
	gen(m);
	gen(a);
	gen(n);
	gen(a);
	gen(v);
getch();
}