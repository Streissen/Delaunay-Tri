//
// Created by hwj on 12/11/16.
//

#include "Edge.h"

Edge::Edge() {}
Edge::Edge(Vertex vertex[]) {
    for (int i = 0; i < 2; ++i) {
        this->vertex[i] = vertex[i];
    }
}
Edge::Edge(Vertex v0, Vertex v1) {
    if (v0.getX() <= v1.getX()) {
        this->vertex[0] = v0;
        this->vertex[1] = v1;
    } else {
        this->vertex[0] = v1;
        this->vertex[1] = v0;
    }
}

const Vertex *Edge::getvertex() const {
    return vertex;
}

Vertex Edge::get(int index) const {
    return vertex[index];
}

Edge::~Edge() {
    vertex[0].~Vertex();
    vertex[1].~Vertex();
}

std::ostream &operator<<(std::ostream &os, const Edge &edge) {
    os << "Edge: " << edge.vertex[0] << " " << edge.vertex[1];
    return os;
}

bool isSameEdge(Edge edge1,Edge edge2) {
    return isSameVertex(edge1.get(0), edge2.get(0)) && isSameVertex(edge1.get(1), edge2.get(1));
}