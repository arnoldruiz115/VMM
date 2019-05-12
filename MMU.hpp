#pragma once
#include "BackingStore.hpp"
#include "RAM.hpp"
#include "PCB.hpp"
#include <vector>

class MemoryManagementUnit{
public:
	MemoryManagementUnit();						//Class Constructor

	//Check if page number from logical address is in TLB, then PageTable
	void checkPageTable(int pageNumber, int offset, BackingStore *bStore, RAM *Memory, bool FIFO);

	//Update the TLB with page number and frame
	void updateTLB(int pageNumber, int frameNumber);
	void clearTLB();
	void pageFaults();
	void ResetFrameCounter();
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
