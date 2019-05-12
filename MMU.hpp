#pragma once
#include "BackingStore.hpp"
#include "RAM.hpp"
#include "PCB.hpp"
#include <vector>

class MemoryManagementUnit{
public:
	MemoryManagementUnit();						//Class Constructor
	void read();								//Read in addresses from text file
	void checkPageTable(int pageNumber, int offset, BackingStore *bStore, RAM *Memory);						//Check if page number from logical address is in PageTable
	void updateTLB(int pageNumber, int frameNumber);
	void clearTLB();
	void translateLogical(int address);			//Translate logical address to page number and offset
	void pageFaults();
	void TLBHits();
private:
	PCB PageTable;
	std::vector<int> TLBPages;
	std::vector<int> TLBFrames;
	int page_access_count;
	float page_in_faults;
	float tlb_access_count;
	int tlb_faults;
	int pageTableCounter;
	int openFrameCounter;
};
