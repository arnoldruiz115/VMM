#include <iostream>
#include <fstream>
#include <string>
#include "BackingStore.hpp"
#include "RAM.hpp"

using namespace std;

BackingStore::BackingStore(){

}

void BackingStore::read(int page, int offset, RAM *Memory, int nextFrame){							//RAM is 256 frames * 256-byte frame
	ifstream binaryFile("BACKING_STORE.bin", ios::binary);	//open binaryFile
	int value;
	char buffer[256];
	binaryFile.seekg(page * 256);
	binaryFile.read(buffer, 256);
	for(int i = 0; i < 256; i++){
		Memory->physicalMemory[nextFrame][i] = buffer[i];
	}
	value = Memory->physicalMemory[nextFrame][offset];
	//cout << " Value " << value << endl;
}
