#include "vertex.h"

Vertex::Vertex( const std::string& vname, const int x, const int y ) : name( vname ), xcoordinate( x ), ycoordinate( y )
{}

bool Vertex::hasSameName( const Vertex& rhs ) const
{
    return name == rhs.name;
}

bool Vertex::hasSameName( const std::string& vertexName ) const
{
    return name == vertexName;
}

bool Vertex::hasSameCoordinates( const Vertex& rhs ) const
{
    return ( xcoordinate == rhs.xcoordinate ) and ( ycoordinate == rhs.ycoordinate );
}

bool Vertex::hasSameCoordinates( const int x, const int y ) const
{
    return ( xcoordinate == x ) and ( ycoordinate == y );
}

bool Vertex::operator==( const std::string& rhsName ) const
{
    return hasSameName( rhsName );
}

bool Vertex::operator!=( const std::string& rhsName ) const
{
    return not operator==( rhsName );
}

std::ostream& operator<<( std::ostream& output, const Vertex& vertex )
{
    output << "Vertex: " << vertex.name << "\t( " << vertex.xcoordinate << ", " << vertex.ycoordinate << " )";

    return output;
}

