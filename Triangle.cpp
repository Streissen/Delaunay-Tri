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

double Triangle::getAverageHeight() const {
    double sum = 0.0;
    for (auto &v: vertex) {
        sum += v.getHeight();
    }
    return sum / 3.0;
}

bool Triangle::contain(Vertex vertex) const {
    Vertex _v0 = this->vertex[2] - this->vertex[0];
    Vertex _v1 = this->vertex[1] - this->vertex[0];
    Vertex _v2 = vertex - this->vertex[0];

    Eigen::Vector2d v0(_v0.getX(), _v0.getY());
    Eigen::Vector2d v1(_v1.getX(), _v1.getY());
    Eigen::Vector2d v2(_v2.getX(), _v2.getY());
    double dot00 = v0.dot(v0) ;
    double dot01 = v0.dot(v1) ;
    double dot02 = v0.dot(v2) ;
    double dot11 = v1.dot(v1) ;
    double dot12 = v1.dot(v2) ;

    double inverDeno = 1 / (dot00 * dot11 - dot01 * dot01) ;

    double u = (dot11 * dot02 - dot01 * dot12) * inverDeno ;
    if (u < 0 || u > 1) // if u out of range, return directly
    {
        return false ;
    }

    double v = (dot00 * dot12 - dot01 * dot02) * inverDeno ;
    if (v < 0 || v > 1) // if v out of range, return directly
    {
        return false ;
    }

    return u + v <= 1 ;
}


bool Triangle::hasVertex(Vertex vertex) {
    for (int i = 0; i < 3; ++i) {
        double distance = sqrt(pow(vertex.getX() - this->get(i).getX(), 2.0) + pow(vertex.getY() - this->get(i).getY(), 2.0));
        if (distance < 1e-16)
            return true;
    }
    return false;
}

Triangle::~Triangle() {
    for (auto &v: vertex) {
        v.~Vertex();
    }
}

std::ostream &operator<<(std::ostream &os, const Triangle &triangle) {
    os << "Triangle: " << triangle.vertex[0] << triangle.vertex[1] << triangle.vertex[2];
    return os;
}
