#ifndef MESH_H
#define MESH_H

#include <string>

class Mesh
{
    int vertexCount = 0;
    int cellCount = 0;

    public:
    Mesh( const std::string& );
    ~Mesh() = default;

    int getVertexCount();
    int getCellCount();
};

#endif

