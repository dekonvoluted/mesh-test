#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <string>

class Vertex
{
    std::string name = "";
    int xcoordinate = 0;
    int ycoordinate = 0;

    public:
    Vertex( const std::string&, const int, const int );
    ~Vertex() = default;

    bool hasSameName( const Vertex& ) const;
    bool hasSameName( const std::string& ) const;

    bool hasSameCoordinates( const Vertex& ) const;
    bool hasSameCoordinates( const int, const int ) const;

    bool operator==( const std::string& ) const;
    bool operator!=( const std::string& ) const;

    friend std::ostream& operator<<( std::ostream&, const Vertex& );
};

#endif

