#include "mesh.h"

#include <iostream>

int main()
{
    Mesh mesh( "./mesh-test.dat" );

    std::cout << "Number of vertices: " << mesh.getVertexCount() << std::endl;
    std::cout << "Number of cells: " << mesh.getCellCount() << std::endl;

    std::cout << mesh << std::endl;

    return 0;
}

