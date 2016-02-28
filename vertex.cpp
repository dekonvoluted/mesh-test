#include "vertex.h"

Vertex::Vertex( const std::string& vname, const int x, const int y ) : name( vname ), xcoordinate( x ), ycoordinate( y )
{}

bool Vertex::operator==( const std::string& rhsName ) const
{
    return name == rhsName;
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

