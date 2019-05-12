#pragma once
#include "PCB.hpp"
#include <vector>

class RAM{
public:
	RAM();
	void read();
	int physicalMemory[128][256];			//RAM is 128 frames * 256-byte frame
private:
};
