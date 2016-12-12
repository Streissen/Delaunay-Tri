//
// Created by hwj on 12/10/16.
//

#ifndef DELAUNAY_TRI_TRANGLE_H
#define DELAUNAY_TRI_TRANGLE_H

#include "Vertex.h"

class Triangle {
private:
    Vertex vertex[3];
public:
    Triangle();
    Triangle(Vertex vertex[3]);
    Triangle(Vertex v0, Vertex v1, Vertex v2);

    virtual ~Triangle();

    const Vertex *getVertex() const;

    Vertex get(int index) const;
    double getRadius() const;
    Vertex getCircumCenter() const;

    double getAverageHeight() const;

    bool contain(Vertex vertex) const;
    bool hasVertex(Vertex vertex);
};

#endif //DELAUNAY_TRI_TRANGLE_H
