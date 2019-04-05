#include "pathfinder.h"
#include "pos.h"

#include <vector>
//#include <iostream>
//#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>



//helper functions

bool Reachable(const Kha::Pos& a, const Kha::Pos& b){
	return (float)sqrt(pow(a.row-b.row,2)+pow(a.col-b.col,2))==1.0f;
	//return true;
}



//PathFinder functions

Kha::PathFinder::PathFinder(): result(false){
	
}

Kha::PathFinder::~PathFinder(){
	
}

bool Kha::PathFinder::FindPath(const std::vector<float>& _mapping, int row, int col, int src_r, int src_c, int dest_r, int dest_c){

	//if current mapping is identical to cached mapping, return previous result
	int mapping_size = mapping.size();
	if(mapping_size==_mapping.size() && std::memcmp(&mapping.at(0), &_mapping.at(0), sizeof(mapping.at(0)*mapping_size))){
		return result;
	}

	//declare map for tracking search state
	Map map(_mapping, row, col);
	map.SpecSrc(src_r, src_c);
	map.SpecDest(dest_r, dest_c);

	//declare path storage to store full path travelled
	std::vector<Pos> full_path;

	//populate full_path
	while(!map.QueueEmpty()){
		int r = -1;
		int c = -1;
		float distance = map.PopQueue(&r, &c); //this call syncs state and queue and return smallest distance
		//check left
		full_path.push_back(Kha::Pos(r, c));
		//std::cout<<r<<" "<<c<<"\n";
		int cl = c-1;
		if(cl>=0){
		if(map[r][cl]==0) {result = true; break; }
			float dist = map.DistanceToSrc(r, c)+1.0f+map.DistanceToDest(r,cl);
			map.UpdateMap(r, cl, dist);
			if(map[r][cl]==-1 || dist<map[r][cl]){
				map[r][cl] = dist;
			}
		}
		//check right
		int cr = c+1;
		if(cr<map.COLS){
		if(map[r][cr]==0) {result = true; break; }
			float dist = map.DistanceToSrc(r, c)+1.0f+map.DistanceToDest(r,cr);
			map.UpdateMap(r, cr, dist);
			if(map[r][cr]==-1 || dist<map[r][cr]){
				map[r][cr] = dist;
			}
		}
		//check up
		int ru = r-1;
		if(ru>=0){
		if(map[ru][c]==0) {result = true; break; }
			float dist = map.DistanceToSrc(r, c)+1.0f+map.DistanceToDest(ru,c);
			map.UpdateMap(ru, c, dist);
			if(map[ru][c]==-1 || dist<map[ru][c]){
				map[ru][c] = dist;
			}
		}
		//check down
		int rd = r+1;
		if(rd<map.ROWS){
		if(map[rd][c]==0) {result = true; break; }
			float dist = map.DistanceToSrc(r, c)+1.0f+map.DistanceToDest(rd,c);
			map.UpdateMap(rd, c, dist);
			if(map[rd][c]==-1 || dist<map[rd][c]){
				map[rd][c] = dist;
			}
		}
	}

	//If a path is found, backtrace to find actual route from full path
	if(result){
		route.clear();
		//route.push_back(full_path.at(full_length-1));
		route.push_back(Pos(dest_r, dest_c));
		for(int i=0, j=full_path.size(); i<j; ++i){
			Pos const * last = &route.at(route.size()-1);
			if(Reachable(*last, full_path[i])){
				route.push_back(full_path[i]);
				j = i;
				i = 0;
			}
		}
		std::reverse(route.begin(), route.end());
	}

	return result;
}

const std::vector<Kha::Pos>& Kha::PathFinder::GetRoute() const{
	return route;
}

