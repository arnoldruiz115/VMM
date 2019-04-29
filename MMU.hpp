class MemoryManagementUnit{
public:
	MemoryManagementUnit();
	void talk();
private:
	int page_access_count;
	int page_in_faults;
	int tlb_access_count;
	int tlb_faults;
};
