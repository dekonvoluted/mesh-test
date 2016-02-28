#ifndef CELL_H
#define CELL_H

#include "vertex.h"

#include <iostream>
#include <vector>

class Cell
{
    long id = 0l;
    std::vector<const Vertex*> vertices;

    public:
    Cell( const long );

    // Cell does not own the vertices resources
    ~Cell() = default;

    bool addVertex( const Vertex* );
    bool cellHasVertex( const long ) const;
    bool cellHasVertex( const int, const int ) const;

    friend std::ostream& operator<<( std::ostream&, const Cell& );
};

#endif

