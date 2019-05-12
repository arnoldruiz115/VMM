#include <iostream>
#include <fstream>
#include <string>
#include "MMU.hpp"
using namespace std;



MemoryManagementUnit::MemoryManagementUnit(){
	pageTableCounter = 0;
	OFFSET_MASK = 0b11111111;
	ADDRESS_MASK = 0b1111111100000000;
}

void MemoryManagementUnit::read(){
	string line;
	int logicalAddress;
	cout << "Reading from text file." << endl;
	ifstream textFile("addresses.txt");
	while(getline(textFile, line)){
		logicalAddress = stoi(line);
		translateLogical(logicalAddress);
		cin.get();
	}
}

void MemoryManagementUnit::translateLogical(int address){
	int pageNumber = (address & ADDRESS_MASK) >> 8;			//Mask the 16 address bits then shift 8 to get page
	int offset = (address & OFFSET_MASK);					//Mask the 8 bits to get offset
	cout << "Page number: "<< pageNumber << " Offset: " << offset << endl;
	checkPageTable(pageNumber, offset);
	//bStore.read(pageNumber, offset);
}

void MemoryManagementUnit::checkPageTable(int pageNumber, int offset){
	int frame = -1;
	for(int i = 0; i < pageTableCounter; i++){
		if(PageTable.pageNumbers[i] == pageNumber){
			frame = PageTable.frameNumbers[i];
		}
	}
	if (frame == -1){
		bStore.read(pageNumber, offset);
	}
}
