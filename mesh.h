#ifndef MESH_H
#define MESH_H

#include "cell.h"
#include "vertex.h"

#include <iostream>
#include <string>
#include <vector>

class Mesh
{
    std::vector<Vertex*> vertices;
    std::vector<Cell*> cells;

    public:
    Mesh( const std::string& );
    ~Mesh();

    int getVertexCount() const;
    int getCellCount() const;

    std::vector<Cell*> getCellsWithVertex( const std::string& ) const;
    std::vector<Cell*> getCellsWithVertex( const double, const double ) const;

    friend std::ostream& operator<<( std::ostream&, const Mesh& );
};

#endif

