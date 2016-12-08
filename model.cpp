#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <deque>
#include "model.h"

using namespace std;

extern int screenSize;
extern int screenWidth;
extern int screenHeight;

double rr = 0.05;

void update(int kbstat[]){
    /*static int frameCount = stepInterval;
    static int snakeDirNext = 0;
    if (kbstat['w']) snakeDirNext = 0; 
    if (kbstat['a']) snakeDirNext = 1; 
    if (kbstat['s']) snakeDirNext = 2; 
    if (kbstat['d']) snakeDirNext = 3; 
    if (stepInterval == frameCount){
        
        if ((snakeDirNext + snakeDir)%2) snakeDir = snakeDirNext;
        snake.push_front(t.inversion()(steps[snakeDir]));
        t1 = transform(steps[snakeDir]) * t1;
        t = transform(steps[snakeDir+4]) * t;

        if (snakeInc > 0) snakeInc--;
        else snakeend++;

        if (checkCollision()){
            printf("You lose! Score: %d\n\n", score);
            fflush(stdout);
            initModel();
            frameCount = stepInterval;
            snakeDir = 0;
            snakeDirNext = 0;
            return;
        }
        
        if (checkFood()){
            snakeInc += 2;
            score++;
            while(PoincareDistance(complex(0.0), (food = randFoodPoint())) >= boundRadius);
        }
        frameCount = 0;
    } else t = transform(steps[snakeDir+4]) * t;
    ++frameCount;*/
}

void renewMouseStat(double x, double y, int button){

    static int button_old = 0;
    static double x_old = 0, y_old = 0;
    if (LEFT_MOUSE_BUTTON & button & button_old) {
//        t = transform(-complex(x-x_old, y-y_old))*t;
    }
    button_old = button;
    x_old = x; y_old = y;
    printf("%lf %lf",x,y);
}
