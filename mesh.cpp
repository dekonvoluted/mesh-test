#include "mesh.h"

#include <fstream>
#include <sstream>

Mesh::Mesh( const std::string& datFilePath )
{
    // Open the file
    std::ifstream inFile( datFilePath.c_str() );

    // Just count vertices and cells
    std::string line;
    while ( std::getline( inFile, line ) ) {
        // Discard empty and commented lines
        if ( line.empty() ) continue;
        if ( line.front() == '#' ) continue;

        // Record vertices
        if ( line.find( "VERTEX" ) == 0 ) {

            std::stringstream lineStream( line );

            // Discard first string, take second as name
            std::string vertexName = "";
            lineStream >> vertexName;
            lineStream >> vertexName;

            // Record coordinates
            auto xcoordinate = 0;
            auto ycoordinate = 0;
            lineStream >> xcoordinate;
            lineStream >> ycoordinate;

            // Record vertex
            vertices.push_back( new Vertex( vertexName, xcoordinate, ycoordinate ) );
        }

        // Count vertices or cells
        if ( line.find( "CELL" ) != std::string::npos ) ++cellCount;
    }
}

Mesh::~Mesh()
{
    // Release memory used by vertices
    for ( auto& vertex : vertices ) {
        delete vertex;
    }

    vertices.clear();
}

int Mesh::getVertexCount()
{
    return vertices.size();
}

int Mesh::getCellCount()
{
    return cellCount;
}

