//
// Created by xdroid on 12/8/16.
//

#include "Vertex.h"
#include <math.h>
#include <cmath>



Vertex::Vertex() : x(0.0), y(0.0), height(0.0), p(nullptr) {}

Vertex::Vertex(double x, double y, double height) : x(x), y(y), height(height), p(nullptr) {}

Vertex::~Vertex() {
    if (p != nullptr) delete p;
    p = nullptr;
}

Vertex Vertex::operator -(Vertex _vertex) const {
    return Vertex(x-_vertex.x, y-_vertex.y, 0.0);
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
    os << "Vertex: {";
    os << "x: " << vertex.x << " y: " << vertex.y << " height: " << vertex.height << " p: " << vertex.p;
    os << "}";
    return os;
}

bool isSameVertex(Vertex vertex1, Vertex vertex2) {
    double distence = sqrt(pow(vertex1.getX() - vertex2.getX(), 2.0) + pow(vertex1.getY() - vertex2.getY(), 2.0));
    if (distence < 1e-6)
        return true;
    return false;
}
