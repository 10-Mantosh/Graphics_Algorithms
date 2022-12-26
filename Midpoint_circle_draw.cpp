#include <iostream>
#include<GL/glut.h>
using namespace std;
float r;

void point(int a,int b) 
{	
	glColor3f(0.0,0.0,1.0);
	glPointSize(2.2);
	glBegin(GL_POINTS);
	glVertex2i(a,b);
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
  	gluOrtho2D(-400,400,-400,400);
  	glColor3f(1.0, 0.0, 0.0);
  	glBegin(GL_LINES);
  	glVertex2i(-400,0);
  	glVertex2i(400,0);
  	glVertex2i(0,400);
  	glVertex2i(0,-400);
  	
  	midPointCircleAlgo();
  	
	glFlush();
}

int main(int argc, char** argv) {
	
	cout << "\nEnter radius : "; cin >> r;


		
	glutInit(&argc,argv);
	
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(300,20);
	glutCreateWindow("Midpoint circle drawing Algorithm");
	glClearColor(0.5,0.5,0.5,0.0);	
	glutDisplayFunc(display);
	
	glutMainLoop();
	
	return 0;
}