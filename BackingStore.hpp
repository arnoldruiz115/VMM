#pragma once
#include <fstream>

class BackingStore{
public:
	BackingStore();
	void read(int page, int offset);			//Read value from BackingStore given a pageNumber and offset
private:
};
