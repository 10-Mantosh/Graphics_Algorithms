#include <iostream>
#include<GL/glut.h>
using namespace std;
float x0,yo,x1,yl;

void point(int a,int b) 
{
	glBegin(GL_POINTS);
	glVertex2i(a,b);
	glEnd();
}

void dda()
{
    
    float m=(yl-yo)/(x1-x0);
    float xk,yk;
    xk=x0,yk=yo;
 	point(xk,yk);
	if(m<=1)
	{
		while(xk<x1)
		{
		
			xk++;
			yk+=m;
			cout<<"("<<xk<<","<<yk<<")\n";
			point(xk,yk);
	
		}
	}
	else 
	{
		while(yk<yl)
		{
			xk+=(1/m);
			yk++;
			cout<<"("<<xk<<","<<yk<<")\n";
		    point(xk,yk);
	
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
  	dda();
  	
	glFlush();
}

int main(int argc, char** argv) {
	
	cout<<"Enter the initial point (x0,y0):";
	cin>>x0>>yo;
	cout<<"Enter the end point (x1,y1):";
	cin>>x1>>yl;
		
	glutInit(&argc,argv);
	
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(300,20);
	glutCreateWindow("DDA Algorithm");
	glClearColor(0.0,0.50,0.0,0.0);	
	glutDisplayFunc(display);
	
	glutMainLoop();
	
	return 0;
}