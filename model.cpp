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
    /*for (int i = 0; i < vertexNumber; ++i) {
        cout << "Round " << i << endl;
        while (true) {
            GLfloat x = Random(-0.5f, 0.5f);
            GLfloat y = Random(-0.5f, 0.5f);
            GLfloat height = Random(-0.5f, 0.5f);
            Vertex v = Vertex(x, y, height);
            if (i < 2) {
                cout << "Added " << v << endl;
                vertexes.push_back(v);
                break;
            }
            Triangle triangle(vertexes[i-2], vertexes[i-1], v);
            bool valid = true;
            for (int j = 0; j < i - 2; ++j) {
                if (triangle.contain(vertexes[j])) {
                    valid = false;
                    break;
                }
            }
            if (!valid)  {
                cout << "Dropped " << v << endl;
                continue;
            }
            cout << "Added " << v << endl;
            vertexes.push_back(v);
            triangles.push_back(triangle);
            break;
        }
    }*/
    for (int i = 0; i < vertexNumber; ++i) {
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
    }
}