#pragma once
#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Iterator.h"
using namespace std;

class heap {
private:
	int size; // heap size
	const int step_size = 100; //the step of changing the size of the array
	int* arr_heap;         // pointer to a heap array
	int heap_size; // real heap size

	void heapify(int index); //restoring a heap property

public:
	heap() {//constructor
		size = 100;
		arr_heap = new int[size];
		heap_size = 0;
	}

	//methods
	bool contains(int key); //search for an element in the tree by key
	void insert(int key); //adding an element to the tree by key
	void remove(int key); //deleting a tree element by key
	friend ostream& operator << (ostream& stream, const heap&); //output of the heap as an array
	void out_heap(); //output of the heap in the form of an approximate graph

	//Iterators
	class dft_iterator : public Iterator { //creating an iterator that implements one of the depth-first traversal methods(depth - first traverse)
	private:
		int* arr_heap;
		int heap_size;
		int index;
		int cnt_node;
		stack stack; //we implement depth traversal using a stack

	public:
		dft_iterator(int* arr_heap, int heap_size) { //constructor
			this->arr_heap = arr_heap;
			this->heap_size = heap_size;
			index = 0;
			cnt_node = 0;
		}

		int next() {//return next node of the graph
			if (!has_next())
				throw "The heap is empty";
			else {
				int buf_item;
				int left = 2 * index + 1;
				int right = 2 * index + 2;

				if (index < heap_size) {
					buf_item = arr_heap[index];
					if (right < heap_size)
						stack.add(right);
					index = left;
				}
				else {
					index = stack.take_last();
					buf_item = arr_heap[index];
				}
				cnt_node++;
				if (index > heap_size - 1 && has_next()) //reached the end
					index = stack.take_last();
				return buf_item;
			}
		};
		
		bool has_next() {
			if (cnt_node < heap_size) return true;
			else return false;
		}
	};

	Iterator* create_dft_iterator() {
		return new dft_iterator(this->arr_heap, heap_size);
	}

	class bft_iterator : public Iterator {//creating an iterator that implements breadth-first traversal methods(breadth - first traverse)
	private:
		int* arr_heap;
		int heap_size;
		int index;
		queue queue;

	public:
		bft_iterator(int* arr_heap, int heap_size) {//constructor
			this->arr_heap = arr_heap;
			this->heap_size = heap_size;
			index = 0;
			if (heap_size > 0)
				queue.add(this->arr_heap[index]);
		}

		int next() {//return next node of the graph
			if (!has_next())
				throw "The heap is empty";
			else {
				int left = 2 * index + 1;
				int right = 2 * index + 2;

				if (left < heap_size)
					queue.add(arr_heap[left]);
				if (right < heap_size)
					queue.add(arr_heap[right]);
				index++;
				return queue.take_top();
			}
		};

		bool has_next() {
			return !queue.isEmpty();
		};
	};

	Iterator* create_bft_iterator() {
		return new bft_iterator(this->arr_heap, heap_size);
	};
};

bool heap::contains(int key) { 
	int index = 0;
	bool check = false;
	while (index < heap_size) {
		if (arr_heap[index] == key) {
			check = true;
			break;
		}
		index++;
	}
	return check;
}

void heap::insert(int key) {
	int index; 
	int parent;

	if (heap_size >= size) {
		int* buff = arr_heap;
		size += step_size;
		arr_heap = new int[size];
		for (int i = 0; i < heap_size; i++)
			arr_heap[i] = buff[i];
		delete[] buff;
	}

	index = heap_size;
	arr_heap[index] = key;
	parent = (index - 1) / 2;
	while (parent >= 0 && index > 0) { //restoring a heap property
		if (arr_heap[index] > arr_heap[parent]) {
			swap(arr_heap[index], arr_heap[parent]);
		}
		index = parent;
		parent = (index - 1) / 2;
	}
	heap_size++; //node added
}

void heap::remove(int key) {
	int index = 0;
	if (contains(key) == false) throw "There is no such element in the heap";
	else {
		while (index < heap_size) {
			if (arr_heap[index] == key) {
				break;
			}
			index++;
		}
		swap(arr_heap[index], arr_heap[heap_size - 1]);
		arr_heap[heap_size - 1] = 0;
		heap_size--;
		heapify(index); //restoring a heap property
	}
}

void heap::heapify(int index) {
	int left, right;
	left = 2 * index + 1;
	right = 2 * index + 2;

	if (left < heap_size) {
		if (arr_heap[index] < arr_heap[left]) {
			swap(arr_heap[index], arr_heap[left]);
			heapify(left);
		}
	}

	if (right < heap_size) {
		if (arr_heap[index] < arr_heap[right]) {
			swap(arr_heap[index], arr_heap[right]);
			heapify(right);
		}
	}
}

// for output
ostream& operator << (ostream& stream, const heap& heap) 
{
	int index = 0;
	while (index < heap.heap_size) {
		stream << heap.arr_heap[index] << " ";
		index++;
	}
	cout << endl;
	return stream;
}

void heap::out_heap() {
	int index = 0;
	int buf_index = 1;
	while (index < heap_size) {
		while ((index < buf_index) && (index < heap_size)) {
			cout << arr_heap[index] << " ";
			index++;
		}
		cout << endl;
		buf_index = buf_index * 2 + 1;
	}
}