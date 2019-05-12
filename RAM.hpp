#pragma once
#include "PCB.hpp"

class RAM{
public:
	RAM();
	void read();
	int physicalMemory[256][256];							//RAM is 256 frames * 256-byte frame
private:
};
