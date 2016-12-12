//
// Created by hwj on 12/11/16.
//

#ifndef DELAUNAY_TRI_EDGE_H
#define DELAUNAY_TRI_EDGE_H


#include "Vertex.h"


class Edge {
private:
    Vertex vertex[2];
public:
    Edge();
    Edge(Vertex vertex[2]);
    Edge(Vertex v0, Vertex v1);

    const Vertex *getvertex() const;

    Vertex get(int index) const;
};

bool isSameEdge(Edge edge1, Edge edge2);


#endif //DELAUNAY_TRI_EDGE_H
