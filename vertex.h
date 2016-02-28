#ifndef VERTEX_H
#define VERTEX_H

#include <string>

class Vertex
{
    std::string name = "";
    int xcoordinate = 0;
    int ycoordinate = 0;

    public:
    Vertex( const std::string&, const int, const int );
    ~Vertex() = default;
};

#endif

