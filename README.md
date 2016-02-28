# Background/Current goal

A mesh is a collection of vertices connected by edges and forming cells.
For the scope of this project, let's assume that a list of vertices and a list of cells are provided externally in a file that looks like this,

```
VERTEX UNIQNAME X-COORDINATE Y-COORDINATE
...
CELL UNIQNAME VERTEXNAME VERTEXNAME ...
...
```

We would like to read this in and store it for queries.
* Get a list of vertices in the domain
* Get a list of cells in the domain
* Given a vertex, how many cells is it a part of?
* Given a vertex, how many other vertices is it connected to?
* Given a cell, how many vertices/edges does it have?
* Given a coordinate, which cell is the coordinate in?

# Building instructions

To build in-source, do,

```
% cmake .
% make
% ./mesh
```

To build out of source, do,

```
% mkdir build/
% cd build/
% cmake ..
% make
% ./mesh
```

If successful, you should see a list of cells and their vertices as defined in the test data printed out.

