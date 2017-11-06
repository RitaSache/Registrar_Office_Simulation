#ifndef DoublyLinkedList_Included

#define DoublyLinkedList_Included

#include "ListNode.h"


class DoublyLinkedList {
	private:
		ListNode *front;
		ListNode *back;
		unsigned int size;
	public: 
		DoublyLinkedList();
		~DoublyLinkedList();
		void insertFront(Student *data);
		void insertBack(Student *data);
		Student* removeFront();
		Student* removeBack();
		void printList();
		Student* deletePos(int pos);
		bool isEmpty();
		unsigned int getSize();
		Student* showFrontNode();
};

#endif