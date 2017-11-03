#include "DoublyLinkedList.h"
using namespace std;

class genQueue {
	public: 
		genQueue();
		~genQueue();
		void insert (int data); //enqueue()
		int remove(int key);//dequeue
		int peek();//front()
		int isEmpty();
		void printQueue();
		DoublyLinkedList* myList;
		unsigned int getSize();
};
