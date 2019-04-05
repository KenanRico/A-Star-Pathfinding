#ifndef PATH_FINDER_H
#define PATH_FINDER_H
//------------------------------------


#include "pos.h"
#include "map.h"


#include <vector>

namespace Kha{
	class PathFinder{
		private:
			Map map;
			std::vector<Pos> route;
		public:
			PathFinder(const std::vector<float>&, int, int);
			~PathFinder();
		private:
			PathFinder() = delete;
			PathFinder(const PathFinder&) = delete;
			PathFinder& operator=(const PathFinder&) = delete;
		public:
			void SetSrc(int, int);
			void SetDest(int, int);
			bool FindPath();
			std::vector<Pos> GetRoute() const;
	};
}

//helper
bool Reachable(const Kha::Pos&, const Kha::Pos&);

//------------------------------------
#endif
