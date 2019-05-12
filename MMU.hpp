#pragma once
#include "BackingStore.hpp"
#include "PCB.hpp"
class MemoryManagementUnit{
public:
	MemoryManagementUnit();						//Class Constructor
	void read();								//Read in addresses from text file
	void checkPageTable(int pageNumber, int offset);						//Check if page number from logical address is in PageTable
	void clearTLB();
	void translateLogical(int address);			//Translate logical address to page number and offset

private:
	BackingStore bStore;
	PCB PageTable;
	int page_access_count;
	int page_in_faults;
	int tlb_access_count;
	int tlb_faults;
	int pageTableCounter;
	int OFFSET_MASK; 					//8 bits to mask the offset
	int ADDRESS_MASK;					//16 bits to mask the address
};
