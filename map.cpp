//
// Created by hwj on 12/10/16.
//

#include "Triangle.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include "Edge.h"

using namespace std;

Triangle superTriangle() {
    Vertex v0(-1.0, -1.0, 0.0);
    Vertex v1(1.0, -1.0, 0.0);
    Vertex v2(0.0, 1.0, 0.0);
    Triangle triangle(v0, v1, v2);
    return triangle;
}

void removeRepeat(vector<Edge> &edge_buffer) {
    /*for (auto &edge: edge_buffer) {
        cout << edge << endl;
    }*/
    for (auto iterator = edge_buffer.end(); iterator != edge_buffer.begin() + 1;) {
        --iterator;
        for (auto iterator1 = iterator; iterator1 != edge_buffer.begin();) {
            if (isSameEdge(*(--iterator1), *(iterator))) {
                iterator = edge_buffer.erase(iterator);
                edge_buffer.erase(iterator1);
                iterator--;
                break;
            }
        }
    }
}

vector<Triangle> map(vector<Vertex> vertexes) {
    sort(vertexes.begin(), vertexes.end(), [](Vertex left, Vertex right){
        return left.getX() < right.getX();
    });

    vector<Triangle> triangles;
    triangles.push_back(superTriangle());

    vector<Triangle> temp_triangle;
    temp_triangle.push_back(superTriangle());

    int v = 0;
    for (auto &vertex: vertexes) {
        cout << "Round " << v++ << endl;
        vector<Edge> edge_buffer;
        for (auto triangleItr = temp_triangle.begin(); triangleItr != temp_triangle.end();) {
            double Radius = (*triangleItr).getRadius();
            Vertex CircumCenter = (*triangleItr).getCircumCenter();
            if (vertex.getX() >= (CircumCenter.getX()+Radius)) {
                cout << vertex << " right to " << *triangleItr << endl;
                triangles.push_back(*triangleItr);
                triangleItr = temp_triangle.erase(triangleItr);
            } else if (vertex.getDistance(CircumCenter) < Radius) {
                cout << vertex << " in " << *triangleItr << endl;
                edge_buffer.push_back(Edge((*triangleItr).get(0), (*triangleItr).get(1)));
                edge_buffer.push_back(Edge((*triangleItr).get(1), (*triangleItr).get(2)));
                edge_buffer.push_back(Edge((*triangleItr).get(2), (*triangleItr).get(0)));
                triangleItr = temp_triangle.erase(triangleItr);
            } else {
                cout << vertex << " ??? " << *triangleItr << endl;
                triangleItr++;
            }
        }
        removeRepeat(edge_buffer);
        for (auto &edge: edge_buffer) {
            Triangle triangle(edge.get(0), edge.get(1), vertex);
            temp_triangle.push_back(triangle);
        }
    }
    for (auto &triangle: temp_triangle) {
        triangles.push_back(triangle);
    }
    for (auto iterator = triangles.end(); iterator != triangles.begin();) {
        Triangle supertriangle = superTriangle();
        --iterator;
        for (int i = 0; i < 3; ++i) {
            if ((*iterator).hasVertex(supertriangle.get(i))) {
                iterator = triangles.erase(iterator);
                break;
            }
        }
    }
    return triangles;
}