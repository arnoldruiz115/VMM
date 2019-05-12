#include <iostream>
#include <fstream>
#include <string>
#include "MMU.hpp"


using namespace std;

MemoryManagementUnit::MemoryManagementUnit(){
}

void MemoryManagementUnit::read(){
	string line;
	int logical_address;
	cout << "Reading from text file." << endl;
	ifstream textFile("addresses.txt");
	while(getline(textFile, line)){
		logical_address = stoi(line);
		translateLogical(logical_address);
		cin.get();
	}
}

void MemoryManagementUnit::translateLogical(int address){
	int pageNumber = (address & ADDRESS_MASK) >> 8;			//Mask the 16 address bits then shift 8 to get page
	int offset = (address & OFFSET_MASK);					//Mask the 8 bits to get offset
	cout << "Page number: "<< pageNumber << " Offset: " << offset;
	bStore.read(pageNumber, offset);
}
