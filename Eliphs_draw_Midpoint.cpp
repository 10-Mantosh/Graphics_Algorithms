#include <iostream>
#include<GL/glut.h>
using namespace std;
float maxr,minr;

void point(int x,int y) 
{	
	glColor3f(0.0,0.0,1.0);
	glPointSize(1.8);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
void fourwaysemetry(int x,int y)
{
point(x,y);
point(-x,y);
point(x,-y);
point(-x,-y);
}
void midPointEllipseAlgo(int rx,int ry)
{
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;
    d1 = (ry * ry)-(rx * rx * ry)+(0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;
    while (dx < dy)// first region 
    {
    fourwaysemetry(x,y);
        
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }
    
    while (y >= 0)
    {
     fourwaysemetry(x,y);
         if (d2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
    
}
void display()
{
    
    	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
  	gluOrtho2D(-400,400,-400,400);
  	glColor3f(1.0, 0.0, 0.0);
  	glBegin(GL_LINES);
  	glVertex2i(-400,0);
  	glVertex2i(400,0);
  	glVertex2i(0,400);
  	glVertex2i(0,-400);
  	
  	midPointEllipseAlgo(maxr,minr);
  	
	glFlush();
}

int main(int argc, char** argv) {
	
	cout << "\nEnter major radius : "; cin >> maxr;
	cout << "\nEnter minor radius : "; cin >> minr;	

		
	glutInit(&argc,argv);
	
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(300,20);
	glutCreateWindow("Midpoint Ellipse drawing Algorithm");
	glClearColor(0.5,0.5,0.5,0.0);	
	glutDisplayFunc(display);
	
	glutMainLoop();
	
	return 0;
}