#include <iostream>
#include <ctime>

using namespace std;

#include "SList.h"

template <typename T>
void bubbleSort(SList<T> &list)
{
	SList<T>::Iterator iter1;
	SList<T>::Iterator iter2;

	T value;

	// Controls bubbling passes
	for (int i = list.size() - 1; i >= 0; --i)
	{
		// Set to first node
		iter1 = list.begin();

		// Set to second node
		iter2 = ++(list.begin());

		for (int j = 1; j <= i; ++j, ++iter1, ++iter2)
		{
			// Bubble greater values towards back of list
			if (*iter1 > *iter2)
			{
				value = *iter2;
				*iter2 = *iter1;
				*iter1 = value;
			}
		}
	}
}

int main(void)
{
	SList<int> list;
	SList<int>::Iterator iter;

	srand(time(NULL));

	// Populate list with random numbers between 1 - 100
	for(int i = 0; i < 10; i++)
		list.push_front((rand() % 100) + 1);
	
	// Print list values
	for (iter = list.begin(); iter != list.end(); ++iter)
		cout << *iter << endl;
	cout << endl;

	// Sort list
	bubbleSort(list);

	// Print list values
	for (iter = list.begin(); iter != list.end(); ++iter)
		cout << *iter << endl;
	cout << endl;

	system("pause");

	return 0;
}
