
#include "map.h"
#include "pos.h"
#include "pathfinder.h"

#include <iostream>
#include <functional>
#include <vector>


int main(){

	//Create PathFinder instance
	Kha::PathFinder path_finder;

	//Supply map info as float vector
	std::vector<float> mapping {
		-1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1,
		-1, -2, -1, -2, -2, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -2, -1, -1, -1, -1, -2, -1,
		-1, -2, -1, -2, -2, -2, -2, -2, -2, -2, -1,
		-1, -2, -1, -2, -2, -1, -2, -1, -1, -2, -1,
		-1, -2, -1, -1, -1, -1, -2, -1, -1, -1, -1,
		-1, -2, -1, -2, -1, -1, -1, -1, -1, -1, -1,
	};
	//Call FindPath() with mapping info, height(#rows)=7, width(#columns)=11, starting at (6,0), trying to reach (1,7)
	if(path_finder.FindPath(mapping, 7, 11, 6,0, 1,7)){
		//Call GetRoute() to retrieve optimal route; This call is meaningless if FindPath() returned false
		const std::vector<Kha::Pos>& route = path_finder.GetRoute();
		for(int i=0; i<route.size(); ++i){
			std::cout<<route[i].row<<" "<<route[i].col<<"\n";
		}
	}else{
		std::cout<<"Could not find a path\n";
	}
	return 0;
}

