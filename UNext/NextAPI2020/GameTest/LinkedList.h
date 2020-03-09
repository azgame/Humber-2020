#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "stdafx.h"

template <typename T>
class LinkedList
{
	struct Node
	{
		T value;
		Node *next, *prev;

		Node(const T& v)
		{
			value = v;
			next = prev = nullptr;
		}
	};

	Node *head, *tail;
	size_t size;

public:

	LinkedList() : head(nullptr), tail(nullptr), size(0) {}

	~LinkedList() { clear(); }

	void clear()
	{
		while (!empty())
			pop_front();
	}

	bool empty() const { return size == 0; }

	size_t getSize() const { return size; }

	T& front()
	{
		return head->value;
	}

	T& back()
	{
		return tail->value;
	}

	void push_front(const T& value)
	{
		Node* newNode = new Node(value);
		if (empty())
		{
			head = tail = newNode;
		}
		else
		{
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
		}

		size++;
	}

	void push_back(const T& value)
	{
		Node* newNode = new Node(value);

		if (empty())
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}

		size++;
	}

	void pop_front()
	{
		Node* oldHead = head;

		if (head == tail)
			head = tail = nullptr;
		else {
			head = head->next;
			head->prev = nullptr;
		}

		delete oldHead;
		--size;
	}

	void pop_back()
	{
		Node* oldTail = tail;

		if (head == tail) {
			head = tail = nullptr;
		}
		else {
			tail = tail->prev;
			tail->next = nullptr;
		}

		delete oldTail;

		--size;
	}

	class Iterator
	{
	protected:

		Node* node;

		friend class LinkedList;

		Iterator(Node* n) : node(n) {}

	public:

		Iterator() : node(nullptr) { }

		bool operator== (const Iterator& rhs) const
		{
			return node == rhs.node;
		}

		bool operator!= (const Iterator& rhs) const
		{
			return node != rhs.node;
		}

		T& operator* () const
		{
			return node->value;
		}

		Iterator& operator++()
		{
			node = node->next;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator temp = *this;
			node = node->next;
			return temp;
		}

		Iterator& operator--()
		{
			node = node->prev;
			return *this;
		}

		Iterator operator--(int)
		{
			Iterator temp = *this;
			node = node->prev;

			return temp;
		}
	};

	Iterator begin()
	{
		return head;
	}

	Iterator rbegin()
	{
		return tail;
	}

	Iterator end()
	{
		return nullptr;
	}

	Iterator rend()
	{
		return nullptr;
	}

	Iterator erase(Iterator pos)
	{
		Node* target = pos.node;

		++pos;  

		if (target == head)
			pop_front();
		else if (target == tail)
			pop_back();
		else {
			target->prev->next = target->next;
			target->next->prev = target->prev;

			delete target;
			--size;
		}

		return pos;
	}

	Iterator insert(Iterator pos, const T& value)
	{
		if (pos == begin()) {
			push_front(value);
			return head;
		}
		else if (pos == end()) {
			push_back(value);
			return tail;
		}
		else {
			Node* newNode = new Node(value);

			pos.node->prev->next = newNode;
			newNode->prev = pos.node->prev;
			pos.node->prev = newNode;
			newNode->next = pos.node;

			++size;

			return newNode;
		}
	}

	Iterator find(const T& value)
	{
		for (Node* node = head; node; node = node->next)
			if (node->value == value)
				return node;
		return end();
	}

};

#endif
