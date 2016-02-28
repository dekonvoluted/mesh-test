#include "vertex.h"

Vertex::Vertex( const long vid, const int x, const int y ) : id( vid ), xcoordinate( x ), ycoordinate( y )
{}

bool Vertex::hasSameID( const Vertex& rhs ) const
{
    return id == rhs.id;
}

bool Vertex::hasSameID( const long vertexID ) const
{
    return id == vertexID;
}

bool Vertex::hasSameCoordinates( const Vertex& rhs ) const
{
    return ( xcoordinate == rhs.xcoordinate ) and ( ycoordinate == rhs.ycoordinate );
}

bool Vertex::hasSameCoordinates( const int x, const int y ) const
{
    return ( xcoordinate == x ) and ( ycoordinate == y );
}

bool Vertex::operator==( const long rhsID ) const
{
    return hasSameID( rhsID );
}

bool Vertex::operator!=( const long rhsID ) const
{
    return not operator==( rhsID );
}

std::ostream& operator<<( std::ostream& output, const Vertex& vertex )
{
    output << "Vertex: " << vertex.id << "\t( " << vertex.xcoordinate << ", " << vertex.ycoordinate << " )";

    return output;
}

