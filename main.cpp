#include "mesh.h"

#include <iostream>

int main()
{
    Mesh mesh( "./mesh-test.dat" );

    std::cout << "Number of vertices: " << mesh.getVertexCount() << std::endl;
    std::cout << "Number of cells: " << mesh.getCellCount() << std::endl;

    std::cout << mesh << std::endl;

    // Check if mesh knows which cells contain a vertex
    auto cellsWithVertex = mesh.getCellsWithVertex( 5 );
    std::cout << "Cells with vertex 5: " << std::endl;
    for ( const auto& cell : cellsWithVertex ) {
        std::cout << *cell << std::endl;
    }

    // Check if mesh knows which cells contain a vertex by coordinate
    cellsWithVertex = mesh.getCellsWithVertex( 2, 2 );
    std::cout << "Cells with vertex ( 2, 2 ): " << std::endl;
    for ( const auto& cell : cellsWithVertex ) {
        std::cout << *cell << std::endl;
    }

    return 0;
}

