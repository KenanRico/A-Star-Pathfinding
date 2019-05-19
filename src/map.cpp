#include "map.h"

#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstdint>


Kha::Map::Map(const std::vector<float>& mapping, int rows, int cols): rowi(-1), coli(-1), rowf(-1), colf(-1), ROWS(rows), H(rows), COLS(cols), W(cols){
	queue = mapping;
	//valid.resize(queue.size());
	//std::memset(&valid.at(0), 0, valid.size()*sizeof(bool));
	valid.reserve(queue.size());
	for(int i=0; i<queue.size(); ++i){
		valid.push_back(false);
	}
}

Kha::Map::~Map(){}

float* Kha::Map::operator[](int row){
	return &queue[0]+row*W;
}


//which ever gets specified last is responsible for setting src's distance

void Kha::Map::SpecSrc(int row, int col){
	rowi = row;
	coli = col;
	if(colf!=-1){
		float distance = sqrt(pow(rowf-rowi, 2)+pow(colf-coli, 2));
		UpdateMap(rowi, coli, distance);
	}
}

void Kha::Map::SpecDest(int row, int col){
	rowf = row;
	colf = col;
	(*this)[row][col] = 0;
	if(coli!=-1){
		float distance = sqrt(pow(rowf-rowi, 2)+pow(colf-coli, 2));
		UpdateMap(rowi, coli, distance);
	}
}

float Kha::Map::PopQueue(int* r, int* c){
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

void Kha::Map::UpdateMap(int r, int c, float dist){
	int index = r*W+c;
	if(queue[index]==-1 || dist<queue[index]){
		valid[index] = true;
		queue[index] = dist;
	}
}

bool Kha::Map::QueueEmpty() const{
	bool result = true;
	for(int i=0; i<ROWS*COLS; ++i){
		if(valid[i]){
			result = false;
			break;
		}
	}
	return result;
}

float Kha::Map::DistanceToSrc(int r, int c) const{
	return (float)sqrt(pow(r-rowi, 2)+pow(c-coli, 2));
}

float Kha::Map::DistanceToDest(int r, int c) const{
	return (float)sqrt(pow(r-rowf, 2)+pow(c-colf, 2));
}
