#ifndef MAP_H
#define MAP_H
//----------------------------------------------

#include <vector>
#include <cstdint>

namespace Kha{
	class Map{
		private:
			std::vector<bool> valid;
			std::vector<float> queue;
			int rowi; int coli;
			int rowf; int colf;
		public:
			const int ROWS; const int H;
			const int COLS; const int W;
		public:
			Map(const std::vector<float>&, int, int);
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
}

//----------------------------------------------
#endif
