DDA
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

void dda(int x0, int y0, int x1, int y1) {
	int dx = x1-x0;
	int dy = y1-y0;
	int steps = abs(dy) > abs(dx) ? dy : dx;
	float Xinc = dx/steps;
	float Yinc = dy/steps;
	int x = x0;
	int y = y0;
	for (int i=0; i<=steps;i++) {
		putpixel(x,y,RED);
		x = x + Xinc;
		y = y + Yinc;
	}

}

void main() {
 int gd = DETECT, gm;
 clrscr();
 initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

 int x0 = 100, y0 = 100, x1 = 400, y1 = 400;
 dda(x0,y0,x1,y1);


  getch();

}
==========================================================================
Bressenham
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void bressenham(int x1,int x2, int y1, int y2) {
	int dx = x2-x1;
	int dy = y2-y1;
	int p = 2*dy-dx;

	int x = x1;
	int y =y1;

	while (x < x2) {
	 if (p>=0) {
		putpixel(x,y,RED);
		y = y+1;
		p = p+2*dy-2*dx;
	 }else {
		putpixel(x,y,RED);
		p = p + 2*dy;
	 }
	 x=x+1;
	}

}

int main() {
 int gd = DETECT, gm;
 initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
 bressenham(100,200, 100,200);
 getch();
 closegraph();
 return 0;

} 


===========================================================================
shearing
#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Original coordinates of a rectangle
    int left = 100, top = 100, right = 200, bottom = 200;

    // Draw original rectangle
    rectangle(left, top, right, bottom);
    outtextxy(left, bottom + 10, "Original Rectangle");

    // Horizontal shearing factor (shx)
    float shx = 1.0;

    // Apply horizontal shearing (shift x coordinates)
    int new_left_x = left + shx * top;
    int new_right_x = right + shx * bottom;

    // Draw sheared rectangle
    rectangle(new_left_x, top, new_right_x, bottom);
    outtextxy(new_left_x, bottom + 10, "Sheared Rectangle");

    getch();
    closegraph();
    return 0;
}
=============================================================================

Bezier Curve
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

void drawBezier(int x[3], int y[3]) {
    double t;
    for (t = 0.0; t <= 1.0; t += 0.001) {
	// Compute the coordinates of the point on the Bézier curve
	int xt = (1 - t) * (1 - t) * x[0] + 2 * (1 - t) * t * x[1] + t * t * x[2];
	int yt = (1 - t) * (1 - t) * y[0] + 2 * (1 - t) * t * y[1] + t * t * y[2];

	// Plot the point
	putpixel(xt, yt, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int x[3] = {100, 200, 300};  // x-coordinates of P0, P1, P2
    int y[3] = {300, 100, 300};  // y-coordinates of P0, P1, P2

    line(x[0], y[0], x[1], y[1]); // Line from P0 to P1
    line(x[1], y[1], x[2], y[2]); // Line from P1 to P2
    drawBezier(x, y);
    getch();
    closegraph();
 return 0;
}

=============================================================================
BFill 
// C Implementation for Boundary Filling Algorithm 
#include <graphics.h> 
	
// Function for 4 connected Pixels 
void boundaryFill4(int x, int y, int fill_color,int boundary_color) 
{ 
	if(getpixel(x, y) != boundary_color && 
	getpixel(x, y) != fill_color) 
	{ 
		putpixel(x, y, fill_color); 
		boundaryFill4(x + 1, y, fill_color, boundary_color); 
		boundaryFill4(x, y + 1, fill_color, boundary_color); 
		boundaryFill4(x - 1, y, fill_color, boundary_color); 
		boundaryFill4(x, y - 1, fill_color, boundary_color); 
	} 
} 
	
//driver code 
int main() 
{ 
	// gm is Graphics mode which is 
	// a computer display mode that 
	// generates image using pixels. 
	// DETECT is a macro defined in 
	// "graphics.h" header file 
	int gd = DETECT, gm; 
	
	// initgraph initializes the 
	// graphics system by loading a 
	// graphics driver from disk 
	initgraph(&gd, &gm, ""); 
	
	int x = 250, y = 200, radius = 50; 
	
	// circle function 
	circle(x, y, radius); 
	
	// Function calling 
	boundaryFill4(x, y, 6, 15); 
	
	delay(10000); 
	
	getch(); 
	
	// closegraph function closes the 
	// graphics mode and deallocates 
	// all memory allocated by 
	// graphics system . 
	closegraph(); 
	
	return 0; 
}


=============================================================================
2D trans
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
void scaling(int x1,int  y1,int x2,int y2) {
	int sx = 4;
	int sy= 3;
	x1 = x1*sx;
	x2 = x2*sx;
	y1= y1*sy;
	y2 = y2*sy;
	rectangle(x1,y1,x2,y2);
}
void rotation() {
   int x1 =100, x2 = 100, y1 = 100, y2 = 200;
   line(x1,y1,x2,y2);
   double s,c, angle;
   angle = 10;
   c= cos(angle*3.14/180);
   s= sin(angle*3.14/180);
   x1 = floor(x1*c + y1*s);
   y1= floor(-x1*s+y1*c);
   x2 = floor(x2*c+y2*s);
   y2 = floor(-x2*s+y2*c);

   line(x1,y1,x2,y2);
}

void main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
 //	int x1 = 50, y1 = 50, x2= 100, y2 = 100;
	rotation();
   //	rectangle(x1, y1, x2, y2);
    //	scaling(x1,y1,x2,y2);
  //	int tx = 15;
//	int ty= 20;
      //	x1 = x1+tx;
    //	x2 = x2+tx;
  //	y1 = y1+ty;
 //	y2 = y2+ty;
	//rectangle(x1,y1,x2,y2);

       getch();
       closegraph();

}