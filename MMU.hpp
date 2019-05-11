class MemoryManagementUnit{
public:
	MemoryManagementUnit();		//Class Constructor
	void read();				//Read in addresses from text file
	void clearTLB();
	void translateLogical(int address);	//Translate logical address to page number and offset
private:
	int page_access_count;
	int page_in_faults;
	int tlb_access_count;
	int tlb_faults;
};
