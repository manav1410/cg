#include <iostream.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>
int gd=DETECT,gm;
int round(float a)
{
	return (int)(a+0.5);
}
int main()
{

// for co-ordinates.
    float xa,ya,xb,yb;

    initgraph(&gd,&gm,"C:/TURBOC3/BGI");
// Scan here.
    cout<<" Enter xA : ";
    cin>>xa;
    cout<<" Enter yA : ";
    cin>>ya;
    cout<<" Enter xB : ";
    cin>>xb;
    cout<<" Enter yB : ";
    cin>>yb;


// for horizontal and vertical difference.
    float dx = xb - xa;   // dx =  xb - xa;
    float dy = yb - ya;   // dy =  yb - ya;
    cout<<"\n dx = "<<dx<<"\n dy = "<<dy<<endl;

// for steps counting.
    int steps; //for steps counting

    if(abs(dx)>abs(dy))
	steps = dx;
    else
	steps = dy;

//  finding increament.

    float xinc = dx/steps;
    float yinc = dy/steps;

//  temporary variables to handle the values.
    float tempx = xa;
    float tempy = ya;
// printing Answer
    cout<<"\n\nANSWER \n\n";
    for(int i = 0;i<steps;i++)
    {
	putpixel(round(tempx),getmaxy()-round(tempy),3);
	tempx = tempx + xinc;
	tempy = tempy + yinc;
    }
    getch();
    return 0;
}
