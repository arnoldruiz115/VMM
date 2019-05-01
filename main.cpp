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

/*
Read block of data from binary file.
Compare value from binary fine with correct.txt
int main () {

  std::ifstream is ("test.txt", std::ifstream::binary);
  if (is) {
    // get length of file:
    is.seekg (0, is.end);
    int length = is.tellg();
    is.seekg (0, is.beg);

    char * buffer = new char [length];

    std::cout << "Reading " << length << " characters... ";
    // read data as a block:
    is.read (buffer,length);

    if (is)
      std::cout << "all characters read successfully.";
    else
      std::cout << "error: only " << is.gcount() << " could be read";
    is.close();

    // ...buffer contains the entire file...

    delete[] buffer;
  }
  return 0;
}
*/
