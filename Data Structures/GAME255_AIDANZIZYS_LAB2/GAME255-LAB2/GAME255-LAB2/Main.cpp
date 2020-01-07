#include "CDList.h"

#include <iostream>
#include <string>

using namespace std;

template <typename T>
void CDList<T>::getJosephusPosition(int m)
{
	//Declare two pointers which point to two nodes and set them equal to head
	Node *n1 = new Node("");
	Node *n2 = new Node("");
	n1 = n2 = head;

	//Loop until there is only one node
	while (head->prev != head) 
	{
		//Declare a counter and set equal to 1
		int counter = 1;

		//Loop until counter equals m
		for (counter; counter < m; counter++)
		{
			//Set second pointer equal to first pointer and first pointer to the next node
			n2 = n1;
			n1 = n1->next;
		}

		//Declare a temp node pointer and set equal to first pointer
		//Node *temp = new Node("");
		CDList<T>::Iterator temp;
		temp = n1;
		n1 = n1->next;

		//Print value of node to be deleted
		cout << temp.node->value << " was killed." << endl;

		//Relink nodes and erase temp node
		erase(temp);
	}

	//Print value of last node
	cout << "Last person left standing is " << head->value << "." << endl;
}

int main()
{
	CDList<string> sentence;
	CDList<string>::Iterator word = sentence.begin();

	for (int i = 0; i < 8; i++)
	{
		sentence.push_back("Person " + to_string(i + 1));
	}

	sentence.getJosephusPosition(2);
}
