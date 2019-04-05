
#include "map.h"
#include "pos.h"
#include "pathfinder.h"

#include <iostream>
#include <functional>
#include <vector>


int main(){
	std::vector<float> mapping {
		-1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1,
		-1, -2, -1, -2, -2, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -2, -1, -1, -1, -1, -2, -1,
		-1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1,
		-1, -1, -1, -2, -2, -1, -2, -1, -1, -2, -1,
		-1, -2, -1, -1, -1, -1, -2, -1, -1, -1, -1,
		-1, -2, -1, -2, -1, -1, -1, -1, -1, -1, -1,
		-1, -2, -1, -2, -1, -1, -1, -1, -1, -1, -1
	};

	Kha::PathFinder path_finder(mapping, 8, 11);
	path_finder.SetSrc(6, 0);
	path_finder.SetDest(1, 7);


	if(path_finder.FindPath()){
		std::vector<Kha::Pos> route = path_finder.GetRoute();
		for(int i=0; i<route.size(); ++i){
			std::cout<<route[i].row<<" "<<route[i].col<<"\n";
		}
	}else{
		std::cout<<"Could not find a path\n";
	}
	return 0;
}

