#include <iostream>
#include <fstream>
#include <string>
#include "MMU.hpp"
using namespace std;

MemoryManagementUnit::MemoryManagementUnit(){
	read();
}

void MemoryManagementUnit::read(){
	string line;
	int logical_address;
	cout << "Reading from text file." << endl;
	ifstream textFile("addresses.txt");
	while(getline(textFile, line)){
		logical_address = stoi(line);
		translateLogical(logical_address);
		cin.get();
	}
}

void MemoryManagementUnit::translateLogical(int address){
	cout << address;
}
