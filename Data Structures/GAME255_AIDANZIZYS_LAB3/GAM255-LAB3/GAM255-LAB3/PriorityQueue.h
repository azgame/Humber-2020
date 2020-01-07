#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "SList.h"

template <typename T>
class PriorityQueue
{
	// List containing data values
	SList<T> data;

	// List containing priority keys
	SList<int> key;

public:
	

	// Insert a data value sorted by priority 
	void push(const int priority, const T& value)
	{
		if(key.size() == 0)
		{
			// if priority queue is empty, insert new node to front of lists
			// INSERT CODE HERE
			key.push_front(priority);
			data.push_front(value);
		}
		else
		{
			// create an iterator for the data and key lists
			// INSERT CODE HERE
			typename SList<T>::Iterator dataIter;
			SList<int>::Iterator keyIter;

			
			// move to the beginning of the lists 
			// use the Iterator begin method to do this
			// INSERT CODE HERE
			dataIter = data.begin();
			keyIter = key.begin();


			// use iterators to loop until null and compare priorities to ensure items are inserted correctly in lists
			// INSERT CODE HERE
			if (priority < *keyIter) {
				data.insert(dataIter, value);
				key.insert(keyIter, priority);
			}
			else {
				while (dataIter != data.end() && keyIter != key.end() && *keyIter < priority)
				{
					dataIter++;
					keyIter++;
				}
				// insert data and key if null
				// INSERT CODE HERE
				data.insert(dataIter, value);
				key.insert(keyIter, priority);
			}
		}
	}

	// Remove first element from priority queue
	// Precondition: Priority queue not empty
	void pop()
	{
		// remove front items from lists
		// INSERT CODE HERE
		key.pop_front();
		data.pop_front();
	}

	// return reference to first value in priority queue
	// precondition: list is not empty
	T& peek()
	{
		// create an iterator and set to beginning of data list
		// use the Iterator begin method to do this
		// INSERT CODE HERE
		return *data.begin();
	}

	// check for empty priority queue
	bool empty() const
	{
		// INSERT CODE HERE
		return key.empty();
	}

	// return number of members
	size_t size() const
	{
		// INSERT CODE HERE
		return key.size();
	}

	// remove all nodes
	void clear()
	{
		// INSERT CODE HERE
		while (!key.empty()) {
			data.pop_back();
			key.pop_back();
		}
	}
};

#endif
