#ifndef Queue_Included

#define Queue_Included

#include "DoublyLinkedList.h"

using namespace std;

class genQueue {
	public: 
		genQueue();
		~genQueue();
		void insert (Student *data); //enqueue()
		Student* remove();//dequeue
		Student* peek();//front()
		int isEmpty();
		void printQueue();
		DoublyLinkedList* myList;
		unsigned int getSize();
};

#endif