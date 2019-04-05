A* Pathfinding
===============
A* Pathfinding is a backtracking + greedy approach to pathfinding algorithm. This project includes source code to an implementation of the algorithm in C++.

## Usage
To integrate the code into your projects, include the pathfinder and pos header into your codebase:
~~~
#include "pathfinder.h"
#include "pos.h"
~~~
Resources reside in the Kha namespace. The call to finding optimal paths are:
~~~
//generate path in PathFinder instance
bool Kha::PathFinder::FindPath(
	const std::vector<float>& mapping,
	int row_count, int column_count, 
	int source_row_number, int source_column_number
	int dest_row_number, int dest_column_numer
);
//return optimal route
const std::vector<Pos>& Kha::PathFinder::GetRoute();
~~~
Supply your map via a vector of floats, where -1's are open spaces and -2's are walls (obsticles).
PathFinder objects cache mapping and route info for optimization for subsequent searches, so it is recommanded to reuse the same PathFinder object.
"main.cpp" serves as a sample use case
