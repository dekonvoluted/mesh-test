#include <cmath>

#include "vertex.h"

const double threshold = 1e-6;

Vertex::Vertex( const std::string& vname, const double x, const double y ) : name( vname ), xcoordinate( x ), ycoordinate( y )
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

bool Vertex::hasSameCoordinates( const double x, const double y ) const
{
    return ( std::fabs( xcoordinate - x ) <= threshold ) and ( std::fabs( ycoordinate - y ) <= threshold );
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

