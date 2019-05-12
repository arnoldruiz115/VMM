#pragma once
#include "BackingStore.hpp"
#include "PCB.hpp"
class MemoryManagementUnit{
public:
	MemoryManagementUnit();						//Class Constructor
	void read();								//Read in addresses from text file
	void checkPageTable(int pageNumber, int offset, BackingStore *bStore);						//Check if page number from logical address is in PageTable
	void clearTLB();
	void translateLogical(int address);			//Translate logical address to page number and offset
	void pageFaults();
private:
	PCB PageTable;
	int page_access_count;
	float page_in_faults;
	int tlb_access_count;
	int tlb_faults;
	int pageTableCounter;
	int openFrameCounter;
};
