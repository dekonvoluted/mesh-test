#include "mesh.h"

#include <fstream>

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

        // Count vertices or cells
        if ( line.find( "VERTEX" ) != std::string::npos ) ++vertexCount;
        if ( line.find( "CELL" ) != std::string::npos ) ++cellCount;
    }
}

int Mesh::getVertexCount()
{
    return vertexCount;
}

int Mesh::getCellCount()
{
    return cellCount;
}

