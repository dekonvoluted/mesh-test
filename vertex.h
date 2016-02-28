#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>

class Vertex
{
    long id = 0l;
    int xcoordinate = 0;
    int ycoordinate = 0;

    public:
    Vertex( const long, const int, const int );
    ~Vertex() = default;

    bool hasSameID( const Vertex& ) const;
    bool hasSameID( const long ) const;

    bool hasSameCoordinates( const Vertex& ) const;
    bool hasSameCoordinates( const int, const int ) const;

    bool operator==( const long ) const;
    bool operator!=( const long ) const;

    friend std::ostream& operator<<( std::ostream&, const Vertex& );
};

#endif

