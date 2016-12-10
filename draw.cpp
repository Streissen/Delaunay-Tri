#include <GL/freeglut.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include "input.h"
#include "Vertex.h"
#include "Triangle.h"

using namespace std;

int screenSize = 600;
int screenWidth = 600;
int screenHeight = 600;

extern Input input;
extern vector<Vertex> vertexes;
extern vector<Triangle> triangles;

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

void drawPoint(Vertex v){
    double size = 0.01;
    if (size * screenSize / 2 < 0.3) return;
    glBegin(GL_POLYGON);
    glVertex2d(v.getX()-size, v.getY()-size);
    glVertex2d(v.getX()-size, v.getY()+size);
    glVertex2d(v.getX()+size, v.getY()+size);
    glVertex2d(v.getX()+size, v.getY()-size);
    glEnd();
}

void drawTriangle(Triangle triangle) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 3; ++i) {
        glColor4d(1.0, 1.0, 1.0, triangle.getAverageHeight());
        glVertex2dv(triangle.get(i).getGLdoubleArray());
    }
    glEnd();
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

    for (auto &vertex: vertexes) {
        drawPoint(vertex);
    }

    for (auto &triangle: triangles) {
        drawTriangle(triangle);
    }

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

