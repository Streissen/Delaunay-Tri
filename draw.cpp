#include <GL/freeglut.h>
#include <stdio.h>
#include <time.h>
#include "input.h"

using namespace std;

int screenSize = 600;
int screenWidth = 600;
int screenHeight = 600;

extern Input input;

int getfps(){
    static int count = 0, fps = 0;
    static time_t previousTime = time(NULL);
    time_t currentTime = time(NULL);
    if (currentTime > previousTime) {
        fps = count / (currentTime - previousTime);
        previousTime = currentTime;
        count = 0;
    } else ++count;
    return fps;
}

void initDisplay(){
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    /*
     *     glEnable(GL_LINE_SMOOTH);
     *     glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
     *     glLineWidth(1.5);
     **/
    glEnable(GL_MULTISAMPLE);
    glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
}

void display(){
    //Clearing buffer
    glClear(GL_COLOR_BUFFER_BIT);

    //Drawing objects
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f,-1.0f, 0.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(1.0f,-1.0f, 0.0f);
    glEnd();

    //Drawing text infomation
    char str[257];
    sprintf(str, "FPS: %d\nMouse: %+.3lf, %+.3lf",
            getfps(),
            input.getMouse().getNx(),
            input.getMouse().getNy());
    glColor3f(1.0f, 1.0f, 0.5f);
    glRasterPos2d(-1, 1 - 24.0/screenSize);
    glutBitmapString(GLUT_BITMAP_HELVETICA_12, (unsigned char *)str);

    //Flush the drawing process
    glFlush();
}

