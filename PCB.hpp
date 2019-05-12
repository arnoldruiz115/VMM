#pragma once
struct PCB{						//Structure for page table
	int pageNumbers[256];		//Array to hold page numbers, 2^8 entries = 256
	int frameNumbers[256];		//Array to hold frame numbers, 256
};
