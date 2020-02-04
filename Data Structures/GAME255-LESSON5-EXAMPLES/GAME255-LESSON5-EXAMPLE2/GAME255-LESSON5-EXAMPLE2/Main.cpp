#include <iostream>
#include <ctime>

using namespace std;

#include "DList.h"

template <typename T>
void bubbleSort(DList<T> &list)
{
	// Iterators to track adjacent nodes
	DList<T>::Iterator iter1;
	DList<T>::Iterator iter2;

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

template <typename T>
bool linearSearch(DList<T> &list, T value)
{
	// Iterator to track current node, starting from the head of the list
	DList<T>::Iterator iter = list.begin();

	// Traverse nodes until value is found or all nodes were visited
	for (int i = 0; i < list.size(); ++i, ++iter)
	{
		// Return true if value was found
		if (*iter == value)
			return true;
	}

	// Return false if value was not found
	return false;
}

template <typename T>
bool binarySearch(DList<T> &list, T value)
{
	// Track first and last index 
	int low = 0;
	int high = list.size() - 1;

	// Set iterator to the first node in the list
	DList<T>::Iterator lowIter = list.begin();

	// Set iterator to the last node in the list
	DList<T>::Iterator highIter = list.rbegin();

	// Iterator will point to the middle node in the list
	DList<T>::Iterator midIter;
	
	// Loop when lower bound index is less than or equal to high bound index
	while (low <= high)
	{
		// Calculate middle index
		int mid = (low + high) / 2;
		
		// Set middle iterator to the first node in list
		midIter = list.begin();

		// Move middle iterator to middle of list
		for (int i = 0; i < mid; ++i, ++midIter)
		{

		}

		// If the value stored in the middle iterator is greater than the value being searched, update range to search the lower portion of list
		if (*midIter > value)
		{
			high = mid - 1;
			highIter = midIter;
			--highIter;
		}
		// If the value stored in the middle iterator is less than the value being searched, update range to search the upper portion of list
		else if (*midIter < value)
		{
			low = mid + 1;
			lowIter = midIter;
			++lowIter;
		}
		// Value was found
		else
			return true;
	}

	// Value was not found
	return false;
}

int main(void)
{
	int num, t1, t2;
	DList<int> list;
	DList<int>::Iterator iter;

	srand(time(NULL));

	// Populate list with random numbers between 1 - 100
	for(int i = 0; i < 10000; i++)
		list.push_front((rand() % 2000000) + 1);
	
	// Print list values
	for (iter = list.begin(); iter != list.end(); ++iter)
		cout << *iter << endl;
	cout << endl;
	
	// Sort list
	bubbleSort(list);

	cout << "Enter a number to search for in the list: ";
	cin >> num;

	t1 = clock();
	cout << num << (linearSearch(list, num) ? " was found in the list" : " was not found in the list.") << endl;
	t2 = clock();

	cout << "Linear searching took " << (t2 - t1) / (double)CLOCKS_PER_SEC << " seconds." << endl;

	t1 = clock();
	cout << num << (binarySearch(list, num) ? " was found in the list" : " was not found in the list.") << endl;
	t2 = clock();

	cout << "Binary searching took " << (t2 - t1) / (double)CLOCKS_PER_SEC << " seconds." << endl;

	system("pause");

	return 0;
}
