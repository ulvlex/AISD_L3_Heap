#pragma once
#include <iostream>

class queue {
private:
	class node {//node of the queue
	public:
		int info;
		node* next;
		node(int info = 0) {//constructor with the parameter
			this->info = info;
			next = NULL;
		}
	};
	int size;
	node* head;
	node* tail;

public:
	queue() { //constructor
		tail = head = NULL;
		size = 0;
	}

	~queue() { //destructor
		while (size > 0) {
			take_top();
		}
	}
	
	void add(int info) {//adding an item
		if (size == 0)
			tail = head = new node(info);
		else
			tail = tail->next = new node(info);
		size++;
	}
	
	int take_top() {//return the first item in the queue and delet them
		if (isEmpty())
			throw "The queue is empty";
		else {
			int top_info = head->info;
			node* cur = head->next;
			delete head;
			head = cur;
			size--;
			return top_info;
		}
	}

	int get_size() { //return the queue size
		return size;
	}

	bool isEmpty() { //is the queue empty?
		return (size == 0);
	}
};