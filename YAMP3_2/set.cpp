#pragma once
#include "set.h"


template<class Data>
void Set<Data>::add(Data obj)
{
	table.add(obj);
}

template<class Data>
bool Set<Data>::search(Data obj)
{

	return table.search(obj);
}

template<class Data>
void Set<Data>::remove(Data obj)
{
	table.remove(obj);
}

template<class Data>
Set<Data> Set<Data>::merge(Set A)
{
	Set<Data> res;
	int N = table.getSize();
	for (int i = 0; i < N; i++)
	{
		DList<Data> ZaDonbass = table.getElbyKey(i);
		DList<Data>::template Iterator it_beg = ZaDonbass.begin();
		DList<Data>::template Iterator it_end = ZaDonbass.end();
		it_end++;
		while (it_beg != it_end)
		{
			if (A.search(*it_beg))
				res.add(*it_beg);
			it_beg++;
		}
	}
	return res;
}

template<class Data>
void Set<Data>::print(std::ostream& out)
{
	
	table.print(out);

}


