#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

int gd = DETECT,gm;
void bres(int xa, int ya, int xb, int yb)
{
	int dx = abs(xa-xb);
	int dy = abs(ya-yb);
	float m = (float)(yb-ya)/(xb-xa);
	int p;
	int twody=2*dy;
	int twodx=2*dx;
	int twodydx=2*(dy-dx);
	int twodxdy=2*(dx-dy);
	int x,y,xend,yend;
	if(dx>dy)
	{
		p=2*dy-dx;
		if(xa>xb)
		{
			x=xb;
			y=yb;
			xend=xa;
		}
		else
		{
			x=xa;
			y=ya;
			xend=xb;
		}
		putpixel(x,getmaxy()-y,3);
		while(x<xend)
		{
			x++;
			if(p<0)
			{
				p+=twody;
			}
			else
			{
				if(0<m && m<1)
					y++;
				else
					y--;
				p+=twodydx;
			}
			putpixel(x,getmaxy()-y,3);
		}
	}
	else
	{
		p=2*dx-dy;
		if(ya>yb)
		{
			x=xb;
			y=yb;
			yend=ya;
		}
		else
		{
			x=xa;
			y=ya;
			yend=yb;
		}
		putpixel(x,getmaxy()-y,3);
		while(y<yend)
		{
			y++;
			if(p<0)
			{
				p+=twodx;
			}
			else
			{
				if(0<m && m<1)
					x++;
				else
					x--;
				p+=twodxdy;
			}
			putpixel(x,getmaxy()-y,3);
		}
	}
}

int main()
{
	initgraph(&gd,&gm,"C:/TURBOC3/BGI");
	bres(200,200,400,100);
	getch();
return 0;
}
