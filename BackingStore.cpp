#include <iostream>
#include <fstream>
#include <string>
#include "BackingStore.hpp"

using namespace std;

BackingStore::BackingStore(){

}

void BackingStore::read(int page, int offset){
	int physicalMemory[256][256];							//RAM is 256 frames * 256-byte frame
	ifstream binaryFile("BACKING_STORE.bin", ios::binary);	//open binaryFile
	uint32_t value;
	char buffer[256];
	binaryFile.seekg(page * 256);
	binaryFile.read(buffer, 256);
	for(int i = 0; i < 256; i++){
		physicalMemory[0][i] = buffer[i];
	}
	value = physicalMemory[0][offset];
	cout << " Value: " << value;
}
