// Process the input.
// Created by xdroid on 12/8/16.
//

#include <GL/freeglut.h>
#include "input.h"

Input input;

extern int screenSize;
extern int screenWidth;
extern int screenHeight;

/** Input::Mouse */
double Input::Mouse::getX() const {
    return x;
}

double Input::Mouse::getY() const {
    return y;
}

int Input::Mouse::getButton() const {
    return button;
}

double Input::Mouse::getNx() const {
    return nx;
}

double Input::Mouse::getNy() const {
    return ny;
}

void Input::Mouse::set(int _button, int _state, int _x, int _y) {
    if (GLUT_DOWN == _state)
        switch (_button) {
            case GLUT_LEFT_BUTTON:
                button |= LEFT_MOUSE_BUTTON;
                break;
            case GLUT_MIDDLE_BUTTON:
                button |= MIDDLE_MOUSE_BUTTON;
                break;
            case GLUT_RIGHT_BUTTON:
                button |= RIGHT_MOUSE_BUTTON;
                break;
        }
    else
        switch (_button) {
            case GLUT_LEFT_BUTTON:
                button &= ~LEFT_MOUSE_BUTTON;
                break;
            case GLUT_MIDDLE_BUTTON:
                button &= ~MIDDLE_MOUSE_BUTTON;
                break;
            case GLUT_RIGHT_BUTTON:
                button &= ~RIGHT_MOUSE_BUTTON;
                break;
        }
    setMotion(_x, _y);
}

void Input::Mouse::setMotion(int _x, int _y) {
    x = _x;
    y = _y;
    nx = (_x - screenWidth / 2.0) / screenSize;
    ny = (screenHeight / 2.0 - _y) / screenSize;
}

/** Input::Keyboard */
const bool *Input::Keyboard::getKeyStat() const {
    return keyStat;
}

void Input::Keyboard::set(unsigned char key, int x, int y) {
    switch (key) {
        case '\x0D' :
        case '\x1B' :
            glutLeaveMainLoop();
            break;
    }
    keyStat[key] = true;
}

void Input::Keyboard::unset(unsigned char key, int x, int y) {
    keyStat[key] = false;
}

/** Input */
const Input::Mouse &Input::getMouse() const {
    return mouse;
}

const Input::Keyboard &Input::getKeyboard() const {
    return keyboard;
}

void Input::setMouse(int button, int state, int x, int y) {
    mouse.set(button, state, x, y);
}

void Input::setMouseMotion(int x, int y) {
    mouse.setMotion(x, y);
}

void Input::setKeyboard(unsigned char key, int x, int y) {
    keyboard.set(key, x, y);
}

void Input::unsetKeyboard(unsigned char key, int x, int y) {
    keyboard.unset(key, x, y);
}

/** Static */
void setMouseWrapper(int button, int state, int x, int y) {
    input.setMouse(button, state, x, y);
}

void setMouseMotionWrapper(int x, int y) {
    input.setMouseMotion(x, y);
}

void setKeyboardWrapper(unsigned char key, int x, int y) {
    input.setKeyboard(key, x, y);
}

void unsetKeyboardWrapper(unsigned char key, int x, int y) {
    input.unsetKeyboard(key, x, y);
}

void initInput() {
    input = Input();
    glutMouseFunc(&setMouseWrapper);
    glutMotionFunc(&setMouseMotionWrapper);
    glutPassiveMotionFunc(&setMouseMotionWrapper);
    glutKeyboardFunc(&setKeyboardWrapper);
    glutKeyboardUpFunc(&unsetKeyboardWrapper);
}