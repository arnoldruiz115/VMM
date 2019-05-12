#pragma once
#include <fstream>
#include <vector>
#include "RAM.hpp"
#include "PageReplacementAlg.hpp"

class BackingStore{
public:
	BackingStore();
	void read(int page, int offset, RAM *Memory, int nextFrame, bool FIFO);			//Read value from BackingStore given a pageNumber and offset
	std::vector<int> LRUTracker;
	std::vector<int> FIFOTracker;
	int LRUcounter;
	int FIFOcounter;
private:
	PRA pageReplacer;
};
