#include "cell.h"

Cell::Cell( const std::string& cname ) : name( cname )
{}

bool Cell::addVertex( const Vertex* vertex )
{
    vertices.push_back( vertex );
}

std::ostream& operator<<( std::ostream& output, const Cell& cell )
{
    output << "Cell name: " << cell.name << std::endl;
    output << "Vertices: " << std::endl;
    for ( const auto& vertex : cell.vertices ) {
        output << *vertex << std::endl;
    }

    return output;
}

