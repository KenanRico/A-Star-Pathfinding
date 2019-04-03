#ifndef MAP_H
#define MAP_H
//----------------------------------------------

#include "constants.h"

class Map{
	private:
		float state[ROWS*COLS];
		bool valid[ROWS*COLS];
		float queue[ROWS*COLS];
		int rowi; int coli;
		int rowf; int colf;
	public:
		Map(int (&array)[ROWS][COLS]);
		~Map();
	private:
		Map() = delete;
		Map(const Map&) = delete;
		Map& operator=(const Map&) = delete;
	public:
		float* operator[](int);
		void SpecSrc(int, int);
		void SpecDest(int, int);
		float PopQueue(int*, int*);
		void UpdateMap(int, int, float);
		bool QueueEmpty() const;
		float DistanceToSrc(int, int) const;
		float DistanceToDest(int, int) const;
};

//----------------------------------------------
#endif
