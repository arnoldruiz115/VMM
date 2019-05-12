#pragma once
#include <fstream>
#include "RAM.hpp"

class BackingStore{
public:
	BackingStore();
	void read(int page, int offset, RAM *Memory, int nextFrame);			//Read value from BackingStore given a pageNumber and offset
private:

};
