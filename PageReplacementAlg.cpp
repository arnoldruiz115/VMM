#include "PageReplacementAlg.hpp"
#include "RAM.hpp"

PRA::PRA(){

}

void PRA::FIFO(char *buffer, RAM *Memory, int nextFrame){
	bool found = false;

	if(FIFOcounter < 128){
		FIFOTracker.push_back(nextFrame);
		for(int i = 0; i < 256; i++){
			Memory->physicalMemory[FIFOcounter][i] = buffer[i];
		}
		FIFOcounter++;
	}
	else{
		FIFOTracker.erase(FIFOTracker.begin());
		FIFOTracker.push_back(nextFrame);
		for(int i = 0; i < 256; i++){
			Memory->physicalMemory[FIFOTracker.size() - 1][i] = buffer[i];
		}
		FIFOcounter++;
	}

}

void PRA::LRU(char *buffer, RAM *Memory, int nextFrame){
	bool found = false;
	if(LRUcounter < 128){
		LRUTracker.push_back(nextFrame);		//If free frames available, simply add to memory
		for(int i = 0; i < 256; i++){
			Memory->physicalMemory[LRUcounter][i] = buffer[i];
		}
		LRUcounter++;
	}
	else{
		for(int i = 0; i < LRUTracker.size(); i++){
			if(LRUTracker[i] == nextFrame){
				LRUTracker.erase(LRUTracker.begin() + i);
				LRUTracker.push_back(nextFrame);
				for(int j = 0; j < 256; j++){
					Memory->physicalMemory[LRUTracker[i]][j] = buffer[j];
				}
				found = true;
				break;
			}
		}
		if(found == false){
			LRUTracker.erase(LRUTracker.begin());
			LRUTracker.push_back(nextFrame);
			for(int i = 0; i < 256; i++){
				Memory->physicalMemory[LRUTracker.size() - 1][i] = buffer[i];
			}
			LRUcounter++;
		}
	}
}
