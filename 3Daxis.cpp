#include <GL/glut.h>
#include<iostream>
using namespace std;

void myinit(void)
{
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2, 0.2, 0.2, 1.0);
    glMatrixMode(GL_MODELVIEW);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(3.8, 0.0, 0.0);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 3.8, 0.0);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 3.8);
    glEnd();

    glLoadIdentity();
    gluLookAt(5.0, 5.0, 5.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0);

    glutSwapBuffers();
    glFlush();
}

void reshape(int width, int height) {
    int aspect = width * 1.0f / height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
    gluPerspective(60.0f, aspect, 0.1f, 10.0f);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("U10916025");
    myinit();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    display();
    glutMainLoop();
    return 0;
}