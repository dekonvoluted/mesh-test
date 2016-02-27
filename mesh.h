#ifndef MESH_H
#define MESH_H

#include <string>

class Mesh
{
    public:
    Mesh( const std::string& );
    ~Mesh() = default;

    int getVertexCount();
    int getCellCount();
};

#endif

