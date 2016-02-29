#include <cmath>

#include "vertex.h"

const double threshold = 1e-6;

Vertex::Vertex( const std::string& vname, const double x, const double y, const double z ) : name( vname ), xcoordinate( x ), ycoordinate( y ), zcoordinate( z )
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
    return ( std::fabs( xcoordinate - rhs.xcoordinate ) <= threshold ) and ( std::fabs( ycoordinate - rhs.ycoordinate ) <= threshold ) and ( std::fabs( zcoordinate - rhs.zcoordinate ) <= threshold );
}

bool Vertex::hasSameCoordinates( const double x, const double y, const double z ) const
{
    return ( std::fabs( xcoordinate - x ) <= threshold ) and ( std::fabs( ycoordinate - y ) <= threshold ) and ( std::fabs( zcoordinate - z ) <= threshold );
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
    output << "Vertex: " << vertex.name << "\t( " << vertex.xcoordinate << ", " << vertex.ycoordinate << ", " << vertex.zcoordinate << " )";

    return output;
}

