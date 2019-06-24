#include <windows.h>
#include <GL/glut.h>

void reshape(GLsizei width, GLsizei height)
{
    if (height == 0) {
        height = 1;
    } //preventing divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height); //setting viewport to cover new window

    //setting the aspect ratio of clipping area to match viewport
    glMatrixMode(GL_PROJECTION); //to operate on Projection matrix
    glLoadIdentity();
    if (width >= height) {
        gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    }
    else {
        gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
    }
}
void idle()
{
    glutPostRedisplay(); //post a repaint request to activate display()
}
void block(float x, float y, float height, float width)
{
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x, y - height);
    glVertex2f(x + width, y - height);
    glVertex2f(x + width, y);
    glEnd();
}

void drawCanvas()
{

    glColor3ub(255, 255, 255);

    glBegin(GL_LINES);
    glVertex2f(-1, 1);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, 1);

    glVertex2f(-1, 0);
    glVertex2f(1, 0);

    glVertex2f(0, 1);
    glVertex2f(0, -1);
    glEnd();
}

void up()
{

    glColor3ub(255, 255, 0);
    block(-1.0, 0.45, 0.25, .5);

    block(-0.6, 0.35, 0.23, 0.23);

    block(-0.5, 0.25, 0.23, 0.365);

    block(-0.25, 0.35, 0.23, 0.35);
    ////

    block(-0.02, 0.25, 0.23, 0.35);

    block(0.22, 0.35, 0.23, 0.23);

    block(0.33, 0.45, 0.25, .5);

    //
    block(-0.135, 0.45, 0.25, 0.112);

    //
    //glColor3ub(255,255,255);
    block(0.1, 0.035, 0.112, 0.12);

    block(-0.37, 0.035, 0.112, 0.12);
}

void display()
{
    glClearColor(1, 1, 1, 1); // white background as clearing
    glClear(GL_COLOR_BUFFER_BIT); //clear the previous color buffer

    glMatrixMode(GL_MODELVIEW); //to operate on modelview matrix
    glLoadIdentity(); //rest model view

    glColor3ub(255, 0, 0);
    block(-1.0, 1.0, 2, 2);

    glTranslatef(0.075, 0, 0);
    glScalef(1.15, 1.15, 0);
    up();
    glLoadIdentity();

    glTranslatef(0.075, -0.5, 0);
    glScalef(1.15, 1.15, 0);
    up();
    glLoadIdentity();

    //drawCanvas();

    glColor3ub(255, 255, 255);
    block(-1, 1, 2, 0.05);
    block(.95, 1, 2, 0.1);
    block(-1, 1, 0.05, 2);
    block(-1, -0.95, 0.05, 2);

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInitDisplayMode(GLUT_DOUBLE); //enables double buffer mode
    glutInitWindowSize(500, 500); //window height and width
    glutInitWindowPosition(10, 10); //x,y position for window
    glutCreateWindow("Lab Performance Mid"); //window title
    glutDisplayFunc(display); //handler window repaint
    glutReshapeFunc(reshape); //handler window resize
    glutIdleFunc(idle); //callback handler
    glutMainLoop(); //infinite event processing loop

    return 0;
}
