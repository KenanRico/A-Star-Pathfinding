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
//suppose path_finder is an instance of Kha::PathFinder
Kha::PathFinder path_finder(mapping, 8, 11);
path_finder.SetSrc(6, 0);
path_finder.SetDest(1, 7);
path_finder.FindPath();
std::vector<Kha::Pos> route = path_finder.GetRoute();
~~~
Where mapping is a std::vector<float> representation of the mapping, where open spaces are represented by -1, and obsticles are represented by -2. The two numbers are dimension parameters, first being #rows, second being #columns. There params need to be supplied to PathFinder instance on initialization.

An example is supplied in main.cpp
