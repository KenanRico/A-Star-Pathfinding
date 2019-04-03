
#include "constants.h"
#include "map.h"

#include <iostream>
#include <queue>
#include <functional>
#include <vector>


void PrintMap(Map&);


int main(void){
	//create map
	int map_array[H][W] = {
		{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -2, -1, -1, -1, -1, -1, -2, -1},
		{-1, -1, -1, -2, -2, -1, -2, -2, -2, -2, -1},
		{-1, -1, -1, -2, -2, -1, -1, -1, -1, -2, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	};
	Map map(map_array);
	PrintMap(map);

	//define src and dest
	map.SpecSrc(5, 3);
	map.SpecDest(1, 7);
	PrintMap(map);

	while(!map.QueueEmpty()){
		int r = -1;
		int c = -1;
		float distance = map.PopQueue(&r, &c); //this call syncs state and queue and return smallest distance
		//check left
		std::cout<<r<<" "<<c<<"\n";
		int cl = c-1;
		if(cl>=0){
		if(map[r][cl]==0) break;
			float dist = map.DistanceToSrc(r, c)+1.0f+map.DistanceToDest(r,cl);
			map.UpdateMap(r, cl, dist);
			if(map[r][cl]==-1 || dist<map[r][cl]){
				map[r][cl] = dist;
			}
		}
		//check right
		int cr = c+1;
		if(cr<COLS){
		if(map[r][cr]==0) break;
			float dist = map.DistanceToSrc(r, c)+1.0f+map.DistanceToDest(r,cr);
			map.UpdateMap(r, cr, dist);
			if(map[r][cr]==-1 || dist<map[r][cr]){
				map[r][cr] = dist;
			}
		}
		//check up
		int ru = r-1;
		if(ru>=0){
		if(map[ru][c]==0) break;
			float dist = map.DistanceToSrc(r, c)+1.0f+map.DistanceToDest(ru,c);
			map.UpdateMap(ru, c, dist);
			if(map[ru][c]==-1 || dist<map[ru][c]){
				map[ru][c] = dist;
			}
		}
		//check down
		int rd = r+1;
		if(rd<ROWS){
		if(map[rd][c]==0) break;
			float dist = map.DistanceToSrc(r, c)+1.0f+map.DistanceToDest(rd,c);
			map.UpdateMap(rd, c, dist);
			if(map[rd][c]==-1 || dist<map[rd][c]){
				map[rd][c] = dist;
			}
		}
	}
		PrintMap(map);

	

	return 0;
}

void PrintMap(Map& map){
	for(int i=0; i<ROWS; ++i){
		for(int j=0; j<W; ++j){
			std::cout<<map[i][j]<<" ";
		}
		std::cout<<"\n";
	}
}
