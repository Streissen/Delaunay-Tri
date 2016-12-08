#include <GL/freeglut.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <deque>
#include <time.h>

using namespace std;

extern int screenSize;
extern int screenWidth;
extern int screenHeight;

const int MAX = 100;
const double TINY = 0.01;

//extern vector<point> v;
//extern vector<line> l;
//extern vector<int> vr, vg, vb;
//extern vector<int> lr, lg, lb;
//extern transform t;
//extern deque<point> snake;
//extern size_t snakeend;
//extern double snakeStep;
//extern double boundRadius;
//extern point food;
//extern int score;

//const double snakeWidth = snakeStep / 2.0;

int getfps(){
    static int count = 0, fps = 0;
    static time_t t1 = time(NULL);
    time_t t = time(NULL);
    if (t > t1) {
        fps = count/(t-t1);
        t1 = t;
        count = 0;
    }else ++count;
    return fps;
}

void reshape(int width, int height){
    screenWidth = width;
    screenHeight = height;
    screenSize = (width < height ? width : height);
    glViewport (0, 0, width, height);
    glLoadIdentity ();
    glOrtho (-(GLfloat)width / screenSize, (GLfloat)width / screenSize,
            -(GLfloat)height / screenSize, (GLfloat)height / screenSize,
            -2.0f, 2.0f);
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
    //transform t(0.0);
 
    //Clearing buffer
    glClear(GL_COLOR_BUFFER_BIT);

    //Drawing objects
    glColor3f(1.0f, 1.0f, 1.0f);
    //drawCircle(point(0.0, 0.0), 1.0);


    //Drawing text infomation
    char str[257];
    glColor3f(1.0f, 1.0f, 0.5f);
    glRasterPos2d(-1, 1 - 24.0/screenSize);
    glutBitmapString(GLUT_BITMAP_HELVETICA_12, (unsigned char *)str);

    //Flush the drawing process
    glFlush();
}

