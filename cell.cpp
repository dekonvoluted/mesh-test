#include "cell.h"

Cell::Cell( const std::string& cname ) : name( cname )
{}

bool Cell::addVertex( const Vertex* vertex )
{
    vertices.push_back( vertex );
}

