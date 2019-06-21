#include <windows.h>
#include <GL/glut.h>

GLubyte green[] ={0,128,0},
        darkgreen[]={255,99,71},
        yellowgreen[]={154,205,50},
        olive[]={128,128,0},
        darkolivegreen[]={85,107,47},

        purple[] ={128,0,128},
        navy[] ={0,0,128},
        gray[] ={128,128,128},
        slategray[]={112,128,144},
        blue[] ={0,0,255},
        violet[]={127,0,255},
        indigo[]={75,0,130},

        tomato[]={255,99,71},
        red[] ={255,0,0},
        orangered[]={255,69,0},
        yellow[] ={255,255,0},
        gold[]={255,215,0},
        orange[] ={255,165,0},
        darkorange[]={255,140,0},

        peru[] ={205,133,63},
        saddiebrown[]={139,69,19},
        wheat[]={245,222,179},
        aqua[] ={0,255,255},
        deepskyblue[] ={0,191,255},
        deeppink[] ={255,20,147};

void display()
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

    glColor3ubv(violet);

    glVertex2f(0.8,0.4);
    glVertex2f(0.8,0.6);
    glVertex2f(-0.8,0.6);
    glVertex2f(-0.8,0.4);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ubv(indigo);
    glVertex2f(0.8,0.2);
    glVertex2f(0.8,0.4);
    glVertex2f(-0.8,0.4);
    glVertex2f(-0.8,0.2);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ubv(blue);
    glVertex2f(0.8,0.0);
    glVertex2f(0.8,0.2);
    glVertex2f(-0.8,0.2);
    glVertex2f(-0.8,0.0);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ubv(green);
    glVertex2f(0.8,0.0);
    glVertex2f(0.8,-0.2);
    glVertex2f(-0.8,-0.2);
    glVertex2f(-0.8,0.0);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ubv(yellow);
    glVertex2f(0.8,-0.2);
    glVertex2f(0.8,-0.4);
    glVertex2f(-0.8,-0.4);
    glVertex2f(-0.8,-0.2);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ubv(orange);
    glVertex2f(0.8,-0.4);
    glVertex2f(0.8,-0.6);
    glVertex2f(-0.8,-0.6);
    glVertex2f(-0.8,-0.4);

    glEnd();



    glFlush();
}

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutCreateWindow("Color Flag");
    glutInitWindowSize(320,320);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}