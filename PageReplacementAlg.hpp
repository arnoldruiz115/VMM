#pragma once
#include <vector>
#include "RAM.hpp"
class PRA{
public:
	PRA();
	void FIFO(char *buffer, RAM *Memory, int nextFrame);
	void LRU(char *buffer, RAM *Memory, int nextFrame);
	std::vector<int> FIFOTracker;
	std::vector<int> LRUTracker;
	int LRUcounter;
	int FIFOcounter;
private:

};
