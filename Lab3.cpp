#include <iostream>
#include "heap.h"
#include "Iterator.h"

void traversal(heap heap) {
	Iterator* bft_iterator = heap.create_bft_iterator();
	cout << "width traversal: \n";
	while (bft_iterator->has_next())
		cout << bft_iterator->next() << ' ';
	cout << endl;

	Iterator* dft_iterator = heap.create_dft_iterator();
	cout << "deep traversal: \n";
	while (dft_iterator->has_next())
		cout << dft_iterator->next() << ' ';
	cout << endl;
}

int main()
{
	heap heap;
	cout << "Creating a binary heap with elements from 10 to 0" << endl;
	for (int i = 10; i >= 1; i--) {
		heap.insert(i);
	}
	cout << endl;

	cout << "Approximate view of the graph: " << endl;
	heap.out_heap();
	traversal(heap);
	cout << endl;

	cout << "Adding element 12" << endl;
	heap.insert(12);
	traversal(heap);
	cout << endl;
	
	cout << "Removing element 6" << endl;
	heap.remove(6);
	traversal(heap);
	cout << endl;

	cout << "Approximate view of the graph: " << endl;
	heap.out_heap();
}