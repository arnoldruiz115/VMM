#include <iostream>
#include <fstream>
#include "MMU.hpp"
#include "BackingStore.hpp"
#include "PCB.hpp"
#include "RAM.hpp"
#include "PageReplacementAlg.hpp"

const int OFFSET_MASK = 0b11111111; 					//8 bits to mask the offset
const int ADDRESS_MASK = 0b1111111100000000;			//16 bits to mask the address

int choice;
bool FIFO;

using namespace std;

int main(){

	MemoryManagementUnit MMU;
	BackingStore backingStore;
	RAM Memory;

	cout << "Virtual Memory Manager." << endl;
	cout << "Choose page replacement algorithm:\n1: FIFO\n2: LRU\n";
	cin >> choice;
	if(choice == 1){
		FIFO = true;
		cout << "FIFO Chosen.\n";
	}
	else {
		FIFO = false;
		cout << "LRU Chosen.\n";
	}

	int pageNumber, offset, logicalAddress;
	string line;

	cout << "Reading from text file." << endl;
	ifstream textFile("addresses.txt");
	while(getline(textFile, line)){
		logicalAddress = stoi(line);
		pageNumber = (logicalAddress & ADDRESS_MASK) >> 8;			//Mask the 16 address bits then shift 8 to get page
		offset = (logicalAddress & OFFSET_MASK);
		//cout << "Page number: "<< pageNumber << " Offset: " << offset << endl;
		MMU.checkPageTable(pageNumber, offset, &backingStore, &Memory, FIFO);
	}
	MMU.pageFaults();
	MMU.TLBHits();
	return 0;
}
