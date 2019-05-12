#include <iostream>
#include <fstream>
#include "MMU.hpp"
#include "BackingStore.hpp"
#include "PCB.hpp"



using namespace std;

int main(){

	cout << "Virtual Memory Manager." << endl;
	MemoryManagementUnit MMU;
	MMU.read();


	return 0;
}
