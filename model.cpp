//
// Created by xdroid on 12/8/16.
//

#include <vector>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "model.h"
#include "Vertex.h"
#include "Triangle.h"

using namespace std;

vector<Vertex> vertexes;
vector<Triangle> triangles;

inline double Random(double b, double t) {
    return b + (t-b) * rand() / RAND_MAX;
}

void initModel() {
    int vertexNumber = 10;
    for (int i = 0; i < vertexNumber; ++i) {
        double x = Random(-0.5f, 0.5f);
        double y = Random(-0.5f, 0.5f);
        double height = Random(-0.5f, 0.5f);
        Vertex v = Vertex(x, y, height);
        vertexes.push_back(v);
    }
    /*for (int i = 0; i < vertexNumber; ++i) {
        double x = cos(3.1415926*2*i/vertexNumber);
        double y = sin(3.1415926*2*i/vertexNumber);
        double height = Random(0, 1.0);
        Vertex v = Vertex(x, y, height);
        if (i >= 2) {
            Triangle triangle(vertexes[0], vertexes[i-1], v);
            triangles.push_back(triangle);
        }
        cout << "Added " << v << endl;
        vertexes.push_back(v);
    }

    for (auto &vertex : vertexes) {
        cout << vertex << endl;
    }*/
}