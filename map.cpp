#include "map.h"

#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>


Map::Map(const std::vector<float>& mapping, uint32_t rows, uint32_t cols): rowi(-1), coli(-1), rowf(-1), colf(-1), ROWS(rows), H(rows), COLS(cols), W(cols){
	queue = mapping;
	valid.resize(queue.size());
	std::memset(valid, 0, valid.size()*sizeof(bool));
}

Map::~Map(){}

float* Map::operator[](int row){
	return queue+row*W;
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
		if(valid[i] && queue[i]<dist && queue[i]!=-2){
			dist = queue[i];
			*r = i/W;
			*c = i%W;
		}
	}
	valid[*r*W+*c] = false;
	return dist;
}

void Map::UpdateMap(int r, int c, float dist){
	int index = r*W+c;
	if(queue[index]==-1 || dist<queue[index]){
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
