#pragma once
#include <iostream>
class stack {
private:
	class node {//node of the stack
	public:
		int info;
		node* prev;
		node(int info) { //constructor with the parameter
			this->info = info;
			prev = NULL;
		}
	};
	node* tail;
	int size;

public:
	stack() {// constructor
		tail = NULL;
		size = 0;
	}
	
	~stack() { // destructor
		while (!isEmpty())
			take_last();
	}
	
	void add(int info) { //adding an item to the end of the queue
		node* cur = tail;
		tail = new node(info);
		tail->prev = cur;
		size++;
	}
	
	int take_last() {//return the last item in the stack and delete them
		if (isEmpty())
			throw "The stack is empty";
		else {
			int last_info = tail->info;
			node* buff = tail->prev;
			delete tail;
			tail = buff;
			size--;
			return last_info;
		}
	}

	int get_size() { //return the stack size
		return size;
	}

	bool isEmpty() { //is the stack empty?
		if (size == 0) return true;
		else return false;
	}
};