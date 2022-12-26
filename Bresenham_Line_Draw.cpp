#include <iostream>
#include<GL/glut.h>
using namespace std;
float x1,yl,x2,y2;//use yl insted of y1 to avoid inbult function error

void point(int a,int b) 
{	glPointSize(3.2);
	glBegin(GL_POINTS);
	glVertex2i(a,b);
	glEnd();
}

void bresenham()
{
float x=x1,y=yl;
float dx=x2-x1,dy=y2-yl;
float p=2*dx-dy;
while(x<=x2)
{
cout<<"("<<x<<","<<y<<")"<<endl;
point(x,y);
x++;
if(p<0)
{
p=p+2*dy;
}
else
{
p=p+2*dy-2*dx;
y++;
}
}
}
void display()
{
    
    	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
  	gluOrtho2D(0, 640, 0, 480);
  	glColor3f(1.0, 0.0, 0.0);
  	bresenham();
  	
	glFlush();
}

int main(int argc, char** argv) {
	
	cout<<"Enter the initial point (x0,y0):\n";
	cin>>x1>>yl;
	cout<<"Enter the end point (x1,y1):\n";
	cin>>x2>>y2;
		
	glutInit(&argc,argv);
	
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(300,20);
	glutCreateWindow("Bresenham Algorithm");
	glClearColor(0.0,0.50,0.0,0.0);	
	glutDisplayFunc(display);
	
	glutMainLoop();
	
	return 0;
}