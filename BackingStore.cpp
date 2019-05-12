#include <iostream>
#include <fstream>
#include <string>
#include "BackingStore.hpp"
#include "RAM.hpp"
#include <vector>

using namespace std;

BackingStore::BackingStore(){
	LRUcounter = 0;
}

void BackingStore::read(int page, int offset, RAM *Memory, int nextFrame, bool FIFO){							//RAM is 256 frames * 256-byte frame
	ifstream binaryFile("BACKING_STORE.bin", ios::binary);	//open binaryFile
	int value;
	char buffer[256];
	binaryFile.seekg(page * 256);
	binaryFile.read(buffer, 256);

	if(FIFO == true) {
		pageReplacer.FIFO(buffer, Memory, nextFrame);
	}
	else {
		pageReplacer.LRU(buffer, Memory, nextFrame);
	}
	binaryFile.close();
}
