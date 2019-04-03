#include "map.h"
#include "constants.h"

#include <cstring>
#include <cmath>
#include <iostream>


Map::Map(int (&array)[ROWS][COLS]): rowi(-1), coli(-1), rowf(-1), colf(-1){
	int row_size = sizeof(int)*W;
	for(int row=0; row<ROWS; ++row){
		//memcpy(state+row*W, &array[row][0], row_size);
		for(int col=0; col<COLS; ++col){
			state[row*W+col] = (float)array[row][col];
		}
	}
	std::memset(valid, 0, sizeof(valid));
	for(int i=0; i<ROWS*COLS; ++i){
		queue[i] = 10000.0f;
	}
}

Map::~Map(){}

float* Map::operator[](int row){
	return state+row*W;
}


//which ever gets specified last is responsible for setting src's distance

void Map::SpecSrc(int row, int col){
	rowi = row;
	coli = col;
	if(colf!=-1){
		float distance = sqrt(pow(rowf-rowi, 2)+pow(colf-coli, 2));
		UpdateMap(rowi, coli, distance);
	}
}

void Map::SpecDest(int row, int col){
	rowf = row;
	colf = col;
	(*this)[row][col] = 0;
	if(coli!=-1){
		float distance = sqrt(pow(rowf-rowi, 2)+pow(colf-coli, 2));
		UpdateMap(rowi, coli, distance);
	}
}

float Map::PopQueue(int* r, int* c){
	float dist = 100000.0f;
	for(int i=0; i<ROWS*COLS; ++i){
		if(valid[i] && queue[i]<dist && state[i]!=-2){
			dist = queue[i];
			*r = i/W;
			*c = i%W;
		}
	}
	valid[*r*W+*c] = false;
	return dist;
}

void Map::UpdateMap(int r, int c, float dist){
	if((*this)[r][c]==-1 || dist<(*this)[r][c]){
		(*this)[r][c] = dist;
	}
	int index = r*W+c;
	if(dist<queue[index]){
		valid[index] = true;
		queue[index] = dist;
	}
}

bool Map::QueueEmpty() const{
	bool result = true;
	for(int i=0; i<ROWS*COLS; ++i){
		if(valid[i]){
			result = false;
			break;
		}
	}
	return result;
}

float Map::DistanceToSrc(int r, int c) const{
	return (float)sqrt(pow(r-rowi, 2)+pow(c-coli, 2));
}

float Map::DistanceToDest(int r, int c) const{
	return (float)sqrt(pow(r-rowf, 2)+pow(c-colf, 2));
}
