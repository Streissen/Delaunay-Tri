//
// Created by hwj on 12/10/16.
//

#include <math.h>
#include "Vertex.h"
#include "eigen3/Eigen/Dense"
#include "Triangle.h"

double Triangle::getRadius() const {
    Vertex v1(this->vertex[0]), v2(this->vertex[1]), v3(this->vertex[2]);
    double a,b,c,radius;
    a = sqrt((v1.getX()-v2.getX())*(v1.getX()-v2.getX())+(v1.getY()-v2.getY())*(v1.getY()-v2.getY()));
    b = sqrt((v1.getX()-v3.getX())*(v1.getX()-v3.getX())+(v1.getY()-v3.getY())*(v1.getY()-v3.getY()));
    c = sqrt((v3.getX()-v2.getX())*(v3.getX()-v2.getX())+(v3.getY()-v2.getY())*(v3.getY()-v2.getY()));
    radius = a*b*c/sqrt((a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c));
    return radius;
}

Vertex Triangle::getCircumCenter() const {
    Eigen::Matrix3d A1,A2,B;
    Vertex v1(this->vertex[0]), v2(this->vertex[1]), v3(this->vertex[2]);
    A1 <<   v1.getX()*v1.getX()+v1.getY()*v1.getY(), v1.getY(), 1,
            v2.getX()*v2.getX()+v2.getY()*v2.getY(), v2.getY(), 1,
            v3.getX()*v3.getX()+v3.getY()*v3.getY(), v3.getY(), 1;
    A2 <<   v1.getX(), v1.getX()*v1.getX()+v1.getY()*v1.getY(), 1,
            v2.getX(), v2.getX()*v2.getX()+v2.getY()*v2.getY(), 1,
            v3.getX(), v3.getX()*v3.getX()+v3.getY()*v3.getY(), 1;
    B <<    v1.getX(), v1.getY(), 1,
            v2.getX(), v2.getY(), 1,
            v3.getX(), v3.getY(), 1;
    double centerX,centerY;
    centerX = A1.determinant()/B.determinant()/2;
    centerY = A2.determinant()/B.determinant()/2;

    Vertex center(centerX, centerY, 0.0); //TODO height

    return center;
}


const Vertex *Triangle::getVertex() const {
    return vertex;
}

Vertex Triangle::get(int index) const {
    return vertex[index];
}

Triangle::Triangle() {}
Triangle::Triangle(Vertex vertex[3]) {
    for (int i = 0; i < 3; ++i) {
        this->vertex[i] = vertex[i];
    }
}
Triangle::Triangle(Vertex v0, Vertex v1, Vertex v2) {
    this->vertex[0] = v0;
    this->vertex[1] = v1;
    this->vertex[2] = v2;
}
