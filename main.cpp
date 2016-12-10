#include <GL/freeglut.h>
#include <stdio.h>
#include <string>
#include "draw.h"
#include "input.h"
#include "model.h"

using namespace std;

extern int screenSize;
extern int screenWidth;
extern int screenHeight;

const char* _APP_NAME_ = "Delaunay Triangles";

// Initialization
void init(){
    printf("--------%s 0.0.0--------\nOpenGL Version %s\n\n", _APP_NAME_, glGetString(GL_VERSION));
    initDisplay();
    initInput();
    initModel();
}

// Timer Callback
void timerCallback(int index){
    switch (index) {
        case 0:
            glutTimerFunc(33, &timerCallback, 0);
            glutPostRedisplay();
            break;
    }
}

int main(int argc, char *argv[]){
    //Window Initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_MULTISAMPLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow(_APP_NAME_);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

    //Callback function registry
    glutDisplayFunc(&display);

    glutTimerFunc(0, &timerCallback, 0);

    //Initialization
    init();

    //Main loop
    glutMainLoop();

    return 0;
}
