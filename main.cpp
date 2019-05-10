#include <iostream>
#include <fstream>
#include "MMU.hpp"



using namespace std;

int main(){

	cout << "Virtual Memory Manager." << endl;
	MemoryManagementUnit MMU;

	char address[256];

	ifstream address_file;
	address_file.open("addresses.txt");
	address_file.seekg(0, ios::cur);
	address_file >> address;
	//cout << address << endl;

	char buffer[65535];
	ifstream backing_store;
	backing_store.open("BACKING_STORE.bin", ios::binary);
	backing_store.seekg(0, backing_store.end);
	int length = backing_store.tellg();
	backing_store.read(buffer, length);
	cout << length;

	return 0;
}
