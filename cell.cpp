#include "cell.h"

Cell::Cell( const std::string& cname ) : name( cname )
{}

bool Cell::addVertex( const Vertex* vertex )
{
    vertices.push_back( vertex );
}

bool Cell::cellHasVertex( const std::string& vertexName ) const
{
    for ( const auto& vertex : vertices ) {
        if ( vertex->hasSameName( vertexName ) ) return true;
    }

    return false;
}

bool Cell::cellHasVertex( const double x, const double y, const double z ) const
{
    for ( const auto& vertex : vertices ) {
        if ( vertex->hasSameCoordinates( x, y, z ) ) return true;
    }

    return false;
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

