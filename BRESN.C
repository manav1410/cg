#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

//to run the program, first uncomment the main function at last.
int tracing = 0;
void logA(float x,float y)
{
	FILE *fptr;
	fptr = fopen("BRESNlog.txt","a");
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
	fptr = fopen("BRESNlog.txt","w");
	if(fptr==NULL)
	{
		printf("Error in file");
	}
	fprintf(fptr,"\n\t\t\t---LOG FILE OF BRESN---");
	fprintf(fptr,"\n\n  X   Y  \n");
	fclose(fptr);

}

void screen()
{
	int gdrive = DETECT,gmode;
	initgraph(&gdrive,&gmode,"C:/TURBOC3/BGI");
}
void bresn(int xA, int yA, int xB, int yB,int ch)
{
	int dx,dy,twody,twodydx,twodx,twodxdy,p,x,y,xend,yend;
	float m = (float)(yB-yA)/(xB-xA);
	int i,cnt=0;
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

	dx=abs(xA-xB);
	dy=abs(yA-yB);
	if(dx>dy)
	{
		p=2*dy-dx;
		twody=2*dy;
		twodydx=2*(dy-dx);
		if(xA>xB)
		{
			x=xB;
			y=yB;
			xend=xA;
		}
		else
		{
			x=xA;
			y=yA;
			xend=xB;
		}
		putpixel(x,getmaxy()-y,3);
		while(x<xend)
		{
			if(tracing==1)
				logA(x,y);
			x++;
			if(p<0)
			{
				p+=twody;
			}
			else
			{
				if(m<1 && m>0)
					y++;
				else
					y--;
				p+=twodydx;
			}
			if(a[cnt])
				putpixel(x,getmaxy()-y,3);
			cnt++;
			if(cnt==10)
				cnt=0;
		}
	}
	else
	{
		p=2*dx-dy;
		twodx=2*dx;
		twodxdy=2*(dx-dy);
		if(yA>yB)
		{
			x=xB;
			y=yB;
			yend=yA;
		}
		else
		{
			x=xA;
			y=yA;
			yend=yB;
		}
		putpixel(x,getmaxy()-y,3);
		while(y<yend)
		{
			if(tracing==1)
				logA(x,y);
			y++;
			if(p<0)
			{
				p+=twodx;
			}
			else
			{
				if(m>=1)
					x++;
				else
					x--;
				p+=twodxdy;
			}

			if(a[cnt])
				putpixel(x,getmaxy()-y,3);
			cnt++;
			if(cnt==10)
				cnt=0;
		}
	}
}
void bresnt(int xA, int yA,int xB, int yB,int size)
{
	int th,i;
	for(i=0;i<size;i++)
	{
		th = i-size/2;
		if(abs(xA-xB) > abs(yA-yB))
			bresn(xA,yA+th,xB,yB+th,1);
		else
			bresn(xA+th,yA,xB+th,yB,1);
	}
}
/*
void main()
{
	screen();
	//to call with line style, put last parameter as 1 or 2 or 3 or 4.
	bresn(100,100,200,200,1);
	//to call thickline, call bresnt with last parameter size.
	bresnt(100,200,200,300,5);
getch();
}
*/