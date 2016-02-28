#ifndef CELL_H
#define CELL_H

#include "vertex.h"

#include <iostream>
#include <string>
#include <vector>

class Cell
{
    std::string name = "";
    std::vector<const Vertex*> vertices;

    public:
    Cell( const std::string& );

    // Cell does not own the vertices resources
    ~Cell() = default;

    bool addVertex( const Vertex* );

    friend std::ostream& operator<<( std::ostream&, const Cell& );
};

#endif

