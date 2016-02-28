#include "mesh.h"

#include <algorithm>
#include <fstream>
#include <iterator>
#include <sstream>
#include <stdexcept>

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
            auto xcoordinate = 0.0;
            auto ycoordinate = 0.0;
            lineStream >> xcoordinate;
            lineStream >> ycoordinate;

            // Record vertex
            vertices.push_back( new Vertex( vertexName, xcoordinate, ycoordinate ) );
        }

        // Record cells
        if ( line.find( "CELL" ) == 0 ) {

            std::stringstream lineStream( line );

            // Discard first string, take second as name
            std::string cellName = "";
            lineStream >> cellName;
            lineStream >> cellName;

            // Record cell
            cells.push_back( new Cell( cellName ) );

            // Record vertices bordering the cell
            std::string vertexName;
            while ( lineStream >> vertexName ) {
                auto iterator = std::find_if( vertices.begin(), vertices.end(), [ &vertexName ]( const Vertex* const vertex ) { return vertex->hasSameName( vertexName ); } );
                if ( iterator == vertices.end() ) {
                    std::runtime_error( "Vertex " + vertexName + " needed by Cell " + cellName + " not known." );
                }

                cells.back()->addVertex( *iterator );
            }
        }
    }
}

Mesh::~Mesh()
{
    // Release memory used by vertices
    for ( auto& vertex : vertices ) {
        delete vertex;
    }

    vertices.clear();

    // Release memory used by cells
    for ( auto& cell : cells ) {
        delete cell;
    }

    cells.clear();
}

int Mesh::getVertexCount() const
{
    return vertices.size();
}

int Mesh::getCellCount() const
{
    return cells.size();
}

std::vector<Cell*> Mesh::getCellsWithVertex( const std::string& vertexName ) const
{
    std::vector<Cell*> cellsWithVertex;
    auto cellHasVertex = [ &vertexName ]( const Cell* const cell )
    {
        return cell->cellHasVertex( vertexName );
    };

    std::copy_if( cells.begin(), cells.end(), std::back_inserter( cellsWithVertex ), cellHasVertex );

    return cellsWithVertex;
}

std::vector<Cell*> Mesh::getCellsWithVertex( const double x, const double y ) const
{
    std::vector<Cell*> cellsWithVertex;
    auto cellHasVertex = [ &x, &y ]( const Cell* const cell )
    {
        return cell->cellHasVertex( x, y );
    };

    std::copy_if( cells.begin(), cells.end(), std::back_inserter( cellsWithVertex ), cellHasVertex );

    return cellsWithVertex;
}

std::ostream& operator<<( std::ostream& output, const Mesh& mesh )
{
    for ( const auto& cell : mesh.cells ) {
        output << *cell << std::endl;
    }

    return output;
}

