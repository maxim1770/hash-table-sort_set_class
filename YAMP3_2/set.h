#pragma once
#include "hash.cpp"
#include <vector>

template <class Data>
class Set
{
	hashTable<Data> table;

public:
	Set() {
		hashTable<Data> A(50);
		table = A;
	}
	
	Set(int N){
		hashTable<Data> A(N);
		table = A;
	}

	void add(Data obj);
	bool search(Data obj);
	void remove(Data obj);
	Set<Data> merge(Set A);	


	void print(std::ostream& out);

};


