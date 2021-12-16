#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab3_new\Heap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab3tests
{
	TEST_CLASS(Lab3tests)
	{
	public:
		TEST_METHOD(contains_method)
		{
			heap heap;
			heap.insert(20);
			heap.insert(10);
			heap.insert(12);
			heap.insert(25);
			Assert::IsTrue(heap.contains(10) == true);
			Assert::IsTrue(heap.contains(1) == false);
		}
		TEST_METHOD(Insert_method)
		{
			heap heap;
			heap.insert(20);
			heap.insert(10);
			heap.insert(12);
			heap.insert(25);

			Iterator* bft_iterator = heap.create_bft_iterator();
			Assert::IsTrue(bft_iterator->next() == 25);
			int next_value = bft_iterator->next();
			Assert::IsTrue(next_value == 20 || next_value == 12);
			next_value = bft_iterator->next();
			Assert::IsTrue(next_value == 20 || next_value == 12);
			next_value = bft_iterator->next();
			Assert::IsTrue(next_value == 10);
		}
		TEST_METHOD(Remove_method)
		{
			heap heap;
			heap.insert(20);
			heap.insert(10);
			heap.insert(12);
			heap.insert(25);
			heap.insert(16);
			heap.remove(25);

			Iterator* bft_iterator = heap.create_bft_iterator();
			Assert::IsTrue(bft_iterator->next() == 20);
			int next_value = bft_iterator->next();
			Assert::IsTrue(next_value == 16 || next_value == 12);
			next_value = bft_iterator->next();
			Assert::IsTrue(next_value == 16 || next_value == 12);
			next_value = bft_iterator->next();
			Assert::IsTrue(next_value == 10);
		}

	};
}
