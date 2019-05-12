#include <iostream>
#include <fstream>
#include <string>
#include "MMU.hpp"
using namespace std;



MemoryManagementUnit::MemoryManagementUnit(){
	pageTableCounter = 0;
	page_in_faults = 0;
	openFrameCounter = 0;			//counter to keep track where the next open frame is
}

void MemoryManagementUnit::read(){

}

void MemoryManagementUnit::pageFaults(){
	cout << "Page Fault Rate: "<< page_in_faults/10 << "%\n";
}

void MemoryManagementUnit::checkPageTable(int pageNumber, int offset, BackingStore *bStore){
	int frame = -1;
	for(int i = 0; i < pageTableCounter; i++){
		if(PageTable.pageNumbers[i] == pageNumber){
			frame = PageTable.frameNumbers[i];
		}
	}
	if (frame == -1){
		bStore->read(pageNumber, offset);
		PageTable.pageNumbers[pageTableCounter] = pageNumber;
		PageTable.frameNumbers[pageTableCounter] = openFrameCounter;

		openFrameCounter++;
		pageTableCounter++;
		page_in_faults++;						//page was not found so page fault occured.
		frame = openFrameCounter - 1;

	}
}
