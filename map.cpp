//
// Created by hwj on 12/10/16.
//

#include "Triangle.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include "model.h"
#include "Vertex.h"
#include "map.h"
#include "Edge.h"

using namespace std;

void newOrder(vector<Vertex> vertexes) {
    sort(vertexes.begin(), vertexes.end(), [](Vertex left, Vertex right){
        return left.getX() < right.getX();
    });
    for (auto &vertex: vertexes) {
        cout << vertex << endl;
    }
}

Triangle superTriangle(double screenWidth, double screenHight) {
    double x, y;
    x = -2*screenWidth;
    y = -2*screenHight;
    Vertex v0(x, y, 0.0);
    x = 2*screenWidth;
    y = -2*screenHight;
    Vertex v1(x, y, 0.0);
    x = 0;
    y = -2*screenHight;
    Vertex v2(x, y, 0.0);
    Triangle triangle(v0, v1, v2);
    return triangle;
}              //TODO hight

void removeRepeat(vector<Edge> edge_buffer) {
    for (auto iterator = edge_buffer.begin(); iterator < edge_buffer.end(); ++iterator) {
        for (auto iterator1 = iterator + 1; iterator < edge_buffer.end(); ++iterator1) {
            if (isSameEdge(*iterator1,*iterator))
                edge_buffer.erase(iterator1);
        }
    }
}

vector<Triangle> map(vector<Vertex> vertexes) {
    vector<Triangle> triangles;
    vector<Triangle> temp_triangle;
    vector<Edge> edge_buffer;
    temp_triangle.push_back(superTriangle(5.0, 5.0));
    triangles.push_back(superTriangle(5.0, 5.0));
    for (auto &vertex: vertexes ) {
        edge_buffer.clear();
        for (auto &triangle: temp_triangle) {
            double Radius = triangle.getRadius();
            Vertex CircumCenter = triangle.getCircumCenter();
            if (vertex.getX() >= (CircumCenter.getX()+Radius)) {
                triangles.push_back(triangle);
                temp_triangle.pop_back();
                break;
            } else if (triangle.contain(vertex)) {
                Edge edge0(vertex, triangle.get(0));
                edge_buffer.push_back(edge0);
                Edge edge1(vertex, triangle.get(1));
                edge_buffer.push_back(edge1);
                Edge edge2(vertex, triangle.get(2));
                edge_buffer.push_back(edge2);
                temp_triangle.pop_back();
                break;
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
    for (auto iterator = triangles.begin(); iterator != triangles.end();) {
        Triangle supertriangle = superTriangle(5.0, 5.0);
        for (int i = 0; i < 3; ++i) {
            if ((*iterator).hasVertex(supertriangle.get(i))) {
                iterator = triangles.erase(iterator);
            } else {
                iterator++;
            }
        }
    }
    return triangles;
}