#include <windows.h>
#include <GL/glut.h>
#include<math.h>
# define PI    3.14159265358979323846

GLubyte wheat[]={245,222,179};
GLubyte sand[]={194,178,128};
GLubyte deepskyblue[] ={0,191,255};
GLubyte aztecgold[] = {194,152,94};
GLubyte fawn[] = {226,171,104};
GLubyte white[] = {255,255,255};

GLfloat xmove = 0.0f;

void reshape(GLsizei width, GLsizei height)
{
    if (height==0){height =1;} //preventing divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0,0,width,height); //setting viewport to cover new window

    //setting the aspect ratio of clipping area to match viewport
    glMatrixMode(GL_PROJECTION); //to operate on Projection matrix
    glLoadIdentity();
    if(width >= height)
    {
        gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    }
    else
    {
        gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
    }
}
void idle()
{
    glutPostRedisplay(); //post a repaint request to activate display()
}
void block(float x,float y, float height, float width)
{
    glBegin(GL_QUADS);
    glVertex2f(x,y);
    glVertex2f(x,y-height);
    glVertex2f(x+width,y-height);
    glVertex2f(x+width,y);
    glEnd();
}
void circle(float x, float y, float radius)
{
	int i;
	int triangleAmount = 100;

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void background()
{
    glColor3ubv(deepskyblue);
    block(-2,1,1.3,4); //x,y,height,width
    glColor3ubv(wheat);
    block(-2,-0.3,0.7,4);
}

void pyramid()
{
    glBegin(GL_TRIANGLES);

    glColor3ubv(aztecgold);
    glVertex2f(0,.1);
    glVertex2f(-.45,-0.4);
    glVertex2f(0.13,-0.5);

    glColor3ubv(fawn);
    glVertex2f(0,.1);
    glVertex2f(0.13,-0.5);
    glVertex2f(0.5,-0.37);


    glEnd();
}

void cloud()
{
    glColor3ubv(white);
    circle(-.7,.6,.18);
    circle(-.5,.6,.21);
    circle(-0.3,.6,.18);

}

void drawCanvas()
{

    glColor3ub(255,255,255);

    glBegin(GL_LINES);
    glVertex2f(-1,1);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,1);

    glVertex2f(-1,0);
    glVertex2f(1,0);

    glVertex2f(0,1);
    glVertex2f(0,-1);
    glEnd();


}

void cloudAnimation()
{
    glPushMatrix();
    glTranslatef(xmove,0,0);
    cloud();
    glLoadIdentity();

    glTranslatef(xmove-0.9,0.5,0);
    glScalef(1.3,.8,0);
    cloud();
    glLoadIdentity();


    glTranslatef(xmove-1.9,0.2,0);
    glScalef(1.1,.9,0);
    cloud();
    glLoadIdentity();

    glPopMatrix();

    xmove+=0.005f;
    if(xmove>4.5)
    {
        xmove=-1.0;
    }
}

void display()
{
    glClearColor(1,1,1,1); // white background as clearing
    glClear(GL_COLOR_BUFFER_BIT); //clear the previous color buffer

    glMatrixMode(GL_MODELVIEW); //to operate on modelview matrix
    glLoadIdentity(); //rest model view

    background();

    glTranslatef(-0.35,0.1,0);
    glScalef(1.2,1.2,0);
    pyramid();
    glLoadIdentity();

    glTranslatef(.4,-0.15,0);
    glScalef(.8,.7,0);
    pyramid();
    glLoadIdentity();

    cloudAnimation();
    //xmove=1.5; //immobile the cloud

    //drawCanvas(); //showing canvas area

    glutSwapBuffers();


}

int main(int argc, char** argv)
{
    glutInitDisplayMode(GLUT_DOUBLE); //enables double buffer mode
    glutInitWindowSize(800,600); //window height and width
    glutInitWindowPosition(100,100); //x,y position for window
    glutCreateWindow("nfsiam | 17-33438-1 | Pyramid"); //window title
    glutDisplayFunc(display); //handler window repaint
    glutReshapeFunc(reshape); //handler window resize
    glutIdleFunc(idle); //callback handler
    glutMainLoop(); //infinite event processing loop

    return 0;
}
