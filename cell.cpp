#include "cell.h"

Cell::Cell( const long cid ) : id( cid )
{}

bool Cell::addVertex( const Vertex* vertex )
{
    vertices.push_back( vertex );
}

bool Cell::cellHasVertex( const long vertexID ) const
{
    for ( const auto& vertex : vertices ) {
        if ( vertex->hasSameID( vertexID ) ) return true;
    }

    return false;
}

bool Cell::cellHasVertex( const int x, const int y ) const
{
    for ( const auto& vertex : vertices ) {
        if ( vertex->hasSameCoordinates( x, y ) ) return true;
    }

    return false;
}

std::ostream& operator<<( std::ostream& output, const Cell& cell )
{
    output << "Cell ID: " << cell.id << std::endl;
    output << "Vertices: " << std::endl;
    for ( const auto& vertex : cell.vertices ) {
        output << *vertex << std::endl;
    }

    return output;
}

