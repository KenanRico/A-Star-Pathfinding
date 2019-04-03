#ifndef MAP_H
#define MAP_H
//----------------------------------------------


class Map{
	private:
		std::vector<bool> valid;
		std::vector<float> queue;
		uint32_t ROWS; uint32_t H;
		uint32_t COLS; uint32_t W;
		int rowi; int coli;
		int rowf; int colf;
	public:
		Map(const std::vector<float>&, uint32_t, uint32_t);
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
