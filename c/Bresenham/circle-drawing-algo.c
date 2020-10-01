#include <graphics.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <conio.h>  
#include <math.h>  
  
    void    EightWaySymmetricPlot(int xc,int yc,int x,int y)  
   {  
    putpixel(x+xc,y+yc,RED);  
    putpixel(x+xc,-y+yc,YELLOW);  
    putpixel(-x+xc,-y+yc,GREEN);  
    putpixel(-x+xc,y+yc,YELLOW);  
    putpixel(y+xc,x+yc,12);  
    putpixel(y+xc,-x+yc,14);  
    putpixel(-y+xc,-x+yc,15);  
    putpixel(-y+xc,x+yc,6);  
   }  
  
    void BresenhamCircle(int xc,int yc,int r)  
   {  
    int x=0,y=r,d=3-(2*r);  
    EightWaySymmetricPlot(xc,yc,x,y);  
  
    while(x<=y)  
     {  
      if(d<=0)  
             {  
        d=d+(4*x)+6;  
      }  
     else  
      {  
        d=d+(4*x)-(4*y)+10;  
        y=y-1;  
      }  
       x=x+1;  
       EightWaySymmetricPlot(xc,yc,x,y);  
      }  
    }  
  
    int  main(void)  
   {  
    /* request auto detection */  
    int xc,yc,r,gdriver = DETECT, gmode, errorcode;  
    /* initialize graphics and local variables */  
     initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");  
  
     /* read result of initialization */  
     errorcode = graphresult();  
  
      if (errorcode != grOk)  /* an error occurred */  
     {  
        printf("Graphics error: %s\n", grapherrormsg(errorcode));  
        printf("Press any key to halt:");  
        getch();  
        exit(1); /* terminate with an error code */  
     }  
       printf("Enter the values of xc and yc :");  
       scanf("%d%d",&xc,&yc);  
       printf("Enter the value of radius  :");  
       scanf("%d",&r);  
       BresenhamCircle(xc,yc,r);  
  
     getch();  
     closegraph();  
     return 0;  
    }  