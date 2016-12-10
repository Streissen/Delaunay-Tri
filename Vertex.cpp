#include "Vertex.h"//
// Created by xdroid on 12/8/16.
//

Vertex::Vertex() : x(0.0), y(0.0), height(0.0), p(nullptr) {}

Vertex::Vertex(double x, double y, double height) : x(x), y(y), height(height), p(nullptr) {}

Vertex::~Vertex() {
    if (p != nullptr) delete p;
    p = nullptr;
}


double Vertex::getX() const {
    return x;
}

double Vertex::getY() const {
    return y;
}

double Vertex::getHeight() const {
    return height;
}

GLdouble* Vertex::getGLdoubleArray() {
    if (p != nullptr) return p;
    p = new GLdouble[2];
    p[0] = (GLdouble) x;
    p[1] = (GLdouble) y;
    return p;
}

std::ostream &operator<<(std::ostream &os, const Vertex &vertex) {
    os << "x: " << vertex.x << " y: " << vertex.y << " height: " << vertex.height << " p: " << vertex.p;
    return os;
}
