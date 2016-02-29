#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <string>

class Vertex
{
    std::string name = "";
    double xcoordinate = 0.0;
    double ycoordinate = 0.0;
    double zcoordinate = 0.0;

    public:
    Vertex( const std::string&, const double, const double, const double );
    ~Vertex() = default;

    bool hasSameName( const Vertex& ) const;
    bool hasSameName( const std::string& ) const;

    bool hasSameCoordinates( const Vertex& ) const;
    bool hasSameCoordinates( const double, const double, const double ) const;

    bool operator==( const std::string& ) const;
    bool operator!=( const std::string& ) const;

    friend std::ostream& operator<<( std::ostream&, const Vertex& );
};

#endif

