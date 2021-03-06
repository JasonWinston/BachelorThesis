// author: dybisz

#include "cube.h"

using namespace geometry;
using namespace glm;
using namespace std;

CCube::CCube(float size) : _size(size) { }

CCube::CCube(vec3 centerVertex, float size) : _center(centerVertex),
                                              _size(size)
        { }

// TODO: my God, it needs to be changed
Vertex *CCube::generateVertices() {
        Vertex *vertices = new Vertex[8];
        float halfSize = _size / 2;
        vertices[0].position = glm::vec3(_center.x - halfSize,
                                         _center.y - halfSize,
                                         _center.z - halfSize);
        vertices[1].position = glm::vec3(_center.x + halfSize,
                                         _center.y - halfSize,
                                         _center.z - halfSize);
        vertices[2].position = glm::vec3(_center.x + halfSize,
                                         _center.y + halfSize,
                                         _center.z - halfSize);
        vertices[3].position = glm::vec3(_center.x - halfSize,
                                         _center.y + halfSize,
                                         _center.z - halfSize);
        vertices[4].position = glm::vec3(_center.x - halfSize,
                                         _center.y - halfSize,
                                         _center.z + halfSize);
        vertices[5].position = glm::vec3(_center.x + halfSize,
                                         _center.y - halfSize,
                                         _center.z + halfSize);
        vertices[6].position = glm::vec3(_center.x + halfSize,
                                         _center.y + halfSize,
                                         _center.z + halfSize);
        vertices[7].position = glm::vec3(_center.x - halfSize,
                                         _center.y + halfSize,
                                         _center.z + halfSize);
        return vertices;
    }

    GLuint *CCube::generateIndices() {
        // 6 sides, each with 2 triangles created from 3 vertices
        _totalIndices = 6 * 2 * 3;
        GLuint *indices = new GLuint[6 * 2 * 3];
        int offset = 0;

        indices[offset++] = 0;
        indices[offset++] = 4;
        indices[offset++] = 5;
        indices[offset++] = 5;
        indices[offset++] = 1;
        indices[offset++] = 0;

        //top face
        indices[offset++] = 3;
        indices[offset++] = 6;
        indices[offset++] = 7;
        indices[offset++] = 3;
        indices[offset++] = 2;
        indices[offset++] = 6;

        //front face
        indices[offset++] = 7;
        indices[offset++] = 6;
        indices[offset++] = 4;
        indices[offset++] = 6;
        indices[offset++] = 5;
        indices[offset++] = 4;

        //back face
        indices[offset++] = 2;
        indices[offset++] = 3;
        indices[offset++] = 1;
        indices[offset++] = 3;
        indices[offset++] = 0;
        indices[offset++] = 1;

        //left face
        indices[offset++] = 3;
        indices[offset++] = 7;
        indices[offset++] = 0;
        indices[offset++] = 7;
        indices[offset++] = 4;
        indices[offset++] = 0;

        //right face
        indices[offset++] = 6;
        indices[offset++] = 2;
        indices[offset++] = 5;
        indices[offset++] = 2;
        indices[offset++] = 1;
        indices[offset++] = 5;

        return indices;
    }

    int CCube::getTotalVertices() {
        return 8;
    }

    int CCube::getTotalIndices() {
        return _totalIndices;
    }