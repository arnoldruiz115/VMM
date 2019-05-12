#include <iostream>
#include <fstream>
#include "MMU.hpp"
#include "BackingStore.hpp"
#include "PCB.hpp"

const int OFFSET_MASK = 0b11111111; 					//8 bits to mask the offset
const int ADDRESS_MASK = 0b1111111100000000;			//16 bits to mask the address

using namespace std;

int main(){

	cout << "Virtual Memory Manager." << endl;
	MemoryManagementUnit MMU;
	BackingStore backingStore;

	int pageNumber, offset, logicalAddress;
	string line;

	cout << "Reading from text file." << endl;
	ifstream textFile("addresses.txt");
	while(getline(textFile, line)){
		logicalAddress = stoi(line);
		pageNumber = (logicalAddress & ADDRESS_MASK) >> 8;			//Mask the 16 address bits then shift 8 to get page
		offset = (logicalAddress & OFFSET_MASK);
		cout << "Page number: "<< pageNumber << " Offset: " << offset;
		MMU.checkPageTable(pageNumber, offset, &backingStore);
		cin.get();
	}
	MMU.pageFaults();
	return 0;
}
