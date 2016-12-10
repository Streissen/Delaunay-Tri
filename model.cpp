//
// Created by xdroid on 12/8/16.
//

#include <GL/gl.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "model.h"
#include "Vertex.h"

using namespace std;

vector<Vertex> vertexes;

inline float Random(float b, float t) {
    return b + (t-b) * rand() / RAND_MAX;
}

void initModel() {
    int vertexNumber = 10;
    for (int i = 0; i < vertexNumber; ++i) {
        GLfloat x = Random(-0.5f, 0.5f);
        GLfloat y = Random(-0.5f, 0.5f);
        GLfloat height = Random(-0.5f, 0.5f);
        vertexes.push_back(Vertex(x, y, height));
    }
    for (auto &vertex : vertexes) {
        cout << vertex << endl;
    }
}