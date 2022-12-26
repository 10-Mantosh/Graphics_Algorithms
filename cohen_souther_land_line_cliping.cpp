#include <GL/glut.h>
#include<iostream>
using namespace std;
int xmin=5,xmax=25,ymin=5,ymax=25,x_1,y_1,x_2,y_2;

void draw_line()
{
    glLineWidth(3.5);
    glBegin (GL_LINES);
    glColor3f(0.0,0.0,1.0);
    glVertex2i (x_1,y_1);
    glVertex2i (x_2,y_2);
    glEnd( );
}

int encode(int x,int y)
{

int code=0;
if(x<xmin)
code=code|1;
if(x>xmax)
code=code|2;
if(y<ymin)
code=code|4;
if(y>ymax)
code=code|8;
return code;

}
void cohen_sutherland()
{
int step=1;
while(1)
{

cout<<"-----------------"<<"step"<<step<<"-----------------------------\n";
int p1=encode(x_1,y_1);
int p2=encode(x_2,y_2);
	cout<<" point 1 is ="<<x_1<<"  "<<y_1<<endl;
	cout<<" point 2 is ="<<x_2<<"  "<<y_2<<endl;
cout<<"line codes "<<p1<<"  "<<p2<<endl;
if((p1|p2)==0)
{
  draw_line();
  break;

}
if((p1&p2)!=0)
{
cout<<"LINE INVISIBLE";
break;
}

if((p1&p2)==0)
{
	
	if(p1==0)
	{
	   int t;
	   t=x_1;
	   x_1=x_2;
	   x_2=t;
	   
	   t=y_1;
	   y_1=y_2;
	   y_2=t;
	   //swap(x_1,x_2);
	   //swap(y_1,y_2);
	   t=p1;
	   p1=p2;
	   p2=t;

	}

int x=0,y=0;
int m=(y_2-y_1)/(x_2-x_1);
if(m<1)
m=1;
if(p1&1)
{
 x=xmin;
 y=y_1+m*(x-x_1);
 
 }
else if(p1&2)
{
 x=xmax;
 y=y_1+m*(x-x_1);
 
}
else if(p1&4)
{
 y=ymin;
 x=x_1+(y-y_1)/m;
 
}
else if(p1&8)
{

 y=ymax;
 
 x=x_1+(y-y_1)/m;
}

x_1=x;
y_1=y;

}
step++;
if(step==8)
break;
}
}


void displayMe()
{
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,60.0,0.0,60.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5,0.5,0.5);

    cohen_sutherland();
    glBegin (GL_LINE_LOOP);
    glLineWidth(2.0);
    glColor3f(1.0,0.0,0.0);
    glVertex2i(xmin,ymin);
    glVertex2i(xmin,ymax); 
    glVertex2i(xmax,ymax);
    glVertex2i(xmax,ymin); 
    glEnd( );



     
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    cout<<"you can't put accurete vertical  across the box ..in that case dy/dx is zero division exception exception"<<endl;
    cout<<"here, xmin=5,ymin=5,xmax=25,ymax=25\n";
    cout<<"Enter line start point x ,y-\n";cin>>x_1>>y_1;
    cout<<"Enter line End point x ,y-\n";cin>>x_2>>y_2;
    //cout<<"\nEnter xmin,ymin,xmax,ymax respectively\n";cin>>xmin>>ymin>>xmax>>ymax;
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("line cliping");
    glClearColor(0.1,0.5,0.3,0.0);
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}