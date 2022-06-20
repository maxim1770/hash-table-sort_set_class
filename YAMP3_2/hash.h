#pragma once
#include "dlist.cpp"
#include <string>
#include <iostream>

template <class Data>
class hashTable {

	int size;
	DList<Data>* table;

	int hashFunc(Data obj);

public:
	hashTable() :size(10) {
		table = new DList<Data>[size];
	}
	hashTable(int N) :size(N) {
		table = new DList<Data>[size];
	}
	void add(Data obj);
	bool search(Data obj);
	void remove(Data obj);
	DList<Data> getElbyKey(int key);
	int getSize();
	void operator=(hashTable<Data> A);

	void print(std::ostream& out);
};