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

void MemoryManagementUnit::TLBHits(){
	cout << "TLB Hit Rate: "<< tlb_access_count/10 << "%\n";
}

void MemoryManagementUnit::checkPageTable(int pageNumber, int offset, BackingStore *bStore){

	int frameNumber = -1;

	for(int i = 0; i < TLBPages.size(); i++){
		if(TLBPages[i] == pageNumber){
			frameNumber = TLBFrames[i];
			tlb_access_count++;
		}
	}


	for(int i = 0; i < pageTableCounter; i++){
		if(PageTable.pageNumbers[i] == pageNumber){
			frameNumber = PageTable.frameNumbers[i];
		}
	}
	if (frameNumber == -1){
		bStore->read(pageNumber, offset);
		PageTable.pageNumbers[pageTableCounter] = pageNumber;
		PageTable.frameNumbers[pageTableCounter] = openFrameCounter;
		openFrameCounter++;
		pageTableCounter++;
		page_in_faults++;						//page was not found so page fault occured.
		frameNumber = openFrameCounter - 1;
	}
	//TLB
	checkTLB(pageNumber, frameNumber);
}

void MemoryManagementUnit::checkTLB(int pageNumber,int frameNumber){
	bool alreadyInTLB = false;
	for(int i = 0; i < TLBPages.size(); i++){
		if(TLBPages[i] == pageNumber){
			alreadyInTLB = true;
			break;
		}
	}
	if(alreadyInTLB == false){
		if(TLBPages.size() == 16){
			TLBPages.erase(TLBPages.begin());
			TLBFrames.erase(TLBFrames.begin());
		}
		TLBPages.push_back(pageNumber);
		TLBFrames.push_back(frameNumber);
	}
}
