#pragma once
#include <vector>
#include "RAM.hpp"
class PRA{
public:
	PRA();
	//First in first out algorithm
	void FIFO(char *buffer, RAM *Memory, int nextFrame);

	//Least Recently Used algorithm
	void LRU(char *buffer, RAM *Memory, int nextFrame);

	//Vector to keep track of frames in FIFO
	std::vector<int> FIFOTracker;

	//Vector to keep track of frames in LRU
	std::vector<int> LRUTracker;

	int LRUcounter;
	int FIFOcounter;
private:

};
