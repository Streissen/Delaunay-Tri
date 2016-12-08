// Process the input.
// Created by xdroid on 12/8/16.
//

#ifndef DELAUNAY_TRI_INPUT_H
#define DELAUNAY_TRI_INPUT_H

class Input {
private:
    class Mouse {
    public:
        double x;
        double y;
        int button;

        double nx;
        double ny;


        double getX() const;
        double getY() const;
        int getButton() const;

        double getNx() const;
        double getNy() const;

        void set(int button, int state, int x, int y);
        void setMotion(int x, int y);
    };
    class Keyboard {
    public:
        bool keyStat[256];

        const bool *getKeyStat() const;
        void set(unsigned char key, int x, int y);
        void unset(unsigned char key, int x, int y);
    };

    Mouse mouse;
    Keyboard keyboard;

public:
    const Mouse &getMouse() const;
    const Keyboard &getKeyboard() const;

    void setMouse(int button, int state, int x, int y);
    void setMouseMotion(int x, int y);
    void setKeyboard(unsigned char key, int x, int y);
    void unsetKeyboard(unsigned char key, int x, int y);

    static const int LEFT_MOUSE_BUTTON = 0x0001;
    static const int MIDDLE_MOUSE_BUTTON = 0x0002;
    static const int RIGHT_MOUSE_BUTTON = 0x0004;
};

void initInput();
#endif //DELAUNAY_TRI_INPUT_H
