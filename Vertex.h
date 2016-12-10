//
// Created by xdroid on 12/8/16.
//

#ifndef DELAUNAY_TRI_VERTEX_H
#define DELAUNAY_TRI_VERTEX_H


#include <GL/gl.h>
#include <ostream>

class Vertex {
private:
    double x, y, height;
    GLdouble *p;
public:
    Vertex();
    Vertex(double x, double y, double height);

    virtual ~Vertex();

    double getX() const;
    double getY() const;
    double getHeight() const;

    GLdouble* getGLdoubleArray();

    friend std::ostream &operator<<(std::ostream &os, const Vertex &vertex);
};


#endif //DELAUNAY_TRI_VERTEX_H
