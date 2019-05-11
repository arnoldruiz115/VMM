class MemoryManagementUnit{
public:
	MemoryManagementUnit();						//Class Constructor
	void read();								//Read in addresses from text file
	void clearTLB();
	void translateLogical(int address);			//Translate logical address to page number and offset
private:
	int page_access_count;
	int page_in_faults;
	int tlb_access_count;
	int tlb_faults;
	const int OFFSET_MASK = 0b11111111; 			//8 bits to mask the offset
	const int ADDRESS_MASK = 0b1111111100000000; 	//16 bits to mask the address
};
