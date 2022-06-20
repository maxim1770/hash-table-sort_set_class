#pragma once
#include "hash.h"

template<class Data>
inline int hashTable<Data>::hashFunc(Data obj)
{
	int temp = obj.hash() % size;
	return abs(temp);
}

template<class Data>
void hashTable<Data>::add(Data obj)
{
	if (!search(obj))
	{
		int place = hashFunc(obj);
		DList<Data>::template Iterator it_beg = table[place].begin();
		DList<Data>::template Iterator it_end = table[place].end();
		it_end++;
		while (it_beg != it_end && *it_beg > obj)
			it_beg++;
		table[place].addAfter(it_beg, obj);
	}
}

template<class Data>
bool hashTable<Data>::search(Data obj)
{
	int place = hashFunc(obj);
	DList<Data>::template Iterator it_end = table[place].end();
	it_end++;
	return table[place].search(obj) != it_end;
}

template<class Data>
void hashTable<Data>::remove(Data obj)
{
	int place = hashFunc(obj);
	if (!table[place].is_empty()) {
		table[place].remove(obj);
	}
}

template<class Data>
DList<Data> hashTable<Data>::getElbyKey(int key)
{
	if(key<size && key>=0) 
		return table[key];
}

template<class Data>
int hashTable<Data>::getSize()
{
	return size;
}

template<class Data>
void hashTable<Data>::operator=(hashTable<Data> A)
{
	size = A.size;
	table = A.table;


}

template<class Data>
void hashTable<Data>::print(std::ostream& out)
{
	for (int i = 0; i < size; i++) {
		if (!(table[i].is_empty())) {
			out << i << ": ";
			table[i].print(out);
			out << '\n';
		}
	}
}


