#ifndef PATH_FINDER_H
#define PATH_FINDER_H
//------------------------------------


#include "pos.h"
#include "map.h"


#include <vector>

namespace Kha{
	class PathFinder{
		private:
			std::vector<float> mapping;
			std::vector<Pos> route;
			bool result;
		public:
			PathFinder();
			~PathFinder();
		private:
			PathFinder(const PathFinder&) = delete;
			PathFinder& operator=(const PathFinder&) = delete;
		public:
			bool FindPath(const std::vector<float>&, int, int, int, int, int, int);
			const std::vector<Pos>& GetRoute() const;
	};
}


//------------------------------------
#endif
