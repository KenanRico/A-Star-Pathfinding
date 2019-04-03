#ifndef PATH_FINDER_H
#define PATH_FINDER_H
//------------------------------------


#include "pos.h"


#include <vector>

namespace Kha{
	class PathFinder{
		private:
			Map map;
			std::vector<Pos> route;
		public:
			PathFinder(const std::vector<int32_t>&);
			~PathFinder();
		private:
			PathFinder() = delete;
			PathFinder(const PathFinder&) = delete;
			PathFinder& operator=(const PathFinder&) = delete;
		public:
			bool FindPath();
			std::vector<Pos> GetRoute() const;
	};
}

//------------------------------------
#endif
