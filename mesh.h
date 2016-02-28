#ifndef MESH_H
#define MESH_H

#include "vertex.h"

#include <string>
#include <vector>

class Mesh
{
    std::vector<Vertex*> vertices;
    int cellCount = 0;

    public:
    Mesh( const std::string& );
    ~Mesh();

    int getVertexCount();
    int getCellCount();
};

#endif

