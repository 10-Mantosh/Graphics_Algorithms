#include <iostream>
#include<GL/glut.h>
using namespace std;
float cx,cy,r;//use yl insted of y1 to avoid inbuilt function error

void point(int a,int b) 
{	glPointSize(3.2);
	glBegin(GL_POINTS);
	glVertex2i(a+cx,b+cy);
	glEnd();
}

void midPointCircleAlgo()
{
int x = 0;
int y = r;
float decision = 5/4 - r;
point(x,y);

while (y > x)
{
if (decision < 0)
{
x++;
decision += 2*x+1;
}
else
{
y--;
x++;
decision += 2*(x-y)+1;
}
point(x, y);
point(x, -y);
point(-x, y);
point(-x, -y);
point(y, x);
point(-y, x);
point(y, -x);
point(-y, -x);
}
}
void display()
{
    
    	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
  	gluOrtho2D(0, 640, 0, 480);
  	glColor3f(1.0, 0.0, 0.0);
  	midPointCircleAlgo();
  	
	glFlush();
}

int main(int argc, char** argv) {
	
	cout << "Enter the coordinates(x,y) of the center:\n" << endl;cin>>cx>>cy;
	cout << "\nEnter radius : "; cin >> r;

		
	glutInit(&argc,argv);
	
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(300,20);
	glutCreateWindow("Midpoint circle drawing Algorithm");
	glClearColor(0.0,0.50,0.0,0.0);	
	glutDisplayFunc(display);
	
	glutMainLoop();
	
	return 0;
}